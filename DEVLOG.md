# Dev Log:

## Spencer Anderson

### 2024-01-03 - Brief description
We brainstormed which game to create and what features we would add to the game to fufill all of the requirements. 
We decided to make the card game war in C and we thought about adding a save and resume feature to the game.
Then we asked Mr. K if he thought it would be enough for two people and that it was a reasonable

### 2024-01-04 - Brief description
In class we further discussed our proposal and added to our technical details and pacing.
We sorted out which data types we would use and decided that we would use two structs.

For homework I set up and created all the files I think we will need for our project.

### 2024-01-05 - Brief description
I started setting up game.h with structs and includes. Then I set up functions to create cards and to add cards to the end of a linked list.
I also updated the makefile to work a bit.
 
For hw I continued adding functions and make a file to test the functions in the game.c file
I made functions for printing the deck of cards and preparing for how they will be printed in game.
Finished setting up war code and testing it and finished game logic


### 2024-01-08 - Brief description
I made a function to remove a card in the middle of the deck.
I started on a function to actually play the game
I started making a function to recursively call and handle war in case it happens many times in a row.

### 2024-01-09 - Brief description
Added networking code and started on server logic for prompting user and making the game work.
For hw I continued working on networking code and adjusting it for war.
I added a splitdeck function, still not completely working(segfaulting)

### 2024-01-10 - Brief description
Fixed splitdeck function
Started sending data between client and server to make game work between terminals and computers

Worked on reading and writing structs between the server and the client

### 2024-01-11 - Brief description
Added functions to make the game work on the server side
Continued testing networking and cleaning up the client
Continued adding to server.c and client.c code for hw

### 2024-01-12 - Brief description
Debugged client.c and server.c to try and make the transfer of cards work
## Riasat Audhy

### 2024-01-03 - Brief description

We brainstormed which game to create and what features we would add to the game to fufill all of the requirements.
Then we asked Mr. K if he thought it would be enough for two people and that it was a reasonable scope for the project.
He said it was and then we started working on the Proposal.md.

### 2024-01-04 - Brief description
In class we further discussed our proposal and added to our technical details and pacing.
We sorted out which data types we would use and decided that we would use two structs.

### 2024-01-05 - Brief description
We discussed some of the structuring for how we'd make the game itself. I added a few includes, listed a few functions,
and started writing the function to fill an empty deck.

For hw I fixed a few typos and small errors. And then I finished the function to generate a deck and made a function to shuffle
the deck. Everything in game.c should be working. I also added on to the makefile a bit. 

### 2024-01-08 - Brief description
We planned out how to structure turns in the game. I added a function to count the number of cards in a deck, and started working on
a function to save the game.

### 2024-01-09 - Brief description
(spent a few hours before class) I worked on saveGame and loadGame. Save game seems to work fully, loadGame loads in the cards and successfully loads one of the decks, but has a bus error when I try loading the other one (with the exact same code). I also moved the random seed to main to improve shuffling. I also modified addAtEnd, printDeck, printNice, deckSize to handle malloc'd but still empty decks.

In class I spent the entire period working on loadGame, and now loadGame and saveGame both fully work.

### 2024-01-10 - Brief description
We collaboratively worked on debugging splitdeck() and planned out interface stuff a bit. I started working on client.c

### 2024-01-11 - Brief description
Made sure networking was fully working (tiny change). Started working on interaction between server and client. Client takes input for server ip,
connects to the server, and sends over a choice.

### 2024-01-12 - Brief description
New & improved implementation of split deck! Also fixed games, and correspondingly adjusted playgames (still has a few unrelated issues to debug). Also added a bit to makefile clean.

### 2024-01-14 - Brief description
I cleaned up some stuff in game-setup which fixed the issue with decks not being random. I also fixed the problem of seemingly random cards (deck was unintentionally being partially iterated through) being used in the game.

### 2024-01-15 - Brief description
I added forking for the server to take multiple clients and also made it so clients can choose to play with other clients or against the server. 
