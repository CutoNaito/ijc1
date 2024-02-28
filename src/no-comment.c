#include <stdio.h>
#include "error.h"

int main(int argc, char **argv) 
{
    if (argc > 2)
        error_exit("Neplatny pocet argumentu.");

    FILE *fp;
    if (argc == 1)
        fp = stdin;

    if (argc == 2) {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
            error_exit("Soubor se nepodarilo otevrit.");
    }

    /* Finite-state machine */
    int state = 0;
    int c;

    while ((c = getc(fp)) != EOF) {
        switch (state) {
        case 0:
            if (c == '/') {
                state = 1;
            } else if (c == '"') {
                putchar(c);
                state = 6;
            } else if (c == '\'') {
                putchar(c);
                state = 8;
            } else {
                putchar(c);
            }

            break;

        case 1:
            if (c == '/') {
                state = 4;
            } else if (c == '*') {
                state = 2;
            } else {
                putchar('/');
                putchar(c);
                state = 0;
            }

            break;

        case 2:
            if (c == '*') {
                state = 3;
            }

            break;

        case 3:
            if (c == '/') {
                putchar(' ');
                state = 0;
            } else if (c != '*') {
                state = 2;
            }

            break;

        case 4:
            if (c == '/') {
                state = 5;
            }

            break;

        case 5:
            if (c != '/') {
                state = 4;
            }

            break;

        case 6:
            if (c == '\\') {
                putchar(c);
                state = 7;
            } else if (c == '"') {
                putchar(c);
                state = 0;
            } else {
                putchar(c);
            }

            break;

        case 7:
            putchar(c);
            state = 6;

            break;
        
        case 8:
            if (c == '\\') {
                putchar(c);
                state = 9;
            } else if (c == '\'') {
                putchar(c);
                state = 0;
            } else {
                putchar(c);
            }

            break;

        case 9:
            putchar(c);
            state = 8;

            break;

        default:
            error_exit("Nastala chyba ve stavu.");
        }
    }

    return 0;
}
