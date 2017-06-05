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
    string m = argv[2];
    char mybuf[2];
    sprintf(mybuf, "%.4s", m.c_str());

   // while(1) {
        send(sd, mybuf, 1, 0);
        //cout << "bufsend: " << mybuf << endl;
       // cout << "sended " + std::string(argv[2]) << endl;
    //}

    string comnd(argv[2]);
    comnd = comnd[0];

    if (strcmp("d", comnd.c_str()) == 0)
    {   char buffForMsg[10 + 1];
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

    } else if (strcmp("h", comnd.c_str()) == 0)
    {
        char buffForMsg[30 + 1];
        recv(sd, &buffForMsg[0], 30, 0);
        buffForMsg[30] = '\0';
        string received(buffForMsg);
        cout << "Server: " << received << endl;

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

