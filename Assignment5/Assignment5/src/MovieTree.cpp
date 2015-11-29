#include "MovieTree.h"
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

MovieTree::MovieTree()
{
 ifstream infile;
    //infile.open(argv[1]);
    infile.open("Assignment5Movies.txt");
    string strline;
    MovieNode* parent = NULL;
    while(!infile.eof()){
        getline(infile, strline);
        istringstream line(strline);
        string token;
        int ranking;
        string title;
        int year;
        int quantity;
        int i = 0;
        //cout<<strline<<endl;
        while(getline(line, token, ',')){
                if(i == 0)
                    ranking = atoi(token.c_str());
                if(i == 1)
                    title = token;
                if(i == 2)
                    year = atoi(token.c_str());
                if(i == 3)
                    quantity = atoi(token.c_str());
                i++;
            }
        MovieNode *x = new MovieNode(ranking, title, year, quantity);
        x->parent = parent;
        if(parent == NULL)
            root = x;
        if(parent != NULL){
            string parent_title = parent->title;
            std::transform(title.begin(), title.end(), title.begin(), ::tolower);
            std::transform(parent_title.begin(), parent_title.end(), parent_title.begin(), ::tolower);
            if(parent_title.compare(title) > 0){
                parent->leftChild = x;
                parent->rightChild = NULL;
                cout<<"left"<<endl;
            }
            if(parent_title.compare(title) < 0){
                parent->rightChild = x;
                parent->leftChild = NULL;
                cout<<"right"<<endl;
            }
        }
        parent = x;
    }
    printMovieInventory(root);
}

MovieTree::~MovieTree()
{
    //dtor
}

void MovieTree::printMovieInventory(MovieNode* test){
    MovieNode *x = test;
    if(x->leftChild != NULL){
        printMovieInventory(x->leftChild);}
    cout<<x->title<<endl;
    if(x->rightChild != NULL){
        printMovieInventory(x->rightChild);
    }

}
void MovieTree::findMovie(std::string title){
    MovieNode* x = root;
    string test_title = x->title;
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    std::transform(test_title.begin(), test_title.end(), test_title.begin(), ::tolower);
    while(x->leftChild != NULL || x->rightChild != NULL){
    title = x->title;
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
        if(test_title.compare(title) > 0){
            x = x->leftChild;
        }
        else if(test_title.compare(title) < 0){
            x = x->rightChild;
        }
        else if(test_title.compare(title) < 0)
            cout<<"found";
    }
}


