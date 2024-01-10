#include "game.h"
#include "networking.h"
int gaming(){
int val=0;
    char buff [100];
    printf("Start a new game or resume old one:(1/2) "); 
  fgets(buff,sizeof(buff),stdin);
  //doesn't work, trying to take user input and either start a new game or resume old game based on what they type
  //printf("%ld\n",strlen(buff));
  if(strlen(buff)==2){
    if(buff[0]=='1'){
      struct card* deck =genDeck();
      struct card * deck2;
      printf("Newly generated deck\n");
      printnice(deck);
      printf("\n\n------\n");
      deck2=splitdeck(deck, deck2);
      printnice(deck);
      printf("\n\n------\n");
      printnice(deck2);
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