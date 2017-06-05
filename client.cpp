#include <netinet/in.h>
#include <netdb.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <cerrno>
#include <iostream>
#include <arpa/inet.h>

//
// Created by anastasia on 05.06.17.
//
using namespace std;
int main(int argc, char *argv[]){
    struct sockaddr_in server;
    struct addrinfo addr;
    char host_buf[NI_MAXHOST];
    int sd = socket (AF_INET,SOCK_STREAM,0);
    if ( sd == -1) { cout << "Error creating a socket on client: " << strerror(errno) << endl;    }
    memset(&server, 0, sizeof( server ));

    server .sin_family = AF_INET;
    server .sin_port = htons(2233);

    if ( inet_aton(argv [1], &server.sin_addr) <= 0 ) {   }
    int res = connect(sd, (struct sockaddr*) &server, sizeof( server ));
    if (res == -1){
        close(sd);
        cout <<"Can't connect to a server: " << strerror(errno) << endl; }
    cout<<"connected to serever"<<endl;
    for (;;) {
        char buf [] = "Hello!";
        send(sd, buf, strlen (buf), 0 );
        printf("Sent: %s\n", buf);
        sleep(2);

    }
    return 0;


}

