#include "./Seq.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Seq_T sequence = Seq_new(1);
    int *testArr = calloc(15, sizeof(int));
    for(int i = 0; i < 15; i++){
        testArr[i] = i;
    }
    for(int i = 0; i < 15; i++){
        void* val = testArr+i;
        Seq_addhi(sequence, val);
    }
    for(int i = 0; i < 15; i++){
        int* val = (int*)Seq_get(sequence, i);
        printf("index: %d, val: %d\n", i, *val);
    }
    printf("Length = %d\n", Seq_length(sequence));
}