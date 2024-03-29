#include "networking.h"

#include "networking.h"

void err(int i, char*message){
  if(i < 0){
	  printf("Error: %s - %s\n",message, strerror(errno));
  	exit(1);
  }
}
/*Connect to the server
 *return the to_server socket descriptor
 *blocks until connection is made.*/

int client_tcp_handshake(char * server_address) {
  struct addrinfo * hints, * results;
hints = calloc(1,sizeof(struct addrinfo));
hints->ai_family = AF_INET;
hints->ai_socktype = SOCK_STREAM; //TCP socket
//hints->ai_flags = AI_PASSIVE; //only needed on server
//getaddrinfo(NULL, “80”, hints, &results);  //Server sets node to NULL
getaddrinfo(server_address, PORT, hints, &results); //"149.89.150.100"
  
//create socket
int sd = socket(AF_INET, SOCK_STREAM, 0);
  if(sd<0)
   {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
   }  

int status=connect(sd, results->ai_addr, results->ai_addrlen);
 if(status<0)
   {
        perror("Couldn't connect with the server");
        exit(EXIT_FAILURE);
   }    
//printf("%d\n",status);

  free(hints);
  freeaddrinfo(results);

  return sd;
}

/*Accept a connection from a client
 *return the to_client socket descriptor
 *blocks until connection is made.
 */
int server_tcp_handshake(int listen_socket){
    //char buffer[128];
    int client_socket;
socklen_t sock_size;
struct sockaddr_storage client_address;
sock_size = sizeof(client_address);

client_socket = accept(listen_socket,(struct sockaddr *)&client_address, &sock_size);
    if(client_socket<0){
        perror("Couldn't establish connection with client\n");
        exit(EXIT_FAILURE);}
    // read(client_socket, buffer, 128);
    // printf("%s\n",buffer);
    return client_socket;
}

/*Create and bind a socket.
* Place the socket in a listening state.
*/
int server_setup() {
  struct addrinfo * hints, * results;
hints = calloc(1,sizeof(struct addrinfo));
hints->ai_family = AF_INET;
hints->ai_socktype = SOCK_STREAM; //TCP socket
hints->ai_flags = AI_PASSIVE; //only needed on server
getaddrinfo(NULL, PORT, hints, &results);  //Server sets node to NULL
//client: getaddrinfo(“149.89.150.100”, “9845”, hints, &results);
  
//create socket
int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
int yes = 1;
  int sockOpt =  setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  err(sockOpt,"sockopt  error");
 int status = bind(sd, results->ai_addr, results->ai_addrlen);
 if(status<0){
        perror("Couldn't bind socket");
        exit(EXIT_FAILURE);
    }

  listen(sd, 10);
  free(hints);
  freeaddrinfo(results);

  return sd; //client file descriptor, return value of creating socket
}

