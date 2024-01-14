#include "game.h"
#include "networking.h"
char* structtostring(struct card * cards, char* buffer){
 
  sprintf(buffer, "%d %s", cards->value, cards->shape);
  return buffer;
}
int playgame(int clientd, struct card ** serv, struct card ** clie){
  srand(time(NULL));
    // printf("Starting client deck:\n");
    // printnice(*clie);
    // printf("---------\n");
    while((deckSize(*serv)!=0) || (deckSize(*clie)!=0) ){
      int choice;
      struct card* iterator = *clie;
      for(int i =0;i<3;i++){
        char buff[24];
        // printf("card wrote: ");
        // printcard(*clie);
        // printf("------\n");
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
    struct card* deck1 = NULL;
    struct card* deck2 = NULL;
    if(choice ==1){
      deck1 = shuffleDeck(genDeck());
      deck2 = splitdeck3(&deck1);
    }
    playgame(clientd,&deck1,&deck2);
    close(clientd);
  }
  return 0;
}