#include "terminal.h"

struct termios orig_termios;
struct termios new_termios;
struct termios old_termios;

void reset_terminal_mode(void)
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode(void)
{
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

int kbhit(void)
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv) > 0;
}

int getch(void)
{
    int r;
    unsigned char c;
    return (r = read(0, &c, sizeof(c))) < 0 ? r : c;
}