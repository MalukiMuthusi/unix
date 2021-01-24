#ifndef UNIX_SOCKETS_SERVER_CLIENT
#define UNIX_SOCKETS_SERVER_CLIENT

#include <sys/un.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define BACKLOG 5
#define BUF_SIZE 1024
#define SOCK_PATH_SERVER "/tmp/greatings"

#ifdef __GNUC__
#define NORETURN __attribute__((__noreturn__))
#else
#define NORETURN
#endif

#endif