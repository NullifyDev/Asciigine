#ifndef UTIL
#define UTIL

#include <stdio.h>


#define CURSOR_TO(x, y) printf("\033[%d;%dH", (y+1), (x+1))

inline static void clear(void) { printf("\033[1;1H\033[2J"); }
inline static void linebuff_off(void) { setvbuf(stdin, NULL, _IONBF, 0); }
inline static void linebuff_on(void)  { setvbuf(stdin, NULL, _IOLBF, BUFSIZ); }

#endif
