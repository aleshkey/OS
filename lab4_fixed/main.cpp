#include <iostream>
#include "alloc.c"

#define NUMBER_OF_BYTES 100000

int main() {
    for(int i =0; i< 1000; i++){
        auto start = clock();
        has_initialized=0;
        int* x =  (int*) my_malloc(INT16_MAX*i);
        auto end = clock();
        printf("%d\n", end-start);
        my_free(x);
        has_initialized=1;
    }
}
