#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h> 
#include <netdb.h>

#ifndef GAME_H
#define GAME_H

#define BUFFER_SIZE 1024
struct card {int value; char shape[10]; struct card *next;};
struct player {char name[100]; int gameswon; char filename[1000]}

#endif