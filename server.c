#include "game.h"
#include "networking.h"
char* structtostring(struct card * cards, char* buffer){
 
  sprintf(buffer, "%d %s", cards->value, cards->shape);
  return buffer;
}
int playgame(int clientd, struct card * serv, struct card * clie){
  srand(time(NULL));
    while((deckSize(serv)!=0) || (deckSize(clie)!=0) ){
      int choice;
      read(clientd, &choice, sizeof(choice));
      games(serv, rand()%3+1,clie, choice);
      for(int i =0;i<3;i++){
        char buff[24];
        write(clientd, structtostring(clie, buff), 24);
        clie = clie->next;
      }
    }

}
int gaming(){
  int listeningsociket = server_setup();
  int clientd= server_tcp_handshake(listeningsociket);
int val=0;
    char buff [100];
  //add code to take input from client to either resume or start new game
  if(strlen(buff)==2){
    if(buff[0]=='1'){
      struct card* deck =genDeck();
      struct card * deck2;
      struct card * deck3;
      //printf("Newly generated deck\n");
      for(int i = 0; i < 15; i++){
        deck=shuffleDeck(deck);
      }
      //printnice(deck);
      //printf("\n\n------\n");
      deck2=splitdeck(&deck, &deck2);
  //printnice(deck);
      deck3=splitdeck2(deck,deck3);
       struct card* temp = deck3;
       for(int i =0; i< 3; i++){
        char buff[24];//="hi from server";
    //write(clientd, buff, 20);
    
        write(clientd, structtostring(temp, buff), 24);
        temp = temp->next;
       }
    }
    else if(buff[0]=='2'){
      printf("Add resuming code here\n");
    }
    else{printf("Hey! That wasn't an option, please pick type 1 for a new game or 2 to resume\n");
      gaming();}
  }
  else{
      printf("Hey! Your answer is too long, please just pick 1 or 2\n");
      gaming();
    }

}
int main(int argc, char*argv[]){
gaming();
//   if(isdigit(buff)){
//     sprintf(val, "%d", buff);
//   }
//   if(val ==1){
//     printf("HI, they're ready");
//   }
    
}