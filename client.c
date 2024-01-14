#include "networking.h"
#include "game.h"
struct card * stringtostruct(char* string){
    int value;
    char shape[10];
    sscanf(string, "%d %s", &value, shape);
    return newcard(value, shape);

}
struct card *readcards(int serverd, struct card ** deck){
    struct card* temp = *deck;
    for(int i = 0; i<3; i++){
        char buff[24];
        read(serverd,buff, 24);
       
        
        *deck =addAtEnd(*deck, stringtostruct(buff));
        temp = *deck;
    }
    
    return temp;
}
int resOrNew(){
    
    
    char buff[100];
    printf("Would you like to start a new game (1) or resume old one (2)?");
    fgets(buff, sizeof(buff), stdin);
    if(strlen(buff) != 2){
        printf("%ld\n", strlen(buff));
        printf("Invalid Input!\n");
        return resOrNew();
    }

    int choice = 0;
    choice = buff[0] - 48;
    if(choice != 1 && choice != 2){
        printf("%d\n", choice);
        printf("Invalid Input!\n");
        return resOrNew();
    }

    return choice;
}
int selectcard(struct card * deck){
    printnice(deck); 
        char buff[100];
    printf("Please enter which card to pick(1-3): ");
    fgets(buff, sizeof(buff), stdin);
    int choice = 0;
    choice = buff[0] - 48;
    if(strlen(buff) != 2){
        printf("%ld\n", strlen(buff));
        printf("Invalid Input! Your choice is too long\n");
        selectcard(deck);}
    else if(choice != 1 && choice != 2 && choice !=3){
        printf("%ld\n", strlen(buff));
        printf("Invalid Input! Please pick 1, 2, or 3\n");
        selectcard(deck);}
    
    else return choice;
}
int main(int argc, char*argv[]){
    char *ipbuff = malloc(sizeof(char)*30);
    printf("Please enter ip of server: ");
    fgets(ipbuff, sizeof(char)*30, stdin);
    //strsep(&ipbuff, "\3");
    if(ipbuff[strlen(ipbuff)-1] == '\n') ipbuff[strlen(ipbuff)-1] = '\0';
    //printf("entered ip: |%s|", ipbuff);
    int serverd= client_tcp_handshake(ipbuff);
    printf("connected!\n");

    int c = resOrNew();
    write(serverd, &c, sizeof(int));
    struct card* deck;
    char buff[100];

    while(1){
        deck=NULL;
        deck =readcards(serverd,&deck );
         
        
        int choice =selectcard(deck);
        write(serverd, &choice, 4);
        // struct card * pile;
        // for(int i = 0; i <2;i++){

    
        // read(serverd, buff, 100);
        // addAtEnd(pile, stringtostruct(buff));
        // }
        //printnice(pile);
    
        
    
        //deck=NULL;
    }
    return 0;
    }
    