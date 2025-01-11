#ifndef INIT
#define INIT

#include "renderer/layer/manager.h"

static LayerManager *lm;

void moveup(void);
void movedown(void);
void moveleft(void);
void moveright(void);

void init(void);

#endif
