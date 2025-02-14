#include "manager.h"

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
// #include <conio.h>

#include "../utils/terminal.h"
#include "../utils/log.h"
#include "../utils/util.h"

bool _reading_input = false;
InputManager *input_init(int tickrate, int input_count)
{
	InputManager *im = calloc(sizeof(InputManager), 1);
	im->keylist = keylist_init(input_count);
	im->tickrate = tickrate;
	return im;
}

KeyList *keylist_init(int keylist_capacity)
{

	KeyList *kl = calloc(sizeof(KeyList), 1);
	kl->capacity = keylist_capacity;
	kl->keys = malloc(sizeof(Key) * kl->capacity);
	kl->count = 0;

	return kl;
}

Key *new_key(char c, void (*action)(void))
{
	Key *key = calloc(sizeof(Key), 1);
	key->key = c;
	key->action = action;
	return key;
}

void input_read(InputManager *im, LayerManager *lm)
{
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	int k = -1;
	KeyList *kl = im->keylist;
	LINEBUFF_OFF();
	char c = getch();

	bool scanning = true;
	while (++k < kl->count)
	{
		char key = kl->keys[k].key;
		if (c == kl->keys[k].key)
		{
			// layermgr_shiftlayer(lm, 1, 1, 0);
			kl->keys[k].action();
			scanning = false;
			break;
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// void key_run(Key *k, void *arg) {
// 	(*k->action)(arg);
// }

// void *_async_input_runner(void *arg)
// {
// 	InputManager *im = (InputManager *)arg;
// 	while (_reading_input)
// 	{
// 		input_read(im);
// 	}
// }
// 
// pthread_t *input_startlistenner(InputManager *im)
// {
// 	pthread_t *thread = malloc(sizeof(pthread_t));
// 	_reading_input = true;
// 	pthread_create(thread, NULL, _async_input_runner, im);
// 	pthread_join(*thread, NULL);
// 	return thread;
// }
// 
// void input_stoplistenner(pthread_t thread)
// {
// 	pthread_cancel(thread);
// }

Key *keylist_add(InputManager* im, Key *k)
{
	KeyList *kl = im->keylist;
	if (kl->count == kl->capacity)
		error("cannot add more keys - key list is full.");
	kl->keys[kl->count] = *k;
	// return kl->count++;
	return kl->keys + kl->count++;
}

Key *keylist_getkey(KeyList *kl, char c)
{
	for (int i = 0; i < kl->count; i++)
	{
		Key *key = &kl->keys[i];
		if (key->key == c)
			return key;
	}
}

KeyList *keylist_setup(Key *keys, int count)
{
	if (count == 0) {
		warning("Key List is set to 0");
		return NULL;
	}

	KeyList *kl = keylist_init(count);
	kl->count = count;

	for (int i = 0; i < count; i++)
	{
		kl->keys[i] = keys[i];
	}

	return kl;
}
