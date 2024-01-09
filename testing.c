
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
   srand(time(NULL));

   struct card *origin = genDeck();
   struct card *origin2 = genDeck();
   origin = shuffleDeck(origin);
   origin2 = shuffleDeck(origin2);

   printf("Origin:\n");
   printnice(origin);
   printf("------------\n\nOrigin 2:\n");
   printnice(origin2);
   
}