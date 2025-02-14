#ifndef UTIL
#define UTIL

#include <stdio.h>


#define CURSOR_TO(x, y) printf("\033[%d;%dH", (y+1), (x+1))


#define CLEAR() printf("\e[1;1H\e[2J")
#define LINEBUFF_OFF() setvbuf(stdin, NULL, _IONBF, 0);
#define LINEBUFF_ON()  setvbuf(stdin, NULL, _IOLBF, BUFSIZ);


#endif
