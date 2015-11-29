//Rishab Kanwal
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include "CommunicationNetwork.h"

using namespace std;


int main(){
    //store the head of the list
    string message;
    string messageArray[32] = {};
    int queueCount = 0;
    ifstream infile;
    infile.open("messageIn.txt");
    getline(infile, message);
    istringstream line(message);
    string token;
    int i = 0;
    bool networkBuilt = false;
    while(getline(line, token, ' ')){
        messageArray[i] = token;
        i++;
    }
    int selection;
    CommunicationNetwork* network = new CommunicationNetwork(10);
    while(true){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print Network Path"<<endl;
        cout<<"3. Enqueue"<<endl;
        cout<<"4. Dequeue"<<endl;
        cout<<"5. Print Queue"<<endl;
        cout<<"6. Send Entire Message"<<endl;
        cout<<"7. Quit"<<endl;
        cin>>selection;
        if(selection == 1){
            network->buildNetwork();
            network->printPath();
            networkBuilt = true;
        }
        if(selection == 2){
            network->printPath();
        }
        if(selection == 3){
            if(queueCount<32){
                network->enqueue(messageArray[queueCount]);
                queueCount++;
            }
            else
                cout<<"No more words to queue"<<endl;
            }
        if(selection == 4){
            network->dequeue();

        }
        if(selection == 5){
            network->printQueue();
        }
        if(selection == 6){
            if(!networkBuilt)
                cout<<"Build a network before transmitting a message"<<endl;
            else{
                for(int i = 0; i < 32; i++){
                    network->transmitMsg(messageArray[i]);
                }
                network->transmitRemainingMessage();
            }

        }
        if(selection == 7){
            cout<<"Goodbye!";
            break;
        }
    }
}
