#include <iostream>

using namespace std;
int findItem(int A[], int v, int length){
    int index = -1;
    for(int i =0; i<length; i++){
        if(A[i]==v)
            index = i;
    }
        return index;
}

int main(){
    int A[5] = {45,34,23,54,1};
    int i = findItem(A,34,5);
    cout<<i<<endl;
}

