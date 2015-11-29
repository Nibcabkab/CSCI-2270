#include "Stack.h"

using std::string;

Stack::Stack(int size)
{
    maxStack = size;
    top = -1;
    items = new std::string[maxStack];
}

Stack::~Stack()
{
    delete []items;
}
void Stack::push(string c){
    top++;
    items[top] = c;
}

string Stack::pop(){
    string p = items[top];
    top--;
    return p;
}

bool Stack::isStackEmpty(){
    //The stack is empty when the top is -1
    if(top == -1)
        return true;
    else
        return false;
}
bool Stack::isStackFull(){
    //When is the stack full top  = maxSize -1
    if (top = maxStack - 1)
        return true;
    else
        return false;
}
