#include "./Seq.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void testadd(){
    Seq_T sequence = Seq_new(1);
    printf("\n* STARTING ADD FUNCTION TEST *\n\n");

    // Build test array
    int *testArr = calloc(15, sizeof(int));
    for(int i = 0; i < 15; i++){
        testArr[i] = i;
    }

    // Add vals from test array to sequence
    for(int i = 6; i < 15; i++){
        void* val = testArr+i;
        Seq_addhi(sequence, val);
    }
    for(int i = 5; i >= 0; i--){
        void* val = testArr+i;
        Seq_addlo(sequence, val);
    }

    // Check values
    printf("*****\n");
    for(int i = 0; i < 15; i++){
        int* val = (int*)Seq_get(sequence, i);
        printf("%d == %d\n", i, *val);
        assert(testArr[i] == *val);
    }
    printf("*****\n\n");
    
    printf("* PASSED ADD FUNCTION TEST *\n\n");
}

void testrem(){
    Seq_T sequence = Seq_new(1);
    printf("\n* STARTING REM FUNCTION TEST *\n\n");

    // Build test array
    int *testArr = calloc(15, sizeof(int));
    for(int i = 0; i < 15; i++){
        testArr[i] = i;
    }

    // Add vals from test array to sequence
    for(int i = 0; i < 15; i++){
        void* val = testArr+i;
        Seq_addhi(sequence, val);
    }

    printf("Initial Seq Length = %d\n", Seq_length(sequence));
    int *before, *after;
    // Test remhi
    for(int i = 0; i < 5; i++){
        before = Seq_get(sequence, Seq_length(sequence)-1);
        Seq_remhi(sequence);
        after = Seq_get(sequence, Seq_length(sequence)-1);
        printf("Last Element Before = %d After = %d\n", *before, *after);
    }
    // Test remlo
    for(int i = 0; i < 5; i++){
        before = Seq_get(sequence, 0);
        Seq_remlo(sequence);
        after = Seq_get(sequence, 0);
        printf("First Element Before = %d After = %d\n", *before, *after);
    }
    printf("Final Seq Length = %d\n", Seq_length(sequence));

    printf("\n* PASSED REM FUNCTION TEST *\n\n");
}


int main(){
    testadd();
    testrem();

    printf("****** Passed All Tests ******\n\n");
    return 0;
}