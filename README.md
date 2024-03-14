# VUT FIT IJC course - First project

My solution of the IJC project #1 (2023/24)

## Assignment
See ASSIGNMENT for the full assignment (in Czech)

## Installation and usage
### Linux/BSD/MacOS:
```
make            /* compiles both inline and macro versions into /bin */
make primes     /* compiles only the macro version into /bin */
make primes-i   /* compiles only the inline version into /bin */

make run        /* runs both versions with extended ulimit (85000 KiB) */
```

### Windows:
not possible atm, i will totally change the CC to zig tho

## Performance
Comparing GNU's `time` with ctime's `clock()` on Intel Core i5-1235U:
```
GNU's time: 36.916s

clock(): 36.9s
```
