// eratoshtenes.c
// Řešení IJC-DU1, příklad a), 19.2.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include "eratosthenes.h"

void Eratosthenes(bitset_t arr) 
{
    bitset_fill(arr, 1);

    bitset_setbit(arr, 0, 0);
    bitset_setbit(arr, 1, 0);

    for (size_t i = 2; i < sqrt(bitset_size(arr)); i++) {
        if (bitset_getbit(arr, i)) {
            for (size_t j = i * i; j < bitset_size(arr); j += i) {
                bitset_setbit(arr, j, 0);
            }
        }
    }
}
