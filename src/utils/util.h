#ifndef UTIL
#define UTIL

#include <stdio.h>
#include "fastprint.h"

#define CURSOR_TO(x, y) fp_print("\033[%d;%dH", (y), (x))

#endif
