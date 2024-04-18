#ifndef __ERATOSTHENES_H_
#define __ERATOSTHENES_H_

#include <math.h>
#include "bitset.h"

/*
 *  Eratosthenes' sieve.
 *  Marks all non-prime numbers in the bitset.
 *
 *  [IN] pole - bitset
 * */
void Eratosthenes(bitset_t pole);

#endif
