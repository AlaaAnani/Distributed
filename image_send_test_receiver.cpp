#include "UDPSocket.h"

#include <iostream>
#include <string>
#include<fstream>
using namespace std;

int main(int argc, char ** argv)
{
    char * myIP= argv[1]; 
    char * destIP = argv[2];
    unsigned int myPort = stoi(argv[3]);
    unsigned int destPort = stoi(argv[4]);

    bool stop = false;
    string input;

    UDPSocket sockobj;
    struct sockaddr_in peerAddr;

    bool meh = sockobj.initializeSocket(myPort);
    cout << "MY IP" << sockobj.getMachineIP();

    while(true)
    {
    Message * newM = sockobj.receiveMsg();
    cout << newM->getMessage() << endl;


    }



    return 0;
}