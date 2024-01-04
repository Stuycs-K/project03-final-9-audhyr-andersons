# Final Project Proposal

## Group Members:

Spencer Anderson, Riasat Audhy
       
# Intentions:

Make the cardgame war in C.
    
# Intended usage:

Players can connect to the server to play war against a computer. If we have time, we also plan to expand this to a server that can connect to and manage multiple games, potentially with things like leaderboard and game history information for players.
  
# Technical Details:

Use a socket to connect a host and a client who will play against each other(or maybe the host will connect two client if we have time)

We will write to a file when saving data and retrieve it when resuming a match played in the past.

If expand the game to host multiple players we will use forking to fork a subhost.

We will use signals like SIGQUIT to autosave and exit and other signals for things not for stdin.



The deck of cards will be a linked list of structs for each card
struct:
int value
char* shape

Struct to include player and game details:
char* name
int gameswon
char* filename




    
# Intended pacing:

By Monday the 8th we plan to have the basic logic of the game coded.
We also plan to have all of the features we will implement thought out and writen in psudo code.
card shuffling(send all the cards into 2 temporary decks and then merge the two: repeat many times)

Then we'd connect a client and a host that could play with each other.

Then implement saving

Then Signals

Then a forking game (Connecting many clients to subhosts)

Then Multiplayer (clients with each other or with subhosts)

Interface: so players can choose to save and whether to play against a host or another player.
Also a way to view games played and leaderboard.
