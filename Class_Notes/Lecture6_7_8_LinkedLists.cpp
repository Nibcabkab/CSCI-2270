/*Lecture 6,7,8 - Linked Lists
Rhonda Hoenigman
CU Boulder, Spring 2015
*/
#include <iostream>

using namespace std;
/*Moving between array items uses the index of the item in the array.
If you want to insert an item in the array, you need to change the index
of many other items in the array and possibly even change the size of the
array.

With a linked list, you have a collection of items and a pointer between
those items that sets the order. Each item is a node, either a struct or
a class*/

/*node struct with two members, an integer key and a pointer to the next
node. This is a node for a singly linked list.*/
struct node{
    int key;
    node *next; //pointer to another node. it's the same type
};

node *listInsert(node* n, node* n2);
node *searchList(node *head, int key);

int main()
{
    /*Creates a pointer to a struct node, but no memory has yet been allocated
    for the node. The naming convention here is intended to match the
    pseudocode in your text book. */
    node *x;
    node *head;
    /*Allocate memory to the node dynamically. Doing it this way, we're not
    pointing to an existing node, we're creating a new node. When building
    the list, we generally need to do this, allocate memory for each node.
    */
    x = new node;

    head = x;
    /*With head=x, we've set the head node to be the same as x. This is
    necessary because it gives us a way to traverse the list, since we
    only have a forward pointer for a linked list. We're storing the
    head of the list.*/

    /*Set value of key for x.
    Notice the syntax, it's different than anything we've done so far.
    The -> operator is used for pointers to members of complex types.
    */
    x->key = 5;
    cout<<x->key<<endl;

    //is equivalent to
    (*x).key = 1;
    cout<<x->key<<endl;

    /*Setting next for x. First, we need to create another pointer of
    type node, and then allocate memory for node, and then set
    x->next to point to the newly allocated node.*/
    node *n1;
    n1 = new node;
    //check the address of n1
    cout<<"address of n1: "<<n1<<endl;

    x->next = n1;
    //check address of root->next, it's the same as address of n1
    cout<<"address of next: "<<x->next<<endl;

    /*Adding nodes over and over until you've added all you need.
    If you were using an array of items, you would allocate all memory
    at one time. But, with a linked list, you add items one at a time
    by keeping track of the current end of the list and appending another
    node onto the end.

    To do this, we need our list and a pointer to the end of
    our list.

    Pseudo-code order:
    From current node, move to next node (assumes there is a next)
    Create a new node and set its values, key = number, next = NULL
    Set current node's next node to be the new node just created
    */

    int i = 0;
    while(i < 5){
        //root is a pointer, we're getting the address of the last
        //node in the list
        x = x->next;
        cout<<x<<endl;
        node *n2 = new node;
        n2->key = i+2;
        n2->next = 0; //null
        x->next = n2;
        i++;
    }
    //reset the pointer to the beginning of the linked list
    x = head;
    /*x is a pointer, it's just an address, and we can use
    it to point to any address. In this next example, we're
    using x to store x->next, which is also an address.
    Once we have the next node, we can get the key value for that
    node.
    */
    cout<<"linked list iteration"<<endl;
    while(x != NULL){
        cout<<x->key<<endl;
        x = x->next;
    }
    //we must explicity free the memory
    //this is called garbage collection
    /*starting with the struct, you can delete each node at
    a time, but you want to make sure you get the next pointer
    before you delete a node, otherwise, there's no path to
    the next node.*/

    //we stored the beginning of the linked list in head

    x = head;
    cout<<"starting garbage collection"<<endl;
    node *n;
    n = x->next; //store the next so it's not lost
    while(x->next != NULL){
        cout<<"deleting "<<x<<endl;
        delete x;
        x = n; //this is x->next
        /*Keep the next node in the list stored so that it
        isn't lost during the delete process.*/
        n = n->next;
    }

    /*
    Insert nodes at the beginning of the list. Create function that
    inserts a node and returns the new head of the list.
    */
    /*Rebuild the list that we just deleted.*/
    head = new node;
    head->key = 1;
    head->next = NULL;
    x = new node;
    x->key = 99;
    head = listInsert(head, x); //function prototype above main
    cout<<head<<endl;
    cout<<head->key<<endl;
    i = 0;
    while(i < 5){
        x = new node;
        x->next = NULL;
        x->key = i;
        head = listInsert(head, x);
        cout<<head->key<<endl;
        i++;
    }
    /*Search the list for the specified key. Function defined
    below main.*/
    node *found = searchList(head, 4);
    if(found != NULL){
        cout<<"found it "<<found->key<<endl;
    }else{
        cout<<"list doesn't contain that value"<<endl;
    }

    return 0;
}
/*The complexity of inserting a node at the beginning of a linked
list is O(1). If you want to add it to the end of the list, it's
O(n) because you have to traverse the entire list to the end.
There's no faster way to get to the end of a singly linked list
than to follow the pointers from the head of the list.*/
node *listInsert(node* root, node *x){
    x->next = root;
    cout<<x<<endl;
    return x;
}

node *searchList(node *head, int key){
    node *x = head;
    bool found = false;
    while(!found && x != NULL){
        if(x->key == key)
            found = true;
        else
            x = x->next;
    }
    return x;
}

