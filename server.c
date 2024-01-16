#include "game.h"
#include "networking.h"
// char* structtostring(struct card * cards, char* buffer){
 
//   sprintf(buffer, "%d %s", cards->value, cards->shape);
//   return buffer;
// }
int playgame(int clientd, struct card ** serv, struct card ** clie){
  
    
    while((deckSize(*serv)!=0) || (deckSize(*clie)!=0) ){
      int choice;
      char buff[100];
      struct card* iterator = *clie;
      int size = deckSize(*clie);
      write(clientd, &size, sizeof(int));
      for(int i =0;i<3;i++){
        
        char buff[24];
        
        write(clientd, structtostring(iterator, buff), 24);
        iterator = iterator->next;
      }
      read(clientd, &choice, sizeof(choice));
      if(choice ==11){
      read(clientd, buff, sizeof(buff));
      //printf("Buff: %s\n", buff);
      saveGame(buff, *clie, *serv);
      close(clientd);
      
    }
      games(clientd, serv, rand()%3+1,clie, choice);
      // printf("\n---------------\n");
      // printf("Decksize: %d\n",deckSize(*clie));
      // printnice(*clie);
      // printf("\n---------------\n");
      // printf("Decksize: %d\n",deckSize(*serv));
      // printnice(*serv);
      // printf("\n---------------\n");

      
    }
    
    close(clientd);

}

void playAgainstServer(int clientd){
  int choice = 8;
  
    read(clientd, &choice, sizeof(int));
    char buff[100];
    //printf("Client's Choice: %d\n", choice);
    struct card* deck1 = NULL;
    struct card* deck2 = NULL;
    if(choice ==1){
      deck1 = shuffleDeck(genDeck());
      deck2 = splitdeck3(&deck1);
    }
    if(choice ==2){
      read(clientd, buff, sizeof(buff));
      loadGame(buff, &deck2, &deck1);
    }
    playgame(clientd,&deck1,&deck2);
}

int main(int argc, char*argv[]){
  int listeningsocket = server_setup();
  srand(time(NULL));
  while(1){
    int clientd = server_tcp_handshake(listeningsocket);
    int multi = 8;
    read(clientd, &multi, sizeof(int));
    if(!multi){
      int sub = fork();
      if(!sub){
        playAgainstServer(clientd);
        return 0;
      }
      close(clientd);
      continue;
    }

    int multi2 = 0;
    int client2 = 0;
    while(!multi2){
      client2 = server_tcp_handshake(listeningsocket);
      read(client2, &multi2, sizeof(int));
      if(!multi2){
        int sub = fork();
        if(!sub){
          playAgainstServer(client2);
          return 0;
        }
        close(client2);
      }
    }

    printf("2 PLAYERS WANT TO FIGHT!\n");

    close(clientd);
  }
  return 0;
}