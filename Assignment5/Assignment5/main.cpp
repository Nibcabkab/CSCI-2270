#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "MovieTree.h"
using namespace std;

int main(int arg, char* argv[])
{
    MovieTree *tree = new MovieTree();
    while(true){
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Find a movie"<<endl;
    cout<<"2. Rent a movie"<<endl;
    cout<<"3. Print the inventory"<<endl;
    cout<<"4. Quit"<<endl;
    string selection;
    cin>>selection;
    if(selection == "1"){
        string title;
        cout<<"Enter movie title"<<endl;
        cin>>title;
        tree->findMovie(title);
    }
    }
}
