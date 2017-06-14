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
    server.sin_port = htons(2233);//39
    int res = bind(sd, (struct sockaddr *) &server, sizeof(server));
    if (res == -1) {
        cout << "Error binding a socket to an address: " << strerror(errno) << endl;
    }

    listen(sd, 10);

    cout << "Server: waiting for connections..." << endl;
    while(1) {
        bzero(buf, 1024);
        buf[0] = 'E';
        addr_size = sizeof(server);
        int psd = accept(sd, 0, 0);

        if (psd == -1) {
            cout << "Connection failed" << endl;
        }
        cout << "Connection established " << endl;

        long e = read(psd, buf, 100);
        if (buf[0] != 'E')printf("accepted:  %s\n", buf);
        buf[e] = '0';
        buf[e+1] = 0;

        char buffer[100];
        bzero(buffer, 100);

        if (buf[0] == '-' && buf[1] == 'h' && buf[2] == '0') {
            strncpy(buffer, "Hello ;)", 100);
        }else if (buf[0] == '-' && buf[1] == 'd' && buf[2] == '0'){
            strncpy(buffer, getDate().c_str(), 100);


        }else if (buf[0] == '-' && buf[1] == 't' && buf[2] == '0') {
            strncpy(buffer, getTime().c_str(), 100);
        }else if (buf[0] == '-' && buf[1] == 'm'){

            string s(buf+2, buf+4);
            int size_s = atoi(s.c_str());
            if(size_s != 0){
                string resp(buf+4);
                strncpy(buffer, resp.c_str(), size_s+1);}
            else{
                strncpy(buffer, "You forget to enter size", 25);
            }


        }
        else{
            strncpy(buffer, "sorry, please try again", 100);
        }


        write(psd, buffer, strlen(buffer) + 1);


    }


    return 0;
}

