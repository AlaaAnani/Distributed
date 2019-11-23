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
    cout << "finished Contrustion wtf holly shit" << endl;
    time_t meeh = 90;
    int i=0;
    ifstream inputfile;
    inputfile.open("data.txt");
    string book="";
    while(!inputfile.eof())  
    {
        getline(inputfile,input);
        book+=input;
    } 
    //read jpg

    //cout << extract << endl;
    int j = 0;
    string extract;
    while(true)
    {
    cin >> input;

    extract = input;
    char * str = new char[extract.size()];  
    strcpy(str, extract.c_str());
    cout << "extract size" << extract.size() << endl;
    Message *m =new Message(Request, 1, 3, sockobj.getMyIP(), sockobj.getMyPort(), destIP, destPort, ++i, 8, extract.size(), str);
    sockobj.sendMessage(m);

    }

    return 0;
}