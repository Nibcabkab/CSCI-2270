#include <iostream>

using namespace std;
struct node{
    int key;
    node *next;
    node *previous;
};

class CNode{
private:
    int x;
    CNode *next;
    CNode *previous;
public:
    CNode(int value){
        x = value;
        next = NULL;
        previous = NULL;
    }

    ~CNode(){} //don't really need this yet

    /*The real value of protecting our variables is that we can neatly control
    how they are set. For example, in your current assignment, you are adding
    cities to a network. We could easily add a requirement to the add city that
    cities need to be within 50 miles of each other. You could encapsulate
    the logic of checking distance between cities in the setNext and setPrevious
    methods and your code would look much cleaner than if you had to do that
    checking in your main driver file.*/
    void setNext(CNode *n){
        next = n;
    }
    CNode* getNext(){
        return next;
    }

    void setPrevious(CNode *p){
        previous = p;
    }
    CNode* getPrevious(){
        return previous;
    }

    void setX(int xIn){
        x = xIn;
    }

    int getX(){
        return x;
    }
};

int main()
{

    //doubly linked list with a struct
    node *x1 = new node;
    node *headNode = x1;
    x1->next = NULL;
    x1->previous = NULL;
    x1->key = 0;
    int i = 1;
    /*This builds our list. The only really change here from previous examples
    is adding a previous pointer.*/
    while(i < 5){
        node *n = new node;
        n->next = NULL;
        n->previous = x1;
        n->key = i;
        x1->next = n;
        x1 = n; //could also do x=x->next
        i++;
    }
    //what is x at this point in the code?
    //it should be the last node in the list, and x->next is NULL

    //now that we have a previous pointer, we can go backward through the list
    cout<<"printing struct list back to front"<<endl;
    while(x1 != NULL){
        cout<<x1->key<<endl;
        x1 = x1->previous;
    }
    cout<<"entering class examples"<<endl;
    CNode *cn = new CNode(0); //the next and previous are also set to null here
    CNode *cn1 = new CNode(1);
    cn->setNext(cn1); //replaces the x->next = n in our prior examples
    cn1->setPrevious(cn);
    cout<<cn1->getX()<<endl;

    CNode *x = new CNode(0);
    CNode *head = x;
    //build the list with setNext, setPrevious
    for(int i = 0; i < 10; i++){
        CNode *n1 = new CNode(i);
        n1->setPrevious(x);
        x->setNext(n1);
        x = n1; //could also use x=x->getNext();
    }
    //iterate backwards
    for(int i = 0; i < 10; i++){
        cout<<x->getX()<<endl;
        x = x->getPrevious();
    }
    return 0;
}
