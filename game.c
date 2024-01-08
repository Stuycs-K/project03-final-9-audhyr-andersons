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
    char buff[13][10]={ "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    //printf("%s\n",buff[value-1]);
    //return buff[value-2];
    return "hi";
    
    
}
void printcard(struct card* beg){
    //printf("%s of %s\n", name(beg->value), beg->shape);
    printf("hi\n");
}

void printnice(struct card * beg){
    while(beg!=NULL){
        printcard(beg);
        beg=beg->next;
    }
}

/*Functions:
Generate empty deck
Fill deck
full move
Play card
check cards
Shuffle deck
*/

// void fillDeck(struct card* deck){
//     deck = newcard();
    
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 13; j++){
//             if(i+j != 0){
                
//             }
//         }
//     }
// }
