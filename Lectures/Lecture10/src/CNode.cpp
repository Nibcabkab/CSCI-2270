#include "CNode.h"
#include <iostream>

//Implementation of CNode.h

CNode::CNode(int value, int arraySize)
{
    //ctor
    x = value;
    dataArray = new int(arraySize);
    next = NULL;
    previous = NULL;
    maxSize = arraySize; //how big is the array

}

CNode::~CNode()
{
    //dtor
    delete[] dataArray;
}
CNode*  CNode::getNext(){
    return next;
}
CNode* CNode::getPrevious(){
    return previous;
}
int CNode::getX(){
    return x;
}
int CNode::getArrayData(int index){
    return dataArray[index];
}
void CNode::setNext(CNode* n){
    next = n;
}
void CNode::setPrevious(CNode* p){
    previous = p;
}
void CNode::setX(int xc){
    x = xc;
}
void CNode::setArrayData(int index, int d){
    if(index < maxSize)
    dataArray[index] = d;
    else{
        std::cout<<"index out of bounds\n";
    }
}
