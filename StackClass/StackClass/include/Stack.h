#include <iostream>
#ifndef STACK_H
#define STACK_H

//this is where Stack methods, variables are defined
//Don't use namesppace std for header files.

class Stack
{
    public:
        Stack(int); //Size of the array
        virtual ~Stack();//Destructor
        //What happens to the stack
        //We can push we can pop an item on to the stack
        void push(std::string);
        std::string pop();//pop
        //is the stack full
        //is the stack empty, since we don't want to pop from an empty stack
        bool isStackFull();
        bool isStackEmpty();
    protected:
    private:
        int top;// Top of the stack, changes when we push and pop
        int maxStack;//size of the stack
        std::string *items;//Set size when the constructor is called

};

#endif // STACK_H
