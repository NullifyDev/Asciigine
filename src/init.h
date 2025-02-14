#ifndef INIT
#define INIT

#include <stdio.h>
#include <stdbool.h>

#include "renderer/layer/manager.h"
#include "utils/log.h"
#include "renderer/render.h"
#include "utils/util.h"
#include "utils/file.h"
#include "input/manager.h"

// LayerManager *lm;

static bool _running;
static InputManager *im;
static LayerManager *lm;

static void free_engine();
static void engine_exit();

static void moveup   ();
static void movedown ();
static void moveleft ();
static void moveright();

static void init();

#endif
