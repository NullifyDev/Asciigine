#ifndef KEYBOARD
#define KEYBOARD

#include <stdatomic.h>
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
// #include <conio.h>

#include "../utils/terminal.h"
#include "../utils/log.h"
#include "../utils/util.h"
#include "../utils/args.h"
#include "../renderer/layer/manager.h"

typedef void *(*Action)(void*[]);
typedef struct Key
{
	char key;
	Action action;
	void **args;
} Key;

typedef struct KeyList
{
	Key *keys;
	int capacity;
	int count;
} KeyList;

typedef struct InputManager
{
	KeyList *keylist;
	unsigned int tickrate;
	pthread_t *thread;
	void ** thread_ret;
} InputManager;

static bool _input_alive_a;

InputManager *input_init(int tickrate, int input_count);

void    *_input_read     (void *arg);
void    *input_start     (Args *args);
void     input_end       (pthread_t pthread);
void     input_read      (InputManager *im);
char    *input_getkeychar(void);

Key     *key_new         (char c, Action action, void **args);
KeyList *keylist_init    (int amount);
Key     *keylist_add     (InputManager* im, Key *k);
Key     *keylist_getkey  (KeyList *kl, char c);
KeyList *keylist_setup   (int count, Key *keys);

void keys_add(InputManager *im, int count, Key *keys);

#endif
