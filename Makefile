CC = gcc

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -lm

TARGET = bin/primes bin/primes-i

prime_src = src/main.c src/error.c src/eratosthenes.c

all: primes primes-i no-comment

clean:
	rm -f $(TARGET)

# Using macros
primes:
	$(CC) $(CFLAGS) -o bin/primes $(prime_src)

# Using inline functions
primes-i:
	$(CC) $(CFLAGS) -o bin/primes-i $(prime_src) -DUSE_INLINE

run:
	ulimit -s 85000 && ./bin/primes
	ulimit -s 85000 && ./bin/primes-i

no-comment:
	$(CC) $(CFLAGS) -o bin/no-comment src/no-comment.c
