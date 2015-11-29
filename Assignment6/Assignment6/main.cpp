#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "MovieTree.h"
using namespace std;

int main(int arg, char* argv[])
{
    string a = argv[1];
    MovieTree *tree = new MovieTree(argv[1]);
    while(true){
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Rent a movie"<<endl;
    cout<<"2. Print the inventory"<<endl;
    cout<<"3. Delete a movie"<<endl;
    cout<<"4. Count the movies"<<endl;
    cout<<"5. Quit"<<endl;
    string selection;
    getline(cin, selection);
    if(selection == "1"){
        string title;
        cout<<"Enter movie title"<<endl;
        getline(cin, title);
        tree->rentMovie(title);
    }
    if(selection == "2"){
        tree->printMovieInventory();
    }
    if(selection == "3"){
        string title;
        cout<<"Enter movie title"<<endl;
        getline(cin, title);
        tree->DeleteMovie(title);
    }

    if(selection == "4"){
        tree->countMovies();
    }
    if(selection == "5"){
        cout<<"Goodbye!";
        json_object* output = tree->getJsonObject();
        ofstream myfile;
        myfile.open ("Assignment6Output.txt");
        myfile << json_object_to_json_string_ext(output, JSON_C_TO_STRING_PRETTY);
        myfile.close();
        break;
    }
    }
}
