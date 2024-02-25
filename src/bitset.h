#ifndef __BITSET_H_
#define __BITSET_H_

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define bitset_create(arr_name, size) \
    /* sizeof(unsigned long) = 64 (on most architectures), CHAR_BIT = 8 (on most architectures) */ \
    unsigned long arr_name[size / (sizeof(unsigned long) * CHAR_BIT) + 1] = {0} \
    static_assert(size > 0, "Size must be greater than 0"); \
    arr_name[0] = size;

#define bitset_alloc(arr_name, size) \
    assert(size > 0); \
    unsigned long *arr_name = (unsigned long *)malloc(size + sizeof(unsigned long)); \
    if (arr_name == NULL) { \
        fprintf(stderr, "Chyba alokace paměti\n"); \
        exit(1); \
    } \
    arr_name[0] = size;
     
#define bitset_free(arr_name) \
    if (arr_name != NULL) { \
        free(arr_name); \
    }

#define bitset_size(arr_name) \
    arr_name[0]

#define bitset_setbit(arr_name, index, bool_value) \
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
    (arr_name[index / (sizeof(unsigned long) * CHAR_BIT) + 1] & (1UL << (index % (sizeof(unsigned long) * CHAR_BIT))) ? 1 : 0)


#endif
