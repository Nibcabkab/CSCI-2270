#ifndef CNODE_H
#define CNODE_H
//these are guards on the includes. We only want to define something
//one time, more than once causes an error

//this defines our interface. The implementation is handled separately
class CNode
{
    private:
        int x;
        CNode *next;
        CNode *previous;
        int *dataArray; //each node has an array of data
        int maxSize; //maximum size of dataArray
    public:
        CNode(int, int);
        virtual ~CNode();
        CNode *getNext();
        CNode *getPrevious();
        int getX();
        int getArrayData(int); //return array data for specified index

        void setNext(CNode*);
        void setPrevious(CNode*);
        void setArrayData(int, int);
        void setX(int);

};

#endif // CNODE_H
