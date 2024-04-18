CC = gcc

CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -fsanitize=address
LDFLAGS = -lm -fsanitize=address

TARGET = primes primes-i

prime_src = primes.c error.c eratosthenes.c
no-comment_src = no-comment.c error.c

all: primes primes-i no-comment

clean:
	rm -f $(TARGET) no-comment

# Using macros
primes:
	$(CC) $(CFLAGS) $(LDFLAGS) -o primes $(prime_src)

# Using inline functions
primes-i:
	$(CC) $(CFLAGS) $(LDFLAGS) -o primes-i $(prime_src) -DUSE_INLINE

run:
	ulimit -s 85000 && ./primes
	ulimit -s 85000 && ./primes-i

no-comment:
	$(CC) $(CFLAGS) $(LDFLAGS) -o no-comment $(no-comment_src)
