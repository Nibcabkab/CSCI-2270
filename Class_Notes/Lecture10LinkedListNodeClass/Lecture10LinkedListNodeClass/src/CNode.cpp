#include "CNode.h"
#include <iostream>

/*
the :: is a scope operator
the functions on the right of the :: are members
of the class on the left of the ::
The return type is the left-most value
*/

/*This file contains the implementation details for the
class interface defined in CNode.h */
CNode::CNode(int value, int arraySize)
{
    x = value;
    dataArray = new int[arraySize];
    next = NULL;
    previous = NULL;
    maxSize = arraySize;

}
/*In our destructor, we need to explicitly free the dataArray
because we created it dynamically.*/
CNode::~CNode()
{
    delete[] dataArray;
}

CNode* CNode::getNext(){
    return next;
}
CNode* CNode::getPrevious(){
    return previous;
}
int CNode::getX(){
    return x;
}

void CNode::setNext(CNode* n){
    next = n;
}
void CNode::setPrevious(CNode* p){
    previous = p;
}
//check that index within range
void CNode::setArrayData(int index, int d){
    if(index < maxSize){
        dataArray[index] = d;
    }else{
        std::cout<<"index out of bounds\n";
    }
}
int CNode::getArrayData(int index){
    return dataArray[index];
}
