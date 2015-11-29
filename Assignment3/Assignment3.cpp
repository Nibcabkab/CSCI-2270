//Rishab Kanwal
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

struct node{
    string city;
    node *next;
    string word;
};

node *x = new node;//pointer to node
node *head;
int networkLength = 10;
void printNetwork(){
    int i = 0;
    x = head;
    cout<<"===CURRENT PATH==="<<endl;
    while(i<networkLength){
    cout<<x->city<<" -> ";
    x = x->next;
    i++;
    }
    cout<<"NULL"<<endl;
    cout<<"================="<<endl;
    x = head;
}

void buildNetwork(){
    string cityArray[] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
    int i = 1;
    x = head;
    x->city = cityArray[0];
    x->next = NULL;
    while(i < networkLength){
        node *n1 = new node;
        n1->city = cityArray[i];
        n1->next = NULL;
        x->next = n1;//Connect new node to an existing list
        x = x->next;//move what x points to
        i++;
        }
        x->next = NULL;
        x = head;
    printNetwork();
}
void messageTransmit(){
    ifstream infile;
    string strline;
    infile.open("messageIn.txt");
    while(!infile.eof()){
        string word;
        getline(infile, strline);
        istringstream line(strline);
        string token;
        while(getline(line, token, ' ')){
            int i = 0;
            while(i<networkLength){
                x->word = token;
                cout<<x->city<<" received "<<x->word<<endl;
                x->word = "";
                x = x->next;
                i++;
            }
            x = head;
        }
    }
}
void addCity(string previousCity, string  cityName){
    int i = 0;
    int n = 0;
    node* temp = new node;
    temp->city = cityName;
    if(previousCity == "First"){
        temp->next=head;
        head = temp;
        x = head;
        }
    else if(head->city == previousCity){
            node* temp2 = head->next;
            head->next = temp;
            head = temp->next;
        }
    else{
        for(i = 0; i < networkLength; i++){
            if(x->city == previousCity){
                n = i;
                break;
            }
            x = x->next;
        }
        node* temp2 = head;
        for(i = 0; i < n; i++){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
    printNetwork();
    }
void deleteCity (string cityName){
    int i = 0;
    int n = 0;
    node* temp = new node;
    if(cityName == head->city){
        temp = head;
        head = head->next;
        delete temp;
    }
    else{
        for(i = 0; i < networkLength; i++){
            if(x->city == cityName){
                temp = x->next;
                n = i;
                break;
            }
            x = x->next;
            }
        cout<<n<<endl;
        node* temp2 = head;
        for(i = 0; i < n-1; i++){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        delete x;
    }
    networkLength--;
    printNetwork();
    }
void clearNetwork(){
    x = head;
    node* n = x->next;
    while(x->next != NULL){
        delete x;
        x = n;
        n = n->next;
    }
}


int main(){
    //store the head of the list
    head=x;
    x = head;
    int selection;
    while(true){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print Network Path"<<endl;
        cout<<"3. Transmit Message Coast-To-Coast"<<endl;
        cout<<"4. Add City"<<endl;
        cout<<"5. Delete City"<<endl;
        cout<<"6. Clear Network"<<endl;
        cout<<"7. Quit"<<endl;
        cin>>selection
        if(selection == 1){
            buildNetwork();
        }
        if(selection == 2){
            printNetwork();
        }
        if(selection == 3){
            messageTransmit();
            }
        if(selection == 4){
            cout<<"Enter a city name:";
            string cityName;
            cin>>cityName;
            cout<<"Enter a previous city name:";
            string previousCity;
            cin>>previousCity;
            addCity(previousCity, cityName);
            networkLength ++;
            cout<<x->city<<endl;
        }
        if(selection == 5){
            cout<<"Enter city name:";
            string cityName;
            cin>>cityName;
            deleteCity(cityName);
        }
        if(selection == 6){
            clearNetwork();
        }
        if(selection == 7){
            cout<<"Goodbye !";
            break;
        }
    }
}

