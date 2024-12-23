#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "Node.h"


class Linked_List
{
  private: 
    Node * front;
    Node * back;
    int count;

  public:
    Linked_List();
    Linked_List(Node *, Node*);
    virtual ~Linked_List();

    void insertAfter(Node *, Node *);
    void insertBeginning(Node *);
    int remove(Node *&);


    void display();
    void insertAfterInt(Node *, int);
    int positionValue(int);
    Node * intFind(int);
    int positionFind(int);
    int removeInt(int);
    int removePosition(int);
    bool valueSearch(int);

    Node* getFront();
    Node* getBack();
    int getCount();

    void setFront(Node*);
    void setBack(Node*);
    void setCount(int);
};
#endif