
#include "game.h"
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

int main(){
   // struct card *origin= addAtEnd(NULL, newcard(10, "hearts")); 
   // origin = addAtEnd(origin, newcard(11, "hearts")); 
   // origin = addAtEnd(origin, newcard(12, "hearts")); 
   // origin = addAtEnd(origin, newcard(13, "hearts")); 
   // origin = addAtEnd(origin, newcard(14, "hearts")); 
   // origin = addAtEnd(origin, newcard(2, "spades")); 
   // origin = addAtEnd(origin, newcard(5, "clubs")); 
   struct card *origin = genDeck();
   printnice(origin);
   printf("--------\n");
   origin = shuffleDeck(origin);
   printf("---------\n");
   printnice(origin);
   printf("---------\n");
   // topcard(&origin);
   // printcard(origin);
   // printf("\n\n");
   // printf("%d,%s\n", origin->value,origin->shape);
   // printcard(origin);
   // printf("\n\n");
   //
}