#ifndef UTIL
#define UTIL

#include <stdio.h>

#define CURSOR_TO(x, y) printf("\033[%d;%dH", (y), (x))

#endif
