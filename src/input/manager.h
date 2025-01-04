#ifndef KEYBOARD
#define KEYBOARD

#include <stdbool.h>
#include <pthread.h>

typedef struct Key
{
	char key;
	void (*action)(void);
} Key;

typedef struct KeyList
{
	Key **keys;
	int capacity;
	int count;
} KeyList;

typedef struct InputManager
{
	KeyList *keylist;
	int tickrate;
} InputManager;

InputManager *input_init(int tickrate, int input_count);
KeyList *keylist_init(int amount);
Key *new_key(char c, void (*action)(void));

void input_read(InputManager *im);
// pthread_t *input_startlistenner(InputManager *kl);
// void input_stoplistenner(pthread_t thread);

Key *keylist_add(KeyList *kl, Key *k);
char *input_getkeychar();
#endif
