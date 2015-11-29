#include <iostream>

class Stack{
	int emptyStack;
	int maxStack;
	int top;
	std::string* items;

	public:
	Stack(int);
	~Stack();
	void push(std::string);
	std::string pop();
	bool isEmpty();
	bool isFull();

};

