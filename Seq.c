#include "./Seq.h"
#include <stdio.h>
#include <stdlib.h>

#define T Seq_T

struct T {
    int length;
    int size;
    void **sequence;
};

T Seq_new(int hint){
    T seq = malloc(sizeof(T));
    seq->length = 0;
    seq->size = hint > 0 ? hint : 1;
    seq->sequence = (void**)calloc(seq->size, sizeof(void*));
    return seq;
}

void Seq_free(T *seq){
    //free(seq->sequence);
    free(seq);
}

int   Seq_length(T seq)          { return seq->length; }
void* Seq_get   (T seq, int idx) { return seq->sequence[idx]; }

void* Seq_put   (T seq, int idx, void* val) {
    // Return NULL if idx does not exist
    if ( idx > seq->length ) return NULL;

    // Store previous, place value, return previous
    void* previous = seq->sequence[idx];
    seq->sequence[idx] = val;
    return previous;
}

void* Seq_addhi(T seq, void* val){
    if ( seq->length == seq->size ) {
        seq->size++;
        seq->sequence = realloc(seq->sequence, (seq->size * sizeof(void*)));
    }
    
    seq->sequence[seq->length++] = val;
    return seq->sequence[seq->length-1];
}

void* Seq_addlo(T seq, void* val){
    if ( seq->length == seq->size ) {
        seq->size++;
        seq->sequence = realloc(seq->sequence, (seq->size * sizeof(void*)));
    }
    seq->length++;
    for(int i = seq->length; i > 0; --i){
        seq->sequence[i] = seq->sequence[i-1];
    }
    seq->sequence[0] = val;
    return seq->sequence[0];
}

void* Seq_remhi(T seq){
    seq->length--;
    void* removed = seq->sequence[seq->length];
    seq->sequence[seq->length] = NULL;
    return removed;
}

void* Seq_remlo(T seq){
    seq->length--;
    void* removed = seq->sequence[0];
    for(int i = 0; i < seq->length; i++){
        seq->sequence[i] = seq->sequence[i+1];
    }
    return removed;
}