#include "MovieNode.h"

MovieNode::MovieNode()
{
    while(!infile.eof()){
        MovieNode *root = new MovieNode;
        root->parent = NULL;
        string word;
        getline(infile, strline);
        istringstream line(strline);
        string token;
        int i = 0;
        while(getline(line, token, ',')){
                cout<<token<<" ";
                if(i == 0)
                    root->ranking =
            }
        cout<<endl;
        }
        cout<<root->name;
}

MovieNode::~MovieNode()
{
    //dtor
}
void printMovieInventory();
