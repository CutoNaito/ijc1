// error.c
// Řešení IJC-DU1, příklad a), 19.2.2024
// Autor: Matěj Šturma, FIT
// Přeloženo: gcc 13.2.1

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void warning(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    fprintf(stderr, "Warning: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);
}

void error_exit(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    fprintf(stderr, "Error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);
    exit(1);
}
