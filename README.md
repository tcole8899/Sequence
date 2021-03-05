# Sequence Data Structure Implementation
### - Structure
  struct T {
      int length;
      int size;
      void **sequence;
  };
  - length stores the number of elements contained in the sequence
  - size stores the number of elements that can be stored with the currently allocated memory
  - sequence stores and array of void* for polymorphism
### - Funtions
  - T Seq_new(int hint) 
    - Creates and returns a new empty sequence
    - Hint is used to allocate the memory for the expected size of the sequence
      - Hint does not restrict sequence memory
  - void Seq_free(T *seq)
    - Frees all sequence memory
  - int Seq_length(T seq)
    - Returns the total number of elements in the sequence
  - void* Seq_get(T seq, int idx) 
    - Returns a pointer to the value at index i of the sequence
  - void* Seq_put(T seq, int idx, void* val) 
    - Places val in the sequence at index i and returns a previous value
  - void* Seq_addhi(T seq, void* val)
    - Adds the val to the sequences tail, increments length, and returns the added value
  - void* Seq_addlo(T seq, void* val)
    - Adds the value to the sequences head, increments length, and returns the added value
  - void* Seq_remhi(T seq)
    - Removes the last element, decrements length, and returns the removed value
  - void* Seq_remlo(T seq)
    - Removes the first element, decrements length, and returns the removed value

