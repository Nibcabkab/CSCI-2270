#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
using namespace std;

int main(int arg, char* argv[])
{
    HashTable *movieTable = new HashTable(1);
    ifstream infile;
    infile.open(argv[1]);
    string strline;
    while(!infile.eof()){
        getline(infile, strline);
        stringstream line(strline);
        string token;
        string title;
        int year;
        int position = 0;
        while(getline(line, token, ',')){
            if(position == 1)
                title = token;
            else if(position == 2)
                year = atoi(token.c_str());
            position++;
        }
        //movieTable->insertMovie(title, year);
    }
    while(true){
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Insert movie"<<endl;
    cout<<"2. Delete movie"<<endl;
    cout<<"3. Find movie"<<endl;
    cout<<"4. Print table contents"<<endl;
    cout<<"5. Quit"<<endl;
    string selection;
    getline(cin, selection);
    if(selection == "1"){
        string title;
        cout<<"Enter title:"<<endl;
        getline(cin, title);
        string year;
        cout<<"Enter year:"<<endl;
        getline(cin, year);
        movieTable->insertMovie(title, atoi(year.c_str()));
    }
    if(selection == "2"){
        string title;
        cout<<"Enter title:"<<endl;
        getline(cin, title);
        movieTable->deleteMovie(title);
    }
    if(selection == "3"){
        string title;
        cout<<"Enter title:"<<endl;
        getline(cin, title);
        movieTable->findMovie(title);
    }

    if(selection == "4"){
        movieTable->printInventory();
    }
    if(selection == "5"){
        cout<<"Goodbye!";
        delete movieTable;
        break;
    }
    }
}
