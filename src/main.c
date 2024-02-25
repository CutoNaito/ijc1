#include "eratosthenes.h"

int main(void) 
{
    bitset_alloc(arr, 100);

    Eratosthenes(arr);

    for (size_t i = 0; i < bitset_size(arr); i++) {
        if (bitset_getbit(arr, i)) {
            printf("%lu\n", i);
        }
    }

    bitset_free(arr);

    return 0;
}
