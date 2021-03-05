#ifndef SEQ_DEFINED
#define SEQ_DEFINED

#define T Seq_T
typedef struct T *T;

// New empty sequence. Hint estimates size of seq
T Seq_new(int hint);   

// Frees the sequences memory
void Seq_free(T *seq); 

// Returns number of elements in the sequence
int Seq_length(T seq); 

// Seq_get Returns a pointer to the value at index i of the sequence
// Seq_put Places val in the sequence at index i and returns a previous value
void* Seq_get(T seq, int idx);            
void* Seq_put(T seq, int idx, void* val); 

// Seq_addhi places val at the end of the sequence
// Seq_addlo places val at the start of the sequence
// Both functions increment the length value, allocate 
// memory if necessary, and return the added value
void* Seq_addhi(T seq, void* val);
void* Seq_addlo(T seq, void* val);

// Seq_remhi removes the last element of the sequence
// Seq_remlo removes the first element of the sequence
// Both functions decrement the length value and return the removed value
void* Seq_remhi(T seq, void* val);
void* Seq_remlo(T seq, void* val);

#undef T
#endif