#include <iostream>

using namespace std;
//use a struct to define the tree
struct treeNode{
    string name;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode *parent;
};


int main()
{
    treeNode* root = new treeNode;
    root->name = "Denver";
    root->parent = NULL;
    treeNode* left = new treeNode;
    left->name = "Las Vegas";
    left->parent = root;
    treeNode* right = new treeNode;
    right->name = "Chicago";
    right->parent = root;
    //What we haven't done yet is tell root who his children are
    root->leftChild = left;
    root->rightChild = right;
    cout<<right->parent->name<<endl;
    cout<<root->leftChild->name<<endl;
    //add two more nodes to the tree
    treeNode* next = left;
    treeNode* leftL = new treeNode;
    left->leftChild = leftL;
    leftL->name = "Los Angeles";
    leftL->leftChild = NULL;
    leftL->rightChild = NULL;
    leftL->parent = next;
    treeNode* leftR = new treeNode;
    left->rightChild = leftR;
    leftR->name = "Dallas";
    leftR->leftChild = NULL;
    leftR->rightChild = NULL;
    leftR->parent = next;
    cout<<left->leftChild->name<<endl;

    return 0;
}
