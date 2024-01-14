#include "game.h"
#include "networking.h"
// char* structtostring(struct card * cards, char* buffer){
 
//   sprintf(buffer, "%d %s", cards->value, cards->shape);
//   return buffer;
// }
int playgame(int clientd, struct card ** serv, struct card ** clie){
  
    
    while((deckSize(*serv)!=0) || (deckSize(*clie)!=0) ){
      int choice;
      struct card* iterator = *clie;
      for(int i =0;i<3;i++){
        char buff[24];
        
        write(clientd, structtostring(iterator, buff), 24);
        iterator = iterator->next;
      }
      read(clientd, &choice, sizeof(choice));
      games(clientd, serv, rand()%3+1,clie, choice);
      // printf("\n---------------\n");
      // printf("Decksize: %d\n",deckSize(*clie));
      // printnice(*clie);
      // printf("\n---------------\n");
      // printf("Decksize: %d\n",deckSize(*serv));
      // printnice(*serv);
      // printf("\n---------------\n");

      
    }

}

int main(int argc, char*argv[]){
  int listeningsocket = server_setup();
  srand(time(NULL));
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