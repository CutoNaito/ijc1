#include <stdio.h>
#include "error.h"

int main(int argc, char **argv) 
{
    if (argc == 1 || argc > 2)
        error_exit("Neplatny pocet argumentu.");

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
        error_exit("Soubor se nepodarilo otevrit.");

    /* Finite-state machine */
    int state = 0;
    int c;

    while ((c = getc(fp)) != EOF) {
        switch (state) {
        case 0:
            if (c == '/') {
                state = 1;
            } else {
                putchar(c);
            }
        }
    }

    return 0;
}
