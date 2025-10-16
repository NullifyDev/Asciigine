#ifndef HEART
#define HEART

#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>

#include "renderer/layer/manager.h"
#include "utils/log.h"
#include "renderer/render.h"
#include "utils/util.h"
#include "utils/file.h"
#include "utils/args.h"
#include "input/manager.h"

#define MANAGERS 2

void  free_engine(void);
void *engine_exit(void *args[]);

void *moveup     (void *args[]);
void *movedown   (void *args[]);
void *moveleft   (void *args[]);
void *moveright  (void *args[]);

int start(LayerManager *lm, InputManager *im);

#endif
