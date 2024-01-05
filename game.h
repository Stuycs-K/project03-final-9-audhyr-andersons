#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/socket.h> 
#include <netdb.h>

#ifndef GAME_H
#define GAME_H

#define BUFFER_SIZE 1024

struct node* card(char n[], char Artist[], struct node *next){
    
    struct node *a=  malloc(208);
    strcpy(a->song, n);
    strcpy(a->artist, Artist);
    a->next = next;
    return a;

}
#endif