
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
   struct card* deck1 = NULL;
    struct card* deck2 = NULL;
    
      deck1 = shuffleDeck(genDeck());
      deck2 = splitdeck3(&deck1);
      while(1){
   
   char buff[100];
      fgets(buff, sizeof(buff), stdin);
      games(1, &deck1, 1, &deck2, 1);
      // printf("\n---------------\n");
      // printf("Decksize: %d\n",deckSize(deck1));
      // printnice(deck1);
      // printf("\n---------------\n");
      // printf("Decksize: %d\n",deckSize(deck2));
      // printnice(deck2);
      // printf("\n---------------\n");

      }
}