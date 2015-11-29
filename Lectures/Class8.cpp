#include <iostream>

using namespace std;

struct node{
    int key;
    node *next;
    node *previous;
};
class cNode{
//private variables can only be accessed by public methods
private:
    int x;
    cNode *next;
    cNode *previous;
public:
    cNode(int value){
    x = value;
    next = NULL;
    previous = NULL;
    }
};

int main(){
    node *x1 = new node;
    node *headNode = x1;
    x1->next=NULL;
    x1->previous=NULL;
    x1->key=0;

    int i = 1;
    while(i<5){
        node *n = new node;
        n->next=NULL;
        n->previous = x1;
        n->key = i;
        x1->next = n;
        x1 = n; //could also do x1= x1->next
        i++;
    }
    cout<<&headNode<<endl;
    cout<<&x1<<endl;
    cout<<headNode->key<<endl;
    //If I reference x1 here, what do I get?
    //x1 should be the end of the list
    while (x1 != NULL){
        cout<<x1->key<<endl;
        x1 = x1->previous;
    }
}
