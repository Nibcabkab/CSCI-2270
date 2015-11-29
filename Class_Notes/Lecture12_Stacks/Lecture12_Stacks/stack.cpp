#include "stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int size){
	maxStack = size;
	emptyStack = -1;
	top = emptyStack;
	items = new std::string[maxStack];
}

Stack::~Stack(){
	delete[] items;
}

void Stack::push(string c){
	top++;
	items[top] = c;
}
string Stack::pop(){
	string p = items[top];
	top--;
	return p;
}

bool Stack::isFull(){
	if(top+1 == maxStack)
		return true;
	else
		return false;
}

bool Stack::isEmpty(){
	if(top == emptyStack)
		return true;
	else
		return false;
}
