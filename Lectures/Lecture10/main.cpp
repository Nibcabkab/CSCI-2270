#include <iostream>
#include "CNode.h"

using namespace std;

int main()
{
    CNode *cn = new CNode(0, 10);
    CNode *n = new CNode(1,5);
    //cn->setNext(n);
    //we can write past 10 =, but we really don't have the rights to do it
    n->setPrevious(cn);
    for(int i = 0; i < 20; i++){
        cn->setArrayData(i, i+2);
    }
    for(int i = 0; i < 10; i++){
        cout<<cn->getArrayData(i)<<endl;
    }
    delete cn;
    delete n;
    //double lined list
    int as = 10;
    CNode* x = new CNode(0, as);
    CNode* head = x;
    for(int i; i < 10; i++){
        CNode* n1 = new CNode(i+1, as + i);
        n1->setPrevious(x);
        x->setNext(n1);
        x = n1;
    }
    for(int i = 0; i < 10; i++){
        cout<<x->getX()<<endl;
        x = x->getPrevious();
    }
    //Delete the list
    x = head;
    for(int i = 0; i < 10; i++){
        x = x->getNext();
        delete x->getPrevious();
    }
    delete x;
    return 0;
}
