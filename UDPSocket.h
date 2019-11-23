#ifndef UDPSOCKET_H
#define UDPSOCKET_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include "string.h"
#include <thread>
#include <mutex>  
#include <queue>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> 
#include "Message.h"
#include <algorithm>
#include <math.h>
#include <thread>
#include <unordered_map>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <chrono>
#include <sys/time.h>
#include <unistd.h>
#include <ctime>

//#define RECEIVE_OUTPUT_FILE_LOG
//#define DEBUG
class UDPSocket
{
    protected:
        int sock;
        struct sockaddr_in myAddr;
        int myPort;
        string myAddress_str;
        thread * ReceiveThread;
        thread* SendThread;
        queue<Message *> ReceiveBuffer;
        queue<Message *> SendBuffer;
        //<trials, <time_since_last_trial, message>>
        //queue <pair<int, pair<chrono::steady_clock::time_point, Message *>>> NonRepliedRequests;
        //queue <pair<int, pair<chrono::steady_clock::time_point, Message *>>> NonAckedReplies;

        mutex ReceiveBufferMtx;
        mutex SendBufferMtx;
        bool dest= false;
        bool enabled = true;
        unsigned int FRAG_MSG_SIZE = 10000;
        unsigned int SOCK_MAX_BUFFER_SIZE = 100000;
        ofstream outFile;

    public:    
        UDPSocket ();   
        void setBroadcast(int s);
        bool initializeSocket(char * _myAddr, unsigned int _myPort);
        bool initializeSocket(unsigned int _myPort);
        char * getMachineIP();
        int getMyPort(); 
        string getMyIP();
        void setMyPort(unsigned int _myPort);
        Message * receiveMsg();
        bool sendMessage(Message * FullMessage);
        void fragmentMsg(Message * FullMessage, vector<Message *> & frags);
        string getMsgID(Message* message);
        void sendingHandler(UDPSocket * myUDPSocket);
        void receiveHandler(UDPSocket * myUDPSocket);
        ~UDPSocket ( );
};
#include "UDPSocket.cpp"
#endif // UDPSOCKET_H