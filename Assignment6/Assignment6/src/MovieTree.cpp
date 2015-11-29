#include "MovieTree.h"
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <json/json.h>


using namespace std;
void MovieTree::addMovieNode(int ranking, std::string title, int year, int quantity){
    MovieNode *newNode = new MovieNode(ranking, title, year, quantity);
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    string testTitle;
    MovieNode* x = root;
    MovieNode* y = NULL;
    addedCounter = 0;
    if(root != NULL){
        adddedArray[addedCounter] = root->title;
        addedCounter++;
    }
    string originalTestTitle;
    while(true){
       testTitle = x->title;
       originalTestTitle = testTitle;
       std::transform(testTitle.begin(), testTitle.end(), testTitle.begin(), ::tolower);
       y = x;
       if(testTitle.compare(title) > 0){
           x = x->leftChild;
       }
       else if(testTitle.compare(title) < 0){
           x = x->rightChild;
       }
       if(x == NULL)
           break;
       else{
           adddedArray[addedCounter] = x->title;
           addedCounter++;
           }
    }
    if(testTitle.compare(title) > 0){
        y->leftChild = newNode;
        newNode->rightChild = NULL;
        newNode->leftChild = NULL;
    }
    if(testTitle.compare(title) < 0)
        y->rightChild = newNode;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
}

MovieTree::MovieTree(char* a)
{
    Assignment6Output = json_object_new_object();
    jsonOperationNumber = 1;
    addedCounter = 0;
    deletedCounter = 0;
    rentedCounter = 0;
    ifstream infile;
    infile.open(a);
    string strline;
    int i = 0;
    while(!infile.eof()){
        getline(infile, strline);
        istringstream line(strline);
        string token;
        int ranking;
        string title;
        int year;
        int quantity;
        //cout<<strline<<endl;
        int p = 0;
        while(getline(line, token, ',')){
                if(p == 0)
                    ranking = atoi(token.c_str());
                if(p == 1)
                    title = token;
                if(p == 2)
                    year = atoi(token.c_str());
                if(p == 3)
                    quantity = atoi(token.c_str());
                p++;
            }
        if(i == 0){
            MovieNode *newNode = new MovieNode(ranking, title, year, quantity);
            root = newNode;
            root->rightChild = NULL;
            root->leftChild = NULL;
            root->parent = NULL;
            addedCounter = 0;
        }
        else{
            addMovieNode(ranking, title, year, quantity);
        }
        json_object *jMovie = json_object_new_array();
        json_object *jTitle = json_object_new_string(title.c_str());
        json_object *jOp1 = json_object_new_object();
        json_object *jAdd = json_object_new_string("add");
        json_object_object_add(jOp1, "operation", jAdd);
        json_object_object_add(jOp1, "parameter", jTitle);
        for(int i = 0; i < addedCounter; i++){
            json_object *jMovieAdd = json_object_new_string(adddedArray[i].c_str());
            json_object_array_add(jMovie, jMovieAdd);
        }
        json_object_object_add(jOp1, "output", jMovie);
        std::ostringstream os;
        os << jsonOperationNumber;
        string jsonOperationNumberString = os.str();
        json_object_object_add(Assignment6Output, jsonOperationNumberString.c_str(), jOp1);
        jsonOperationNumber++;
        i++;
    }
}
void MovieTree::DeleteAll(MovieNode * node){
    if(node != NULL){
        DeleteAll(node->leftChild);
        DeleteAll(node->rightChild);
        delete node;
    }
}
void MovieTree::printMovieInventory(){
    traversedCounter = 0;
    printMovieInventory(root);
    json_object *jMovie = json_object_new_array();
    json_object *jOp3 = json_object_new_object();
    json_object *jTraversed = json_object_new_string("traverse");
    json_object_object_add(jOp3, "operation", jTraversed);
    for(int i = 0; i < traversedCounter; i++){
        json_object *jMovieTraversed = json_object_new_string(traversedArray[i].c_str());
        json_object_array_add(jMovie, jMovieTraversed);
    }
    json_object_object_add(jOp3, "output", jMovie);
    std::ostringstream os;
    os << jsonOperationNumber;
    string jsonOperationNumberString = os.str();
    json_object_object_add(Assignment6Output, jsonOperationNumberString.c_str(), jOp3);
    jsonOperationNumber++;
}

void MovieTree::printMovieInventory(MovieNode* test){
    MovieNode *x = test;
    if(x->leftChild != NULL){
        printMovieInventory(x->leftChild);}
    cout<<x->title<<endl;
    /*json_object *jMovie = json_object_new_array();
    json_object *jOp3 = json_object_new_object();
    json_object *jTraversed = json_object_new_string("traverse");
    json_object_object_add(jOp3, "operation", jTraversed);
    for(int i = 0; i < traversedCounter; i++){
        json_object *jMovieTraversed = json_object_new_string(traversedArray[i].c_str());
        json_object_array_add(jMovie, jMovieTraversed);
    }
    json_object_object_add(jOp3, "output", jMovie);
    std::ostringstream os;
    os << jsonOperationNumber;
    string jsonOperationNumberString = os.str();
    json_object_object_add(Assignment6Output, jsonOperationNumberString.c_str(), jOp3);
    jsonOperationNumber++;
    traversedArray[traversedCounter] = x->title;
    traversedCounter++;*/
    traversedArray[traversedCounter] = x->title;
    traversedCounter++;
    if(x->rightChild != NULL){
        printMovieInventory(x->rightChild);
    }

}
void MovieTree::findMovie(std::string title){
    MovieNode* x = root;
    MovieNode* y = NULL;
    bool movieFound = false;
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    string testTitle;
    while(x != NULL){
                testTitle = x->title;
                std::transform(testTitle.begin(), testTitle.end(), testTitle.begin(), ::tolower);
                y = x;
                if(testTitle.compare(title) > 0){
                    x = x->leftChild;
                }
                if(testTitle.compare(title) < 0){
                    x = x->rightChild;
                }
                if(testTitle.compare(title) == 0){
                    movieFound = true;
                    break;
                }
            }
    if(movieFound){
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<x->ranking<<endl;
        cout<<"Title:"<<x->title<<endl;
        cout<<"Year:"<<x->year<<endl;
        cout<<"Quantity:"<<x->quantity<<endl;
    }
    else
        cout<<"Movie not found"<<endl;
}
void MovieTree::rentMovie(std::string title){
    MovieNode* x = root;
    MovieNode* y = NULL;
    bool movieFound = false;
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    string testTitle;
    rentedCounter = 0;
    string originalTestTitle;
    while(x != NULL){
                testTitle = x->title;
                originalTestTitle = testTitle;
                std::transform(testTitle.begin(), testTitle.end(), testTitle.begin(), ::tolower);
                y = x;
                if(testTitle.compare(title) > 0){
                    x = x->leftChild;
                    rentedArray[rentedCounter] = originalTestTitle;
                    rentedCounter++;
                }
                if(testTitle.compare(title) < 0){
                    x = x->rightChild;
                    rentedArray[rentedCounter] = originalTestTitle;
                    rentedCounter++;
                }
                if(testTitle.compare(title) == 0){
                    movieFound = true;
                    break;
                }
            }
    if(movieFound && x->quantity != 0){
        x->quantity--;
        cout<<"Movie has been rented."<<endl;
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<x->ranking<<endl;
        cout<<"Title:"<<x->title<<endl;
        cout<<"Year:"<<x->year<<endl;
        cout<<"Quantity:"<<x->quantity<<endl;
        json_object *jTitle = json_object_new_string(originalTestTitle.c_str());
        json_object *jCount = json_object_new_int(x->quantity);
        json_object *jOp5 = json_object_new_object();
        json_object *jRent = json_object_new_string("rent");
        json_object_object_add(jOp5, "operation", jRent);
        json_object_object_add(jOp5, "parameter", jTitle);
        json_object_object_add(jOp5, "output", jCount);
        std::ostringstream os;
        os << jsonOperationNumber;
        string jsonOperationNumberString = os.str();
        json_object_object_add(Assignment6Output, jsonOperationNumberString.c_str(), jOp5);
        jsonOperationNumber++;
    }
    else if(movieFound && x->quantity == 0)
        cout<<"Movie out of stock."<<endl;
    else
        cout<<"Movie not found"<<endl;
}
MovieNode* MovieTree::findMin(MovieNode *node){
    while(node->leftChild != NULL)
        node = node->leftChild;
    return node;
}
void MovieTree::countMovies(){
    movieCount = 0;
    countMovies(root);
    cout<<movieCount<<endl;
    json_object *jOp4 = json_object_new_object();
    json_object *jCount = json_object_new_string("count");
    json_object *jMovieCount = json_object_new_int(movieCount);
    json_object_object_add(jOp4, "operation", jCount);
    json_object_object_add(jOp4, "output", jMovieCount);
    std::ostringstream os;
    os << jsonOperationNumber;
    string jsonOperationNumberString = os.str();
    json_object_object_add(Assignment6Output, jsonOperationNumberString.c_str(), jOp4);
    jsonOperationNumber++;
}

void MovieTree::countMovies(MovieNode* node){
    MovieNode *x = node;
    movieCount++;
    if(x->leftChild != NULL){
        countMovies(x->leftChild);}
    if(x->rightChild != NULL){
        countMovies(x->rightChild);
    }
}
void MovieTree::DeleteMovie(std::string title){
    MovieNode* x = root;
    MovieNode* y = NULL;
    bool movieFound = false;
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    string testTitle;
    deletedCounter = 0;
    string originalTestTitle;
    testTitle = root->title;
    std::transform(testTitle.begin(), testTitle.end(), testTitle.begin(), ::tolower);
    if(testTitle.compare(title) != 0){
            deletedArray[deletedCounter] = root->title;
            deletedCounter++;
        }
    while(x != NULL){
        testTitle = x->title;
        originalTestTitle = testTitle;
        std::transform(testTitle.begin(), testTitle.end(), testTitle.begin(), ::tolower);
        y = x;
        if(testTitle.compare(title) > 0){
            x = x->leftChild;
        }
        else if(testTitle.compare(title) < 0){
            x = x->rightChild;
        }
        if(x != NULL && testTitle.compare(title) != 0){
            deletedArray[deletedCounter] = x->title;
            deletedCounter++;
        }
        if(testTitle.compare(title) == 0){
            movieFound = true;
            break;
        }
    }
    if(movieFound){
        Delete(title, root);
        parentDirection = "";
        json_object *jMovie = json_object_new_array();
        json_object *jTitle = json_object_new_string(originalTestTitle.c_str());
        json_object *jOp2 = json_object_new_object();
        json_object *jDelete = json_object_new_string("delete");
        json_object_object_add(jOp2, "operation", jDelete);
        json_object_object_add(jOp2, "parameter", jTitle);
        for(int i = 0; i < deletedCounter-1; i++){
            json_object *jMovieDelete = json_object_new_string(deletedArray[i].c_str());
            json_object_array_add(jMovie, jMovieDelete);
        }
        json_object_object_add(jOp2, "output", jMovie);
        std::ostringstream os;
        os << jsonOperationNumber;
        string jsonOperationNumberString = os.str();
        json_object_object_add(Assignment6Output, jsonOperationNumberString.c_str(), jOp2);
        jsonOperationNumber++;

    }
    else{
        cout<<"Movie not found"<<endl;
    }
}
MovieNode* MovieTree::Delete(std::string title, MovieNode* node){
    if(node == NULL)
        return node;
    std::transform(title.begin(), title.end(), title.begin(), ::tolower);
    string testTitle = node->title;
    std::transform(testTitle.begin(), testTitle.end(), testTitle.begin(), ::tolower);
    if(testTitle.compare(title) > 0){
        parentDirection = "left";
        node->leftChild = Delete(title, node->leftChild);
    }
    else if(testTitle.compare(title) < 0){
        parentDirection = "right";
        node->rightChild = Delete(title, node->rightChild);
    }
    else if(testTitle.compare(title) == 0){
        if(node->leftChild == NULL && node->rightChild ==NULL){
            if(parentDirection == "left")
                node->parent->leftChild == NULL;
            else if(parentDirection == "right")
                node->parent->rightChild = NULL;
            delete node;
            node = NULL;
        }
        else if(node->leftChild == NULL){
            MovieNode* temp = node;
            node = node->rightChild;
            delete temp;
        }
        else if(node->rightChild == NULL){
            MovieNode* temp = node;
            node = node->leftChild;
            delete temp;
        }
        else{
            MovieNode* temp = findMin(node->rightChild);
            node->ranking = temp->ranking;
            node->title = temp->title;
            node->year = temp->year;
            node->quantity = temp->quantity;
            node->rightChild = Delete(temp->title, node->rightChild);
        }
    }
    return node;
}

json_object* MovieTree::getJsonObject(){
    return Assignment6Output;
}
MovieTree::~MovieTree()
{
    DeleteAll(root);
}
