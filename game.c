#include "game.h"
//creates a new card based on the value and shape specified
struct card * newcard(int val, char* shape){
    struct card *a=  malloc(24);
    a->value= val;
    strcpy(a->shape, shape);
    a->next = NULL;
    return a;

}
//Adds the second card given to the end of the linked list and return the start
//If given start of linked list is NULL, just returns the new card
struct card * addAtEnd(struct card * beg, struct card * new){
    struct card * start = beg;
    //new->next = NULL;
    if(start == NULL || start->value == 0){
        return new;
    }
    while(start->next != NULL){
        start= start->next;
    };
    start->next = new;
    return beg;
}
char* structtostring(struct card * cards, char* buffer){
 
  sprintf(buffer, "%d %s", cards->value, cards->shape);
  return buffer;
}
void printdeck(struct card * beg){
    //struct car * beg = begg;
    while(beg!=NULL && beg->value != 0){
        printf("Value: %d Shape %s\n", beg->value, beg->shape); 
        beg = beg->next;
    }
}
char* name(int value){
    char *buff[13]={ "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    //                0      1        2       3       4      5        6        7       8      9       10       11      12
    //printf("%s\n",buff[value-1]);
    return buff[value-2];
    //return "hi";
    
    
}

void printcard(struct card* beg){
    printf("%s of %s\n", name(beg->value), beg->shape);
    //printf("hi\n");
}

void printnice(struct card * beg){
    if(beg==NULL || beg->value == 0){
        printf("Empty Deck\n"
        );
    }
    while(beg!=NULL){
        //printf("%d ", beg->value);
        printcard(beg);
        beg=beg->next;
    }
    
}

// Splits a deck in half and returns the removed-half
struct card* splitdeck3(struct card** deck){
    struct card* new = NULL;
    struct card* pholder = (*deck);
    deck = &((*deck)->next);
    while(*deck != NULL){
        new = addAtEnd(new, topcard(deck));
        if(*deck != NULL) deck = &((*deck)->next);
    }
    deck = &pholder;
    return new;
}
//not currently working, the original deck stays the same
struct card * splitdeck(struct card* original, struct card* newdeck){
    struct card * temp= original;
    while(temp->next != NULL){
       
       newdeck = addAtEnd(newdeck,topcard(&temp));
       
       
       
       temp =temp->next;
        if(temp==NULL){
        break;
       }
    }
    return newdeck;
}
struct card * splitdeck2(struct card* original, struct card* newdeck){
    struct card * temp= original;
    while(temp->next != NULL){
        temp =temp->next;
       
       
       
       
       newdeck = addAtEnd(newdeck,topcard(&temp));
       if(temp==NULL){
        break;
       }
    }
    return newdeck;
}
// Generates a full deck
struct card* genDeck(){
    char *buff[4] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    struct card* deck = NULL;
    
    for(int i = 0; i < 4; i++){
        for(int j = 2; j < 15; j++){
            struct card* new = newcard(j, buff[i]);
            deck = addAtEnd(deck, new);
        }
    }
    
    return deck;
}

// Shuffles a given deck
struct card* shuffleDeck(struct card* deck){
    struct card* s1 = NULL;
    struct card* s2 = NULL;
    //srand(time(NULL));

    for(int z = 0; z < 1000; z++){
        while(deck != NULL){
            if(rand()%2) s1 = addAtEnd(s1, topcard(&deck));
            else s2 = addAtEnd(s2, topcard(&deck));
        }

        while(s1 != NULL) deck = addAtEnd(deck, topcard(&s1));
        while(s2 != NULL) deck = addAtEnd(deck, topcard(&s2));
    }
    return deck;
}


// Removes the top card and returns it
struct card* topcard(struct card** deck){
    struct card* new = newcard((*deck)->value, (*deck)->shape);
    *deck = ((*deck)->next);
    return new;
}

// count cards
int deckSize(struct card* deck){
    int size = 0;
    while(deck != NULL && deck->value != 0){
        size++;
        deck = deck->next;
    }

    return size;}
    
struct card * removeindex(struct card ** deck, int index){
    struct card * prev=*deck;
    struct card * temp = *deck;
    if(index ==1){
        return topcard(deck);
    }

    for(int i =1;i<index;i++){
        prev = temp;
        temp=(temp)->next;
    }
    (prev)->next = (temp)->next;
    temp->next=NULL;
    return temp;

}
int war(struct card ** pile, struct card ** p1, struct card ** p2){
//continue function
        //printf("War\n");
        struct card * temp1=*p1;
        struct card * temp2=*p2;
        struct card* temp3=*pile;
        for(int i =0;i<3; i++){
        //printf("here1?\n");

            *pile =addAtEnd(*pile,topcard(p1));
            *pile =addAtEnd(*pile,topcard(p2));
        }
        struct card* prev;
        while(temp3->next!=NULL){
            //printf("here2?\n");
            prev = temp3;
            temp3 = temp3->next;
            
        }
        // printf("\n---------------\n");
        // printnice(*pile);
        // printf("\n---------------\n");
        // printnice(*p1);
        // printf("\n---------------\n");
        // printnice(*p2);
        if((prev->value) == (temp3->value)){
            war(pile, p1,p2);
        }
        else if((prev->value) > (temp3->value)){
            while(*pile!=NULL){
                addAtEnd(*p1,topcard(pile));
            }
        }
        else if((prev->value) < (temp3->value)){
            while(*pile!=NULL){
                addAtEnd(*p2,topcard(pile));
            }
        
        }
        //printf("here3?\n");
        return 1;
        
    
}
// Server plays the game and sends the content required to play to the client
int games(int clientd,struct card ** p1, int c1, struct card** p2, int c2){
    
    char buffer[100];
    struct card * pile=NULL;
    
    pile =addAtEnd(pile, removeindex(p1,c1));
    pile =addAtEnd(pile, removeindex(p2,c2));
    //printnice(pile);
    struct card * temp = pile;
    for(int i = 0; i <deckSize(pile);i++){
        
    write(clientd, structtostring(temp,buffer), 100);
   // printf("here2\n");
    temp = temp->next;
    //
    }
    

    
    if(pile->value > (pile->next)->value){
        while(pile!=NULL){
            addAtEnd(*p1,topcard(&pile));
            
         
        }
    }
    else if(pile->value < (pile->next)->value){
        
            //client won, send cards to end of client pile
        while(pile!=NULL){
            
            addAtEnd(*p2,topcard(&pile));
           
            
        }
    }
    else if(pile->value == (pile->next)->value){
        war( &pile,  p1,  p2);
        
        
        //technically could have infinite wars

    }
    return 1;
    //if(temp1->value>temp2->value);

}

int games2(int clientd, int client2, struct card ** p1, int c1, struct card** p2, int c2){
    
    char buffer[100];
    struct card * pile=NULL;
    
    pile =addAtEnd(pile, removeindex(p1,c1));
    pile =addAtEnd(pile, removeindex(p2,c2));
    //printnice(pile);
    struct card * temp = pile;
    for(int i = 0; i <deckSize(pile);i++){
        
    write(clientd, structtostring(temp,buffer), 100);
    write(client2, structtostring(temp,buffer), 100);
   // printf("here2\n");
    temp = temp->next;
    //
    }
    

    
    if(pile->value > (pile->next)->value){
        while(pile!=NULL){
            addAtEnd(*p1,topcard(&pile));
            
         
        }
    }
    else if(pile->value < (pile->next)->value){
        
            //client won, send cards to end of client pile
        while(pile!=NULL){
            
            addAtEnd(*p2,topcard(&pile));
           
            
        }
    }
    else if(pile->value == (pile->next)->value){
        war( &pile,  p1,  p2);
        
        
        //technically could have infinite wars

    }
    return 1;
    //if(temp1->value>temp2->value);

}

// Saves the game to a file named whatever the player name is, with
// the player deck being written to the file first.
void saveGame(char* player, struct card* pDeck, struct card* sDeck){
    char* saveName = malloc(sizeof(char)*100);
    strcat(saveName, "./");
    strcat(saveName, player);

    int saveFile = open(saveName, O_WRONLY | O_CREAT, 0644);

    int pSize = deckSize(pDeck);
    write(saveFile, &pSize, sizeof(int));
    int sSize = deckSize(sDeck);
    write(saveFile, &sSize, sizeof(int));

    while(pDeck != NULL) write(saveFile, topcard(&pDeck), sizeof(struct card));
    while(sDeck != NULL) write(saveFile, topcard(&sDeck), sizeof(struct card));
    // while(sDeck != NULL) {
    //     struct card* test = topcard(&sDeck);
    //     write(saveFile, test, sizeof(struct card));
    //     printcard(test);
    // }

    free(saveName);
    close(saveFile);
}

// Loads a game from a file with the same name as the player into
// decks
void loadGame(char* player, struct card** pDeck, struct card** sDeck){
    *pDeck = NULL;
    *sDeck = NULL;
    struct card* pTemp = NULL;
    struct card* sTemp = NULL;

    char* saveName = malloc(sizeof(char)*100);
    strcat(saveName, "./");
    strcat(saveName, player);

    int saveFile = open(saveName, O_RDONLY, 0);

    int pSize = 0;
    int sSize = 0;

    read(saveFile, &pSize, sizeof(int));
    read(saveFile, &sSize, sizeof(int));

    for(int i = 0; i < pSize; i++){
        struct card* new = malloc(sizeof(struct card));
        read(saveFile, new, sizeof(struct card));
        pTemp = addAtEnd(pTemp, new);
        if(i == 0) *pDeck = pTemp;
    }
    for(int i = 0; i < sSize; i++){
        struct card* new = malloc(sizeof(struct card));
        read(saveFile, new, sizeof(struct card));
        sTemp = addAtEnd(sTemp, new);
        if(i == 0) *sDeck = sTemp;
    }

    free(saveName);
    close(saveFile);
}



/*Functions:
Fill deck DONE
full move
Play card
check cards
Shuffle deck
*/