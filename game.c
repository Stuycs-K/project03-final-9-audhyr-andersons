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
        for(int j = 2; j < 14; j++){
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


/*Functions:
Fill deck DONE
full move
Play card
check cards
Shuffle deck
*/