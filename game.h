
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
#include <time.h>

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
struct card* shuffleDeck(struct card* deck);
struct card* topcard(struct card**deck);
void printnice(struct card * beg);
int deckSize(struct card * deck);
int games(int clientd, struct card ** p1, int c1, struct card** p2, int c2);
int games2(int clientd, int client2, struct card ** p1, int c1, struct card** p2, int c2);
int war(struct card ** pile, struct card ** p1, struct card ** p2);
struct card * removeindex(struct card ** deck, int index);
void saveGame(char* player, struct card* pDeck, struct card* sDeck);
struct card * splitdeck(struct card* original, struct card* newdeck);
void loadGame(char* player, struct card** pDeck, struct card** sDeck);
struct card * splitdeck2(struct card* original, struct card* newdeck);
struct card* splitdeck3(struct card** source);
char* structtostring(struct card * cards, char* buffer);
#endif
