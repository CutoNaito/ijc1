// primes.c
// Řešení IJC-DU1, příklad a), 19.2.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <time.h>
#include "bitset.h"
#include "eratosthenes.h"

int main(void) 
{
    clock_t start = clock();

    bitset_alloc(arr, 666000000);

    Eratosthenes(arr);

    for (size_t i = 0; i < bitset_size(arr); i++) {
        if (bitset_getbit(arr, i)) {
            printf("%lu\n", i);
        }
    }

    bitset_free(arr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}