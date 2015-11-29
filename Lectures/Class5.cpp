#include <iostream>

using namespace std;

struct node{
    int key;
    node *next;
};

int main(){
    node *x = new node;//pointer to node
    node *head;
    head=x;//store the head of the list
    x->key = 0;
    cout<<x->key<<endl;
    x->next = NULL;
    int i = 1;
    while(i<5){
        node *n1 = new node;
        n1->key = 1;
        n1->next = NULL;
        x->next = n1;//Connect new node to an existing list
        cout<<x->key<<endl;
        x=x->next;//move what x points to
        i++;
    }
    cout<<x->key<<endl;
}
    //cout<<x->key<<endl;
    //cout<<x<<endl;
//    node *n1 = new node;
//    x->next = n1;
//    cout<<"address of n1 "<<n1<<endl;
//    cout<<"adderss of x->next "<<x->next<<endl;
//    int i =0;
//    while(i<5){
//        x = x->next;
//        node *n2 = new node;
//        n2->key = i+2;//set some value to the key
//        n2->next = NULL;
//        x->next =n2;
//        i++;
//    }
//    while(x!=NULL){
//        cout<<x->key<<endl;
//        x = x->next;
//    }
//    //freeing memory
//    //its important to move forward before deleting a node
//    x = head;
//    node *n = x->next;
//    while(x->next !=NULL){
//        delete x;
//        cout<<"deleting"<<endl;
//        x=n;;
//        n =n->next;
//    }
//}
