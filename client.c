#include "networking.h"
#include "game.h"
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
    // struct card * top;
    // read(serverd,top, 24);
    // struct card * temp;
    // //segfaulting here
    // read(serverd,temp, 24);
    // //top=addAtEnd(top, temp);
    // //printf("hi\n");
    // read(serverd,temp, 24);
    // //addAtEnd(top, temp);
    // //printnice(top);
    return  0;
}