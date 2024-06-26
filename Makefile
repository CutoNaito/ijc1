CC = gcc

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -fsanitize=address
LDFLAGS = -lm -fsanitize=address

TARGET = bin/primes bin/primes-i

prime_src = src/primes.c src/error.c src/eratosthenes.c
no-comment_src = src/no-comment.c src/error.c

all: primes primes-i no-comment

clean:
	rm -f $(TARGET) bin/no-comment

# Using macros
primes:
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/primes $(prime_src)

# Using inline functions
primes-i:
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/primes-i $(prime_src) -DUSE_INLINE

run:
	ulimit -s 85000 && bin/primes
	ulimit -s 85000 && bin/primes-i

no-comment:
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/no-comment $(no-comment_src)
