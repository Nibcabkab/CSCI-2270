#ifndef CNODE_H
#define CNODE_H


class CNode
{
    public:
        CNode(int value, int arraySize);
        virtual ~CNode();
        CNode *getNext();
        CNode *getPrevious();
        int getX();
        int getArrayData(int);
        void setNext(CNode*);
        void setPrevious(CNode*);
        void setArrayData(int, int);
        void setX(int);
    protected:
    private:
        int x;
        CNode *next;
        CNode *previous;
        int *dataArray;//pointer, set size later in the constructor
        int maxSize;//number of elements in the array
};

#endif // CNODE_H
