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

    server.sin_family = AF_INET;
    server.sin_port = htons(2233);

    if ( inet_aton(argv [1], &server.sin_addr) <= 0 ) {   }
    int res = connect(sd, (struct sockaddr*) &server, sizeof( server ));
    if (res == -1){
        close(sd);
        cout <<"Can't connect to a server: " << strerror(errno) << endl; }
    cout<<"connected to serever"<<endl;
    string comnd(argv[2]);
    comnd = comnd[1];

    if (!(strcmp("m", comnd.c_str()) == 0)) {

        send(sd, argv[2], strlen(argv[2]), 0);
        printf("Sent: %s\n", argv[2]);
        sleep(2);
    }



    if (strcmp("d", comnd.c_str()) == 0)
    {   char buffForMsg[10 + 1];
        bzero(buffForMsg, 11);
        recv(sd, &buffForMsg[0], 10, 0);
        buffForMsg[10] = '\0';
        string received(buffForMsg);
        cout << "Server: " << received << endl;
    } else if (strcmp("t", comnd.c_str()) == 0)
    {
        char buffForMsg[8 + 1];
        recv(sd, &buffForMsg[0], 8, 0);
        buffForMsg[80] = '\0';
        string received(buffForMsg);
        cout << "Server: " << received << endl;

    } else if (strcmp("h", comnd.c_str()) == 0) {
        char buffForMsg[30 + 1];
        recv(sd, &buffForMsg[0], 30, 0);
        buffForMsg[30] = '\0';
        string received(buffForMsg);
        cout << "Server: " << received << endl;
    }else if (strcmp("m", comnd.c_str()) == 0){
        int size_of_str = strlen(argv[4]);
        char b[size_of_str+100];
        bzero(b, size_of_str+100);
        b[0] = argv[2][0]; //-
        b[1] = argv[2][1];//m
        b[2]  = argv[3][0];//0
        b[3] = argv[3][1];//3

        for (int i=0; i<size_of_str; i++){
            b[4+i] = argv[4][i];
        }

        send(sd, b, size_of_str+100, 0);
        cout << "Sent " << b << "\n";
        sleep(2);
        char buf[ size_of_str+100];
        bzero(buf,  size_of_str+100);
        int cc = recv(sd, buf,  size_of_str+100, 0);
        cout << "Server: " << buf << "\n";
        close(sd);

    } else
    {
        char buffForMsg[30 + 1];
        recv(sd, &buffForMsg[0], 30, 0);
        buffForMsg[30] = '\0';
        string received(buffForMsg);
        cout << "Server: " << received << endl;

    }

    close(sd);



return 0;


}

