#include "manager.h"

bool _reading_input = false;
InputManager *input_init(int tickrate, int input_count)
{
	InputManager *im = calloc(1, sizeof(InputManager));
	im->keylist = keylist_init(input_count);
	im->tickrate = tickrate;
	return im;
}

KeyList *keylist_init(int keylist_capacity)
{

	KeyList *kl = calloc(1, sizeof(KeyList));
	kl->capacity = keylist_capacity;
	kl->keys = calloc(kl->capacity, sizeof(Key));
	kl->count = 0;

	return kl;
}

Key *key_new(char c, Action action, void **args)
{
	Key *key = calloc(1, sizeof(Key));
	key->key = c;
	key->action = action;
	key->args = args;
	return key;
}

void input_read(InputManager *im)
{
	// printf("input_read(InputManager *): hit!\n");
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	int i = -1;
	KeyList *kl = im->keylist;
	linebuff_off();
	char c = getch();

	// bool scanning = true;
	while (++i < kl->count) // && scanning)
	{
		Key *k = &kl->keys[i];
		// char key = kl->keys[k].key;
		if (c == k->key)
		{
			// layermgr_shiftlayer(lm, 1, 1, 0);
			// printf("pressed: %c | ", c);
			k->action(k->args);
			// scanning = false;
			break;
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void *_input_read(void *arg) {
	InputManager *im = (InputManager *)arg;

	while(im->thread) 
		input_read(im);

	return NULL;
}

void *input_start(Args *args)
{
	// Args *arg = args;
	InputManager *im = (InputManager *)args->ptrs[1];
	
	_input_alive_a = true;
	if (pthread_create(im->thread, NULL, _input_read, args) != 0) 
	{
        perror("Failed to create renderer thread \"renderer_pt\"\n");
        exit(EXIT_FAILURE);
    }

	return NULL;
}

Key *keylist_add(InputManager* im, Key *k)
{
	KeyList *kl = im->keylist;
	if (kl->count == kl->capacity)
		error("cannot add more keys - key list is full.");
	kl->keys[kl->count] = *k;
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

	return NULL;
}

KeyList *keylist_setup(int count, Key *keys)
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

// Key key_new()

void keys_add(InputManager *im, int count, Key *keys)
{
	unsigned int newcap = (count + im->keylist->count) < im->keylist->capacity ? count : im->keylist->capacity + count,
				 newcount = 0;

    Key *temp = calloc(newcap, sizeof(Key));
    if (!temp) return;

	int i = 0;
	KeyList *kl = im->keylist;
	while (i < (kl->count + count))
	{
		temp[i] = i < kl->count ? kl->keys[i] : keys[i];
		i++; newcount++;
	}

	free(kl->keys);
	kl->keys = temp;
	kl->count = newcount;
	kl->capacity = newcap;
}