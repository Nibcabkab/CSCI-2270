#include <iostream>
#include "CNode.h"
using namespace std;

int main()
{
    /*Create an instance of the class by calling the class constructor.*/
    /*Each CNode has an array created dynamically of size = arraySize. The
    constructor also allocates memory for that array.*/
    int arraySize = 10;
    CNode *cn = new CNode(0, arraySize);
    CNode *n = new CNode(1, arraySize);
    cn->setNext(n);
    n->setPrevious(cn);

    //this will appear to work, but you will have future problems
    //cn->setArrayData(20,20);

    for(int i = 0; i < 10; i++){
        cn->setArrayData(i, i+2);
    }
    /*These getArrayData calls that go outside the index will appear
    to return something, but the data is garbage. The same is true for
    setArrayData, it might appear to work but you will likely have
    strange seg fault errors further on in the program if you write
    to memory that you haven't allocated for your variable.
    We can add a check to the setArrayData that only updates the array
    if the index is within the bounds of allocated memory.

    How could we do this for getArrayData? We want to be able to only call
    getArrayData if we know that the index is in bounds? The method is
    expecting a return value, so just printing in that the array is out of
    bounds doesn't really work. We could create an additional class method
    called isValidIndex or something equivalent, and only call getArrayData
    if isValidIndex is true.
    */
    for(int i = 0; i < 20; i++){
        cout<<cn->getArrayData(i)<<endl;
    }
    for(int i = 0; i < 20; i++){
        cout<<n->getArrayData(i)<<endl;
    }

    for(int i = 0; i < 20; i++){
        cn->setArrayData(i, i+2);
    }

    delete cn;
    delete n;

    CNode *x = new CNode(0, arraySize);
    CNode *head = x;
    //build the list with setNext, setPrevious
    for(int i = 0; i < 10; i++){
        CNode *n1 = new CNode(i + 1, arraySize + i);
        n1->setPrevious(x);
        x->setNext(n1);
        x = n1; //could also use x=x->getNext();
    }
    //iterate backwards
    for(int i = 0; i < 10; i++){
        cout<<x->getX()<<endl;
        x = x->getPrevious();
    }
    //we should free the linked list here
    x = head;
    for(int i = 0; i < 10; i++){
        x = x->getNext();
        delete x->getPrevious();
    }
    delete x;

    return 0;
}
