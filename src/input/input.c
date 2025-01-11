#include "input.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

bool _reading_input = false;  // vars in global scope leading with an underscore are reserved by the standard

// TODO: lacking some error handling
InputManager *input_init(int tickrate, int input_count) {
  InputManager *im = malloc(sizeof *im);
  im->keylist = keylist_init(input_count);
  im->tickrate = tickrate;
  return im;
}

// TODO: lacking some error handling
KeyList *keylist_init(int keylist_capacity) {

  KeyList *kl = malloc(sizeof *kl);
  kl->capacity = keylist_capacity;
  kl->keys = malloc(sizeof *kl->keys * kl->capacity);
  kl->count = 0;

  return kl;
}

// TODO: lacking some error handling
Key *new_key(char c, void (*action)(void)) {
  Key *key = malloc(sizeof *key);
  key->key = c;
  key->action = action;
  return key;
}

void input_read(InputManager *im) {

  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  int k = -1;
  KeyList *kl = im->keylist;
  char c = getchar();

  while (++k < kl->count) {
    char key = kl->keys[k]->key;
    if (c == key) { kl->keys[k]->action(); }
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
void *_async_input_runner(void *arg) {
  InputManager *im = (InputManager *)arg;
  while (_reading_input) { input_read(im); }

  return NULL;
}

// TODO: lacking some error handling
pthread_t *input_startlistenner(InputManager *im) {
  pthread_t *thread = malloc(sizeof(pthread_t));
  _reading_input = true;
  pthread_create(thread, NULL, _async_input_runner, im);
  pthread_join(*thread, NULL);
  return thread;
}

void input_stoplistenner(pthread_t thread) {
  pthread_cancel(thread);
}

Key *keylist_add(KeyList *kl, Key *k) {
  kl->keys[kl->count] = k;
  // return kl->count++;
  return *(kl->keys + kl->count++);
}
