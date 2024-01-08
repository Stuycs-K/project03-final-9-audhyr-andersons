
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
struct player {char name[100]; int gameswon; char filename[1000];};
struct card * addAtEnd(struct card * beg, struct card * new);
struct card * newcard(int val, char* shape);
void printdeck(struct card * beg);
char* name(int value);
void printcard(struct card * beg);
struct card* genDeck();
void printnice(struct card * beg);
#endif
