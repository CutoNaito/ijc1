CC = gcc

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -lm

TARGET = bin/primes bin/primes-i

# Using macros
primes:
	$(CC) $(CFLAGS) -o bin/primes src/*.c

# Using inline functions
primes-i:
	$(CC) $(CFLAGS) -o bin/primes-i src/*.c -DUSE_INLINE

run:
	ulimit -s 85000 && ./bin/primes
	ulimit -s 85000 && ./bin/primes-i
