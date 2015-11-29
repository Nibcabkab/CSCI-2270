#include <iostream>
#include <string>
#include "hashtable.h""
using namespace std;

HashTable::HashTable(int i){
    for(int i = 0; i < 10; i++){
        hashTable[i] = NULL;
    }
}

void HashTable::insertMovie(string in_title, int year){
    Movie* newMovie = new Movie(in_title, year);
    int position = hashSum(in_title, 10);
    if(hashTable[position] == NULL){
        hashTable[position] = newMovie;
        newMovie->next = NULL;
    }
    else{
        Movie* currentNode = hashTable[position];
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = newMovie;
        newMovie->next = NULL;
    }
}
void HashTable::deleteMovie(std::string in_title){
    int position = hashSum(in_title, 10);
    if(hashTable[position] != NULL){
        Movie* currentNode = hashTable[position];
        if(currentNode->title == in_title){
            hashTable[position] = currentNode->next;
            delete currentNode;
        }
        else{
            bool movieFound = false;
            while(currentNode->next != NULL){
                if(currentNode->next->title == in_title){
                    movieFound = true;
                    break;
                }
                currentNode = currentNode->next;
            }
            if(movieFound){
                Movie* nextNode = currentNode->next->next;
                delete currentNode->next;
                currentNode->next = nextNode;
            }
        }
    }
}
Movie* HashTable::findMovie(std::string in_title){
    int position = hashSum(in_title, 10);
    if(hashTable[position] != NULL){
        Movie* currentNode = hashTable[position];
        if(currentNode->title == in_title){
            cout<<currentNode->title<<":"<<currentNode->year<<endl;
            return currentNode;
        }
        else{
            bool movieFound = false;
            while(currentNode->next != NULL){
                if(currentNode->next->title == in_title){
                    movieFound = true;
                    break;
                }
                currentNode = currentNode->next;
            }
            if(movieFound){
                cout<<currentNode->next->title<<":"<<currentNode->next->year<<endl;
                return currentNode->next;
            }
        }
    }
    cout<<"not found"<<endl;
    return NULL;
}

void HashTable::printInventory(){
    bool tableEmpty = true;
    for(int i = 0; i < 10; i++){
        if(hashTable[i] != NULL){
            Movie* currentNode = hashTable[i];
            while(currentNode->next != NULL){
                cout<<currentNode->title<<":"<<currentNode->year<<endl;
                currentNode = currentNode->next;
            }
            cout<<currentNode->title<<":"<<currentNode->year<<endl;
            tableEmpty = false;
        }
    }
    if(tableEmpty)
        cout<< "empty" <<endl;
}

int HashTable::hashSum(string title, int arraySize){
    int sum = 0;
    for(int i = 1; i < title.length(); i++){
        sum = sum + title.c_str()[i];
        sum = sum % arraySize;
    }
    return sum;
}

HashTable::~HashTable(){
    for(int i = 0; i < 10; i++){
        delete hashTable[i];
    }
}

