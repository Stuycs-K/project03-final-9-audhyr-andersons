
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
       printf("DeckSize: %d", deckSize(deck1));
    printnice(deck1);
   struct card * test = removeindex(&deck1, 2);
    printf("\n------\n");
    printf("DeckSize: %d", deckSize(deck1));
    printnice(deck1);

   printf("removed card test\n");
   printnice(test);


}