#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

CommunicationNetwork::CommunicationNetwork(int qs)
{
    queueSize = qs;
    arrayQueue = new string[queueSize];
    currentQueueSize = 0;
    queueHead = 0;
    queueTail = 0;
    queueisFull = false;
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
}
void CommunicationNetwork::printPath(){
    int i = 0;
    node* x = new node;
    x = head;
    cout<<"===CURRENT PATH==="<<endl;
    while(i<10){
    cout<<x->city<<" -> ";
    x = x->next;
    i++;
    }
    cout<<"NULL"<<endl;
    cout<<"================="<<endl;
    x = head;
}
void CommunicationNetwork::buildNetwork(){
    string cityArray[] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
    int i = 1;
    node* x = new node;
    head = x;
    x->city = cityArray[0];
    x->next = NULL;
    x->previous = NULL;
    while(i < 10){
        node *n1 = new node;
        n1->city = cityArray[i];
        n1->word = "";
        n1->next = NULL;
        n1->previous = NULL;
        n1->previous = x;
        x->next = n1;//Connect new node to an existing list
        x = x->next;//move what x points to
        i++;
        }
        x->next = NULL;
}

void CommunicationNetwork::enqueue(string message){
    if(currentQueueSize == 10)
        queueisFull = true;
    if(queueSize == queueTail){
        queueTail = 0;
    }
    else{
        currentQueueSize++;
    }
    arrayQueue[queueTail] = message;
    cout<<"E: "<<arrayQueue[queueTail]<<endl;
    queueTail++;
    cout<<"H: "<<queueHead<<endl;
    cout<<"T: "<<queueTail<<endl;
    if(queueisFull)
        cout<<"Queue is full"<<endl;
}
std::string CommunicationNetwork::dequeue(){
    std::string word = "";
    if(currentQueueSize == 0){
        cout<<"Queue is empty"<<endl;
    }
    else{
        if(queueSize == queueHead){
             queueHead = 0;
        }
        word = arrayQueue[queueHead];
        arrayQueue[queueHead] = "";
        node* x = new node;
        x = head;
        while(x->next != NULL){
            x->word = word;
            cout<<x->city<<" received "<<x->word<<endl;
            x->word = "";
            x = x->next;
        }
        int i = 0;
        while(i < 10){
            x->word = word;
            cout<<x->city<<" received "<<x->word<<endl;
            x->word = "";
            x = x->previous;
            i++;
        }
        queueHead++;
        currentQueueSize--;
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;
        queueisFull = false;
    }
    return word;
}
void CommunicationNetwork::printQueue(){
    int n = queueHead;
    if(currentQueueSize == 0){
        cout<<"Empty"<<endl;
    }
    else{
        for(int i = 0; i < currentQueueSize; i++){
            if(n == 10){
                n = 0;
            }
            cout<<n<<": "<<arrayQueue[n]<<endl;
            n++;
        }
    }
}
void CommunicationNetwork::transmitMsg(std::string message){
    if(queueSize == queueTail){
        queueTail = 0;
        int n = queueHead;
        for(int p = 0; p < queueSize; p++){
            std::string word = arrayQueue[n];
            arrayQueue[queueHead] = "";
            node* x = new node;
            x = head;
            while(x->next != NULL){
                x->word = word;
                cout<<x->city<<" received "<<x->word<<endl;
                x->word = "";
                x = x->next;
            }
            int i = 0;
            while(i < 10){
                x->word = word;
                cout<<x->city<<" received "<<x->word<<endl;
                x->word = "";
                x = x->previous;
                i++;
            }
            currentQueueSize--;
            n++;
        }
        queueHead = 0;
    }
    arrayQueue[queueTail] = message;
    queueTail++;
    currentQueueSize++;
}
void CommunicationNetwork::transmitRemainingMessage(){
    int n = queueHead;
    if(currentQueueSize == 0){
    }
    else{
        int n = queueHead;
        if(currentQueueSize == 0){
            cout<<"Empty"<<endl;
        }
        else{
            for(int p = 0; p < currentQueueSize; p++){
                if(n == 10){
                    n = 0;
                }
                std::string word = arrayQueue[n];
                arrayQueue[queueHead] = "";
                node* x = new node;
                x = head;
                while(x->next != NULL){
                    x->word = word;
                    cout<<x->city<<" received "<<x->word<<endl;
                    x->word = "";
                    x = x->next;
                }
                int i = 0;
                while(i < 10){
                    x->word = word;
                    cout<<x->city<<" received "<<x->word<<endl;
                    x->word = "";
                    x = x->previous;
                    i++;
                }
                n++;
            }
        }
    }
}


