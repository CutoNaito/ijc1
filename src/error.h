#ifndef __ERROR_H_
#define __ERROR_H_

/*
 *  Prints a warning message to stderr.
 *
 *  [IN] fmt - format string
 *  [IN] ... - arguments
 * */
void warning(const char *fmt, ...);

/*
 *  Prints an error message to stderr and exits the program.
 *
 *  [IN] fmt - format string
 *  [IN] ... - arguments
 * */
void error_exit(const char *fmt, ...);

#endif
