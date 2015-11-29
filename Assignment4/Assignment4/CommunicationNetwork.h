#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include<string>
struct node{

    std::string city;
    std::string word; //intended to hold one word
    node *next;
    node *previous;

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork(int);
        virtual ~CommunicationNetwork();
        //circular queue methods
        void enqueue(std::string);
        std::string dequeue(); //should send through network, call transmit msg
        void printQueue();
        void buildNetwork();
        void printPath();
        bool queueIsFull(); //send when full
        void transmitRemainingMessage();
        void transmitMsg(std::string);

    protected:
    private:
        node *head;
        node *tail;
        int queueSize;
        int currentQueueSize;
        bool queueisFull;
        int queueHead;
        int queueTail;
        std::string *arrayQueue;
};

#endif // COMMUNICATIONNETWORK_H