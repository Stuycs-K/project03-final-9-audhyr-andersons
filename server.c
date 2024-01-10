#include "game.h"
#include "networking.h"

int main(int argc, char*argv[]){
int val=0;
    char buff [100];
    printf("Start a new game or resume old one:(1/2) "); 
  fgets(buff,sizeof(buff),stdin);
  //doesn't work, trying to take user input and either start a new game or resume old game based on what they type
//   if(isdigit(buff)){
//     sprintf(val, "%d", buff);
//   }
//   if(val ==1){
//     printf("HI, they're ready");
//   }
    
}