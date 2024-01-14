#include "game.h"
#include "networking.h"
char* structtostring(struct card * cards, char* buffer){
 
  sprintf(buffer, "%d %s", cards->value, cards->shape);
  return buffer;
}
int playgame(int clientd, struct card ** serv, struct card ** clie){
  srand(time(NULL));
    printf("Starting client deck:\n");
    printnice(*clie);
    printf("---------\n");
    while((deckSize(*serv)!=0) || (deckSize(*clie)!=0) ){
      int choice;
      struct card* iterator = *clie;
      for(int i =0;i<3;i++){
        char buff[24];
        printf("card wrote: ");
        printcard(*clie);
        printf("------\n");
        write(clientd, structtostring(iterator, buff), 24);
        iterator = iterator->next;
      }
      read(clientd, &choice, sizeof(choice));
      //printf("HI1\n");
      games(serv, 1,clie, choice);
      printf("HI2\n");
      
    }

}

int main(int argc, char*argv[]){
  int listeningsocket = server_setup();

  while(1){
  int clientd = server_tcp_handshake(listeningsocket);
  int choice = 8;
  read(clientd, &choice, sizeof(int));
  printf("Client's Choice: %d\n", choice);
  struct card* deck =genDeck();
      struct card * deck2=NULL;
      struct card * deck3=NULL;
    if(choice ==1){}
      
      for(int i = 0; i < 15; i++){
        deck=shuffleDeck(deck);
      }
      deck2=splitdeck(deck, deck2);
    // }
      deck3=splitdeck2(deck,deck3);
//       printnice(deck);
//       printf("\n--------\n");
//       printnice(deck2);
// printf("\n--------\n");
//       printnice(deck3);
//       printf("\n--------\n");
    playgame(clientd,&deck2,&deck3);

  close(clientd);
  }
  return 0;
}