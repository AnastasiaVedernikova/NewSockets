//#include <iostream>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <cstdio>
//
//#include <iostream>
//#include <unistd.h>
//#include <string.h>
//#include <netdb.h>
//using namespace std;
//
//int main() {
//   // std::cout << "Hello, World!" << std::endl;
//    struct sockaddr_in server;
//    char buf[1024];
//    int sd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sd == -1) {
//        cout << "Error creating a socket on server: " << strerror(errno) << endl;
//    };
//    memset(&server, 0, sizeof(server));
//    server.sin_family = AF_INET;
//    server.sin_addr.s_addr = htonl(INADDR_ANY);
//    server.sin_port = htons(2233);
//    int res = bind( sd,(struct sockaddr*) &server, sizeof(server) );
//    if (res == -1) {
//        cout << "Error binding a socket to an address: " << strerror(errno) << endl;
//    }
//
//    if (listen(sd, 1)<0){
//        cout<<"error listening"<<endl;
//        exit(1);
//    };
//    cout << "Server: waiting for connections..." << endl;
//
//    int psd = accept(sd, 0, 0);
//    //new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size); //new socket on which connection will be established
//    if (psd == -1)
//    {
//        cout << "Connection failed" << endl;
//    }
//    cout << "Connection established on port " << endl;
//    close(sd);
//    for (;;) {
//        int cc = recv(psd, buf, sizeof(buf, 0), 0);
//        if (cc == 0) exit(EXIT_SUCCESS);
//        buf[cc] = '\0';
//        printf("message received: %s\n", buf);
//    }
//    return 0;
//}