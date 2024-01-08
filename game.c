
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
    if(start == null){
        return new;
    }
    while(start->next != NULL){
        start= start->next;
    };
    start->next = new;
    return beg;
}

void printdeck(struct card * beg){
    while(beg!=NULL){
        printf("Value: %d Shape %s", beg->value, beg->shape);
        beg = beg->next;
    }
}
char* name(int value){
    char str[10];
    
    if(value <11){
        sprintf(str, "%d", value);
        return str;
    }
    switch(value){
    case 11:
    return "Jack";
    case 12:
    return "Queen";
    case 13:
    return "King";
    case 14:
    return "Ace";
    }
}
void printcard(struct card * beg){
    printf("%s of %s", name(beg->value), beg->shape);
}
