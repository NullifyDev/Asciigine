#include "manager.h"

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool _reading_input = false;
InputManager *input_init(int tickrate, int input_count)
{
	InputManager *im = malloc(sizeof(InputManager));
	im->keylist = keylist_init(input_count);
	im->tickrate = tickrate;
	return im;
}

KeyList *keylist_init(int keylist_capacity)
{

	KeyList *kl = malloc(sizeof(KeyList *));
	kl->capacity = keylist_capacity;
	kl->keys = malloc(kl->capacity);
	kl->count = 0;

	return kl;
}

Key *new_key(char c, void (*action)(void))
{
	Key *key = malloc(sizeof(Key));
	key->key = c;
	key->action = action;
	return key;
}

void input_read(InputManager *im)
{

    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	int k = -1;
	KeyList *kl = im->keylist;
	char c = getchar();

	while (++k < kl->count)
	{
		char key = kl->keys[k]->key;
		if (c == key)
		{
			kl->keys[k]->action();
		}
	}
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
void *_async_input_runner(void *arg)
{
	InputManager *im = (InputManager *)arg;
	while (_reading_input)
	{
		input_read(im);
	}
}

pthread_t *input_startlistenner(InputManager *im)
{
	pthread_t *thread = malloc(sizeof(pthread_t));
	_reading_input = true;
	pthread_create(thread, NULL, _async_input_runner, im);
	pthread_join(*thread, NULL);
	return thread;
}

void input_stoplistenner(pthread_t thread)
{
	pthread_cancel(thread);
}

Key *keylist_add(KeyList *kl, Key *k)
{
	kl->keys[kl->count] = k;
	// return kl->count++;
	return *(kl->keys + kl->count++);
}