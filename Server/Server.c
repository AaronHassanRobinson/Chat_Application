#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

#define PORTNUM 9002

int main(void)
{   

    printf("Configuring server listening on port: %d\n", PORTNUM);
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORTNUM);

    int Server_Listening_SocketFD = socket(AF_INET, SOCK_STREAM, 0);

    bind(Server_Listening_SocketFD, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(Server_Listening_SocketFD, SOMAXCONN); //max conns
    printf("Listening...\n");
    
    for(;;)
    {
        int connfd = accept(Server_Listening_SocketFD, (struct sockaddr*)NULL, NULL);
    }


    return 0;
}