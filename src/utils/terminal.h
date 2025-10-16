#ifndef TERMINAL
#define TERMINAL

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>


void reset_terminal_mode(void);
void set_conio_terminal_mode(void);
int kbhit(void);
int getch(void);

#endif
