#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <iostream>
#include <json/json.h>


struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    }

};

class MovieTree
{
    public:
        MovieTree(char*);
        virtual ~MovieTree();
        void printMovieInventory();
        void addMovieNode(int ranking, std::string title, int year, int quantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);
        void DeleteMovie(std::string);
        void countMovies();
        void initJson();
        //use this to return the json object from the class when you are ready to write it to a file
        json_object* getJsonObject();

    protected:
    private:
        void DeleteAll(MovieNode * node);
        MovieNode* Delete(std::string title, MovieNode* node);
        void printMovieInventory(MovieNode * node);
        MovieNode* findMin(MovieNode *node);
        MovieNode* searchMovieTree(MovieNode * node, std::string title);
        MovieNode *root;
        void countMovies(MovieNode*);
        int movieCount;
        std::string parentDirection;
        std::string adddedArray[50];
        int addedCounter;
        std::string deletedArray[50];
        int deletedCounter;
        std::string rentedArray[200];
        int rentedCounter;
        std::string traversedArray[50];
        int traversedCounter;
        int jsonOperationNumber;
        //including the json_object in the class makes it global within the class, much easier to work with
        json_object * Assignment6Output;
};

#endif // MOVIETREE_H
