#include "args.h"

Args *args_create(unsigned int count, void *pointers[]) 
{
    Args *args = calloc(1, sizeof(Args));
    void *ptrs = calloc(count, sizeof(void *));

    for (int i = 0; i < count; i++) 
    {
        ptrs = pointers[i];
    }

    args->count = count;
    args->ptrs = ptrs;

    return args;
}

void args_free(Args *args)
{
    for (int i = 0; i < args->count; i++) 
    {
        args->ptrs[i] = NULL;
    }

    args->count = 0;
    args->ptrs = NULL;

    free(args);
}
