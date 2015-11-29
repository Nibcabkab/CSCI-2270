#include <iostream>

using namespace std;

void arrayTest(int a[], int length){
    for(int i = 0; i <length; i++){
        a[i] = i;
    }
}
void allocateMemory(){
//show a bad thing to do
//allocate memory
//this is a memory leak
int *a = new int[10000];
}
int* arrayReturnFunction(){
    int *r = new int[5];
    return r;
}
int main(){
    //Makes a fixed array size
    //Again arrays in c++ are pointers and because of that we can change its values outside the function its called in
    int myArray[10];
    arrayTest(myArray, 10);
    for(int i =0; i<10; i++){
        cout<<myArray[i]<<endl;
    }
    //dynamically allocated memory
    //create array on heap, this is dynamically allocated memory
    int *ptrArray = new int[10];
    arrayTest(ptrArray,10);
    for(int i=0; i<10; i++){
        cout<<ptrArray[i]<<endl;
    }
    //if memory is explicitly allocated we need to explicitly deallocate
    delete []ptrArray;
    cout<<"array deallocated"<<endl;
    for (int i=0;i<10;i++)
        //works but will probably get garbage
        cout<<ptrArray[i]<<endl;
    //pointers
    //give a pointer to a new integer in memory and create a pointer to it
    int *ptrx = new int;
    cout<<"address of *ptrx"<<ptrx<<endl;
    //dereferencing: if you want to see the value
    cout<<"value of ptrx"<<*ptrx<<endl;

    int* ptrc = arrayReturnFunction();
    return 0;
}

