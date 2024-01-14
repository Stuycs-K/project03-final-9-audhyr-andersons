#include "game.h"
#include "networking.h"
char* structtostring(struct card * cards, char* buffer){
 
  sprintf(buffer, "%d %s", cards->value, cards->shape);
  return buffer;
}
int playgame(int clientd, struct card ** serv, struct card ** clie){
  srand(time(NULL));
    while((deckSize(*serv)!=0) && (deckSize(*clie)!=0) ){
      int choice;
      struct card ** top = clie;
      for(int i =0;i<3;i++){
        char buff[24];
        write(clientd, *clie, 24);
        //printf("String to be sent%s\n",buff);
        *clie = (*clie)->next;
      }
      read(clientd, &choice, sizeof(choice));
      games(serv, 1,top, choice);

      
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
      deck3=splitdeck2(deck,deck3);
      playgame(clientd,&deck2,&deck3);
      close(clientd);
  }
  return 0;
}