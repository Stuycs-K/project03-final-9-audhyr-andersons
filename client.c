#include "networking.h"
#include "game.h"
int quit = 0;
int m = 0;
int serverd;
static void sighandler(int signo){
    if(signo == SIGINT){
        if(m) {
            printf("\nExiting game.\n");
            close(serverd);
            exit(0);
        }
        else {
            printf("\nSaving and quitting(press enter to confirm)\n");
            quit = 1;
        }
    }

}
struct card * stringtostruct(char* string){
    int value;
    char shape[15];
    sscanf(string, "%d %s", &value, shape);
    return newcard(value, shape);

}
struct card *readcards(int serverd, struct card ** deck){
    struct card* temp = *deck;
    for(int i = 0; i<3; i++){
        char buff[24];
        int check = read(serverd,buff, 24);
        if(check == 0){
            printf("Opponent disconnected. You win!\n");
            return NULL;
        }
       
        
        if(strcmp(buff, "88888888888888888888888") != 0)*deck =addAtEnd(*deck, stringtostruct(buff));
        temp = *deck;
    }
    
    return temp;
}
int resOrNew(){
    
    
    char buff[100];
    printf("Would you like to start a new game (1) or resume old one (2)? ");
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
int multiSelection(){
    char buff[100];
    printf("Would you like to play against the server (0) or another player? (1) ");
    fgets(buff, sizeof(buff), stdin);
    
    if(strlen(buff) != 2){
        printf("%ld\n", strlen(buff));
        printf("Invalid Input!\n");
        return multiSelection();
    }

    int choice = 5;
    choice = buff[0] - 48;
    if(choice != 0 && choice != 1){
        printf("%d\n", choice);
        printf("Invalid Input!\n");
        return multiSelection();
    }

    return choice;
}
int selectcard(struct card * deck){
    if(deckSize(deck) <= 3) printf("Cards in hand:\n");
    else printf("Top 3 cards in hand:\n");
    printnice(deck); 
        char buff[100];
    printf("Please enter which card to pick(1-3): ");
    
    fgets(buff, sizeof(buff), stdin);
    if(quit ==1){
        return 11;
    }
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
    signal(SIGINT, sighandler);
    char *ipbuff = malloc(sizeof(char)*30);
    printf("Please enter ip of server: ");
    fgets(ipbuff, sizeof(char)*30, stdin);

    if(ipbuff[strlen(ipbuff)-1] == '\n') ipbuff[strlen(ipbuff)-1] = '\0';
    int serverd= client_tcp_handshake(ipbuff);
    printf("Welcome to War!\n");

    m = multiSelection();
    write(serverd, &m, sizeof(int));

    int c = 999;
    if(!m){
        c = resOrNew();
        write(serverd, &c, sizeof(int));
    }


    struct card* deck;
    char buff[100];

    if(m) printf("Looking for opponent...\n");
    
    if(!m && c ==2){
            printf("Please enter which name the game is saved under: \n");
            fgets(buff, sizeof(buff), stdin);
            write(serverd, buff, sizeof(buff));
        }
    while(1){
        deck=NULL;
        int size=0;
        read(serverd, &size, sizeof(int));
        printf("Number of Cards in Deck: %d\n", size);
        if(size == 0){
            printf("Your deck is empty. You lose!\n");
            close(serverd);
            exit(0);
        }
        if(size == 52){
            printf("The opponent's deck is empty. You Win!\n");
            exit(0);
        }
        deck =readcards(serverd,&deck );
        if(deck == NULL) exit(0);
         
        
        int choice =selectcard(deck);
        if(m) printf("Waiting for opponent's move...\n");
        write(serverd, &choice, 4);
        
        if(choice ==11){
            printf("Please enter which name to be saved under: ");
            fgets(buff, sizeof(buff), stdin);
            write(serverd, buff, sizeof(buff));
            close(serverd);
            exit(0);
        }
        struct card * pile=NULL;
        for(int i = 0; i <2;i++){
            int check = read(serverd, buff, 100);
            if(check == 0){
                printf("Opponent disconnected. You win!\n");
                exit(0);
            }
            if(i == 0) printf("Pile:\n");
            printnice(newcard(stringtostruct(buff)->value, stringtostruct(buff)->shape));
            //addAtEnd(pile, stringtostruct(buff));
        }

        printf("------\n");
        //printnice(pile);
    
        
    
        //deck=NULL;
    }
    return 0;
    }
    