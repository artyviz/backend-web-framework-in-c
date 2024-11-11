#define _GNU_SOURCE
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<errno.h>
#include <time.h>

#include <fcntl.h>
#include <io.h>

#include "./birchutils.h"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $c (char *)
#define $8 (int8 *)
#define $6 (int16 *)
#define $2 (int32)
#define $4 (int64)
#define $i (int)

#define log(x)  syslogger(LOG_INFO, x)
#define logwarning(x) syslogger(LOG_WARN, x)
#define logger(x)

int16 x;
int8* p;

void syslogger(int priority, const char* str) {
    FILE* log_file = fopen("log.txt", "a");
    if (!log_file) return;

    time_t now = time(NULL);
    fprintf(log_file, "[%ld] Priority: %d, Message: %s\n", now, priority, str);
    fclose(log_file);
}

int32 setupserver(int8*, int16);

int main(int, char**);