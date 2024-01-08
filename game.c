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
    if(start == NULL){
        return new;
    }
    while(start->next != NULL){
        start= start->next;
    };
    start->next = new;
    return beg;
}

void printdeck(struct card * beg){
    //struct car * beg = begg;
    while(beg!=NULL){
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
    while(beg!=NULL){
        //printf("%d ", beg->value);
        printcard(beg);
        beg=beg->next;
    }
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
    srand(time(NULL));

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

struct card * removeindex(struct card * deck, int index){
    struct card * prev;
    for(int i =1;i<index;i++){
        prev = deck;
        deck=deck->next;
    }
    prev->next = deck->next;
    deck->next=NULL;
    return deck;

}
struct card * war(struct card * pile, struct card * p1, struct card * p2){
//continue function
    temp1=p1;
        temp2=p2;
        for(int i =0;i<2; i++){
            addAtEnd(pile,topcard(p1));
            addAtEnd(pile,topcard(p2));
            
            
        }
}
// Server plays the game and sends the content required to play to the client
struct card* game(struct card * p1, int c1, struct card* p2, int c2){
    struct card * temp1=p1;
    if(c1 >1){
        for(int num =1; num < c1; num++ ){
            temp1=temp1->next;
        }
    }
    struct card * temp2=p2;
    if(c2 >1){
        for(int num =1; num < c2; num++ ){
            temp2=temp2->next;
        }
    }
    struct card * pile;
    addAtEnd(pile, removeindex(p1,c1));
    addAtEnd(pile, removeindex(p2,c2));
    if(pile->value > pile->next->value){
        while(pile!=NULL){
            addAtEnd(p1,pile);
            pile=pile->next;
        }
    }
    if(pile->value < pile->next->value){
        while(pile!=NULL){
            addAtEnd(p2,pile);
            pile=pile->next;
        }
    }
    if(pile->value == pile->next->value){
        war(struct card* pile, struct card *p1, struct card * p2)
        
        //technically could have infinite wars

    }
    //if(temp1->value>temp2->value);

}


/*Functions:
Fill deck DONE
full move
Play card
check cards
Shuffle deck
*/