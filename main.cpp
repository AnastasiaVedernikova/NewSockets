

#include <ctime>
#include <iostream>
#include <sys/socket.h>


using namespace std;

string getDate() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    string times = std::to_string(now->tm_year + 1900) + '-'+ std::to_string(now->tm_mon + 1) + '-' + std::to_string(now->tm_mday);
    return times;
}

string getTime() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    string dates = std::to_string(now->tm_hour) + '-'+ std::to_string(now->tm_min) + '-' + std::to_string(now->tm_sec);
    return dates;
}


