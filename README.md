[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/SQs7pKlr)
# PROJECT NAME HERE
War!(The Card Game)
### GROUP NAME HERE

Spencer Anderson
Riasat Audhy
       
### Project Description:

It is the card game war in C where a client connects to a host and plays war against the server or other players that connect.
  
### Instructions:

The server runs the game by running the command make server

The clients run it by running make client

Exit with ctrl+c

##FEATURES:
Play war against server or other clients over sockets

Save game to file and resume game

Use Signals to quit and save game

All files and data stored on server.

Server can play against many clients at once
### ISSUES:

There is an issue where if one player disconnects, the other will sometimes be told they lost (because of empty hand) instead of winning
by default. This is present in the final version, but uncommon enough that we couldn't figure out what causes it, which is why we couldn't fix it.

After saving the game a bunch of extra files are created. Each file name has a value and a card name. This clogs up the directory containing the game,
but does not affect gameplay in any way.
