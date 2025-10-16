#ifndef ARGS
#define ARGS

#include <stdlib.h>

typedef struct Args {
    unsigned int count;
    void **ptrs;
} Args;

Args *args_create(unsigned int count, void *pointers[]);
void args_free(Args *args);

#endif