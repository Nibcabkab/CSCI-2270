#include <iostream>

using namespace std;

struct item{
    string name;
    int price;
    bool for_sale;
};
void changeStructValue(item *ptrItem){//Again pointers can have any data type since they are a memory address
    ptrItem->price = 20;
}
int main(){
    //pointers
    int* a = new int[5];
    //free memory
    delete[] a;
    int b = 5;
    int *ptrB = &b;
    cout<<"address of b "<<&b<<endl;
    cout<<"*ptrB points to "<<ptrB<<endl;
    //Dereferencing with *
    cout<<"value that *ptrB points to "<<*ptrB<<endl;
    item myItem;
    myItem.for_sale = true;
    myItem.name = "chicken";
    myItem.price = 10;
    item *ptrItem = &myItem;
    //Access members with a complex data type then you use the ->
    //-> = (*ptrItem).price
    cout<<ptrItem->price<<endl;
    //pointers can have any date type
    changeStructValue(ptrItem);
    cout<<ptrItem->price<<endl;
}
