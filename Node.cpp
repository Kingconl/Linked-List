#include <iostream>
#include "Node.h"
using namespace std;

Node:: Node()
{
  contents = 0;
  next = nullptr;
  previous = nullptr;
  return;
}

Node:: ~Node()
{
  //dtor
}

Node:: Node(Node * _next, Node * _previous, int _contents)
{
  contents = _contents;
  next = _next;
  previous = _previous;
  return;
}

Node* Node::getNext()
{
  return next;
}

Node* Node::getPrevious()
{
  return previous;
}

int Node::getContents()
{
  return contents;
}



void Node::setNext(Node* _next)
{
  next = _next;
  return;
}

void Node::setPrevious(Node* _previous)
{
  previous = _previous;
  return;
}


void Node::setContents(int _contents)
{
  contents = _contents;
  return;
}
