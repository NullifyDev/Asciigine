#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define HIDE_CURSOR() printf("\033[?25l");
#define SHOW_CURSOR() printf("\033[?25h");

typedef enum LogLevel 
{
    LOGLEVEL_PRINT,
    LOGLEVEL_ERROR,
    LOGLEVEL_WARNING,
    LOGLEVEL_DEBUG,
    LOGLEVEL_LOG,
    LOGLEVEL_VERBOSE
} LogLevel;

static LogLevel maxLogLevel;
void logger(LogLevel level, const char *msg);

const char *format(const char *msg, ...);

void error(const char *msg);
void warning(const char *msg);
void debug(const char *msg);
void _log(const char *msg);
void verbose(const char *msg);

#endif