#pragma once

#include <stdio.h>

#define LOG_LEVEL_PRINT 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_DEBUG 3
#define LOG_LEVEL_LOG 4
#define LOG_LEVEL_VERBOSE 5

#define HIDE_CURSOR() printf("\033[?25l");
#define SHOW_CURSOR() printf("\033[?25h");

extern int maxLogLevel;
void logger(int level, const char *msg);

const char *format(const char *msg, ...);

void error(const char *msg);
void warning(const char *msg);
void debug(const char *msg);
void logger_log(const char *msg);
void verbose(const char *msg);
