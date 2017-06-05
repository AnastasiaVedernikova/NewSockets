#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdio>

#include <iostream>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include "main.cpp"
using namespace std;

int main() {

    struct sockaddr_in server;
    socklen_t addr_size;
    char buf[1024];
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        cout << "Error creating a socket on server: " << strerror(errno) << endl;
    };
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(2233);
    int res = bind(sd, (struct sockaddr *) &server, sizeof(server));
    if (res == -1) {
        cout << "Error binding a socket to an address: " << strerror(errno) << endl;
    }

    listen(sd, 1);

    cout << "Server: waiting for connections..." << endl;
    while(1) {
        addr_size = sizeof(server);
        int psd = accept(sd, 0, 0);

        //int psd = accept(sd, (struct sockaddr *) &server, &addr_size);

        if (psd == -1) {
            //cout << "Connection failed" << endl;
        }
        //cout << "Connection established on port " << endl;
        char buffer[1];
        close(sd);

        if (!fork()) {
            int num = recv(psd, buffer, 1, 0);


            buffer[num] = '\0';
            //std::string my (buffer);
           // cout << "recevied: "<< buffer << endl;//-------------------------------------------------------------------
            switch (buffer[0]) {
                case 'd': {

                    if (send(psd, getDate().c_str(), 10, 0) == -1) {
                        cout << "Error" << endl;
                    }
                    break;
                }
                case 't': {
                    if (send(psd, getTime().c_str(), 8, 0) == -1) {
                        cout << "Error" << endl;
                    }
                    break;
                }
                case 'h': {
                    if (send(psd, "Hello, I an server!", 30, 0) == -1) {
                        cout << "Error" << endl;
                    }
                    break;
                }
                default:
                    if (send(psd, "Try again!", 33, 0) == -1) {
                        cout << "Error" << endl;
                    }
            }
            close(psd);
            exit(0);
        }
        close(psd);

    }


    return 0;
}

