#ifndef __BITSET_H_
#define __BITSET_H_

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define bitset_create(arr_name, size) \
    /* sizeof(unsigned long) = 64 (on most architectures), CHAR_BIT = 8 (on most architectures) */ \
    static_assert(size > 0, "Size must be greater than 0"); \
    unsigned long arr_name[size / (sizeof(unsigned long) * CHAR_BIT) + 1] = {0} \
    arr_name[0] = size;

#define bitset_alloc(arr_name, size) \
    static_assert(size > 0, "Size must be greater than 0"); \
    unsigned long *arr_name = (unsigned long *)malloc(size + sizeof(unsigned long)); \
    if (arr_name == NULL) { \
        error_exit("bitset_alloc: Chyba alokace pameti"); \
    } \
    arr_name[0] = size;
     
#define bitset_free(arr_name) \
    if (arr_name != NULL) { \
        free(arr_name); \
    }

#ifdef USE_INLINE

static inline unsigned long bitset_size(unsigned long *arr_name)
{
    return arr_name[0];
}

static inline void bitset_setbit(bitset_t arr_name, bitset_index_t index, int bool_value) {
    if (index >= bitset_size(arr_name)) {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", index, bitset_size(arr_name) - 1);
    }

    if (bool_value) {
        arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] |= 1UL << (index % (sizeof(unsigned long) * 8));
    } else {
        arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] &= ~(1UL << (index % (sizeof(unsigned long) * 8)));
    }
}

static inline void bitset_fill(bitset_t arr_name, int bool_value) {
    for (unsigned long i = 0; i < bitset_size(arr_name); i++) {
        bitset_setbit(arr_name, i, bool_value);
    }
}

static inline int bitset_getbit(bitset_t arr_name, bitset_index_t index) {
    if (index > bitset_size(arr_name)) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", index, bitset_size(arr_name) - 1);
    }

    return arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] & (1UL << (index % (sizeof(unsigned long) * CHAR_BIT))) ? 1 : 0;
}

#else

#define bitset_size(arr_name) \
    arr_name[0]

#define bitset_setbit(arr_name, index, bool_value) \
    if (index >= bitset_size(arr_name)) { \
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", index, bitset_size(arr_name) - 1); \
    } \
    if (bool_value) { \
        arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] |= 1UL << (index % (sizeof(unsigned long) * 8)); \
    } else { \
        arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] &= ~(1UL << (index % (sizeof(unsigned long) * 8))); \
    }

#define bitset_fill(arr_name, bool_value) \
    for (unsigned long i = 0; i < bitset_size(arr_name); i++) { \
        bitset_setbit(arr_name, i, bool_value); \
    }

#define bitset_getbit(arr_name, index) \
    (((index) > bitset_size(arr_name)) ? \
        (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", index, bitset_size(arr_name) - 1), 0) : \
        (arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] & (1UL << (index % (sizeof(unsigned long) * CHAR_BIT))) ? 1 : 0) \
    )

#endif
#endif
