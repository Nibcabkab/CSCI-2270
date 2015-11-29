#include <iostream>
#include "Stack.h"
using namespace std;
//if the stack is implemented in as a singly linked list
//with array the size is fixed but with a linked list we don't need a fixed size so you don't have to declare the array
//pointer to the top node instead of the top of the index
//add nodes to the list
//destructor, we need to have a loop to destroy the list
//can keep popping until the previous pointer is not null
int main()
{
    Stack *s = new Stack(5);
    s->push("test");
    s->push("test2");
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
    return 0;
}
