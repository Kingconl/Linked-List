#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
  private: 
    Node * previous;
    Node * next;
    int contents;

  public:
    Node();
    Node(Node *, Node*, int);
    virtual ~Node();

    Node* getNext();
    Node* getPrevious();
    int getContents();

    void setNext(Node*);
    void setPrevious(Node*);
    void setContents(int);
};

#endif