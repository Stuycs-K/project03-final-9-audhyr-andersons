
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

   struct card *origin;
   struct card *origin2;
   // origin = genDeck();
   // origin2 = genDeck();
   // origin = shuffleDeck(origin);
   // origin2 = shuffleDeck(origin2);
   //printf("%d\n", deckSize(origin));
   //if(origin->shape == NULL) printf("yay\n");
   loadGame("player", &origin, &origin2);
   //printnice(origin);

   // printf("Origin: %d\n", deckSize(origin));
   // printdeck(origin);
   // printf("------------\n\nOrigin 2: %d\n", deckSize(origin2));
   // printnice(origin2);

   //saveGame("player", origin, origin2);
}