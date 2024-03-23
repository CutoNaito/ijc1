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

    int primes[10];
    int count = 0;

    for (size_t i = bitset_size(arr); i > 0; i--) {
        if (bitset_getbit(arr, i)) {
            primes[count] = i;
            count++;

            if (count == 10) {
                break;
            }
        }
    }

    for (int i = 9; i >= 0; i--) {
        printf("%d\n", primes[i]);
    }


    bitset_free(arr);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
