#include <iostream>
#include "Node.h"
#include "Linked_List.h"
using namespace std;

Linked_List:: Linked_List()
{
  count = 0;
  front = nullptr;
  back = nullptr;
  return;
}

Linked_List:: ~Linked_List()
{
  //dtor
}

Linked_List:: Linked_List(Node * _front, Node * _back)
{
  front = _front;
  back = _back;
  count = 1;//since the linked list isnt empty, we have to set it too 1.
  return;
}

Node* Linked_List::getFront()
{
  return front;
}

Node* Linked_List::getBack()
{
  return back;
}

int Linked_List::getCount()
{
  return count;
}



void Linked_List::setFront(Node* _front)
{
  front = _front;
  return;
}

void Linked_List::setBack(Node* _back)
{
  back = _back;
  return;
}


void Linked_List::setCount(int _count)
{
  count = _count;
  return;
}

int Linked_List::remove(Node *& ptr_nodeToBeRemoved)
{
  if (ptr_nodeToBeRemoved == nullptr)//prevents crashes as well as more efficient
  {
    throw runtime_error("Can not remove an empty Node.");
  }
  
  Node * iterator = front; 
  for(int i = count; i > 0 ; i++)//for loop that goes through every value
    {
      if(iterator == ptr_nodeToBeRemoved)
      {//we only remove if the node exisits within the list
        int removeValue = ptr_nodeToBeRemoved->getContents();
      
        if(ptr_nodeToBeRemoved == front) 
        {
          if(ptr_nodeToBeRemoved->getNext() == nullptr)
          {
            front = nullptr;//since if the one next to the front is null, then there is only 1 node in the linked list. And if we remove the only node, both front and back with be empty/nulls
            back = nullptr;
          }
          else
          {
            ptr_nodeToBeRemoved->getNext()->setPrevious(nullptr);//since its getting deleted, we need to set it to nullptr
            front = ptr_nodeToBeRemoved->getNext();
          }
        }
        else if(ptr_nodeToBeRemoved == back)
        {
          ptr_nodeToBeRemoved->getPrevious()->setNext(nullptr);//since its getting deleted, we need to set it to nullptr
          back = ptr_nodeToBeRemoved->getPrevious();
        }
        else
        {
          ptr_nodeToBeRemoved->getPrevious()->setNext(ptr_nodeToBeRemoved->getNext());
          ptr_nodeToBeRemoved->getNext()->setPrevious(ptr_nodeToBeRemoved->getPrevious());
        }
        delete ptr_nodeToBeRemoved;
        ptr_nodeToBeRemoved = nullptr;
        count --;
        return removeValue;
        }
      iterator = iterator->getNext();
    }
   throw runtime_error("Can not remove a node that does not exist within Linked List.");//if it does not exist, we throw an error
}

void Linked_List::insertAfter(Node * ptr_NodeToInsert, Node * ptr_afterThisNode)
{
  
  if( ptr_NodeToInsert == nullptr)//prevent crashes
  {
    throw runtime_error("Can not insert an null.");
  }
  else if(ptr_afterThisNode == nullptr)
  {
    insertBeginning(ptr_NodeToInsert);//if its null, we insert to the start
  }
  else if(ptr_afterThisNode != back)//if its not the back, we have to mkae sure all 3 of them are properlly set
  {
    ptr_afterThisNode->getNext()->setPrevious(ptr_NodeToInsert);
    ptr_NodeToInsert->setNext(ptr_afterThisNode->getNext());
    ptr_NodeToInsert->setPrevious(ptr_afterThisNode);
    ptr_afterThisNode->setNext(ptr_NodeToInsert);
    
    count ++;
  }
  else{//if its the back then we just worry about back and the new back
    back->setNext(ptr_NodeToInsert);
    ptr_NodeToInsert->setNext(nullptr);
    ptr_NodeToInsert->setPrevious(back);
    back = ptr_NodeToInsert;

      
    count ++;
  }
  return;
}

void Linked_List::insertBeginning(Node * ptr_NodeToInsert)
{
  if (front == nullptr)// 0 values
  {
    back = ptr_NodeToInsert;//since both back and front's values are the same
    front = ptr_NodeToInsert;
    front->setPrevious(nullptr);//both have to front or back
    back->setNext(nullptr);
    back->setPrevious(nullptr);
    front->setNext(nullptr);//incase they were pointed somewhere else before
  }
  else if(front->getNext() == nullptr)//1 value
  {
    front = ptr_NodeToInsert;//new front
    front->setNext(back);
    back->setPrevious(front);
    front->setPrevious(nullptr);
    back->setNext(nullptr);
  }
  else
  {
    front->setPrevious( ptr_NodeToInsert);
    ptr_NodeToInsert->setNext(front);
    ptr_NodeToInsert->setPrevious(nullptr);
    front = ptr_NodeToInsert;//sets the old front to have its previous pointed at the new front and sets the new fronts previous to null and next to the old front
  }
  count ++;
  return;
}

void Linked_List::display()
{
  if (count == 0)
  {
    cout << "Empty Linked List" << endl;
  }
  else
  { 
    Node * iterator = front;
    do{//we can use a do loop as an empty queue will never be a case because of the if
      cout << iterator->getContents() << endl;
        iterator = iterator->getNext();
    }while (iterator != nullptr);//we stop displaying when there is no next. 
  }
}

int Linked_List::positionValue(int position)
{

  if(position > count or position < 0)//above the number in the list or negative
  {
    throw runtime_error("Position outside of lists current parameters");
  }
    Node * iterator = front;


  for(int i = 0; i < position ; i++)//find the node at the position
    {
      iterator = iterator->getNext();
    }


  return iterator->getContents();
}

void Linked_List::insertAfterInt(Node * ptr_NodeToInsert, int desiredInt)
{
  Node * desiredLocaton = intFind(desiredInt);//find the right position
  insertAfter(ptr_NodeToInsert,desiredLocaton);
  return;
}

int Linked_List::removeInt(int intToRemove)
{
  Node * desiredLocaton = intFind(intToRemove);//find the right position

  remove(desiredLocaton);
  return intToRemove;
}

int Linked_List::removePosition(int intToRemove)
{
    Node * iterator = front;
  if(intToRemove > count or intToRemove<0)//if its too big or negative
  {
    throw runtime_error("Invalid position");
  }
  for(int i = intToRemove; i > 0 ; i--)// >1 since we want it to run zero times if its zero and once if its 1
    {
      iterator = iterator->getNext();
    }
    remove(iterator);
  return intToRemove;
}

bool Linked_List::valueSearch(int value)
{
  Node * iterator = front;
  for(int i = count; i > 0 ; i--)// >1 since we want it to run zero times if its zero and once if its 1
  {
    if(iterator->getContents() == value)//of it is in there its true
    {
      return true;
    }
    iterator = iterator->getNext();
  }
  return false;
}

Node * Linked_List::intFind(int value)
{
  Node * iterator = front;
  for(int i = count; i > 0 ; i--)// >1 since we want it to run zero times if its zero and once if its 1
  {
    if(iterator->getContents() == value)
    {
      return iterator;
    }
    iterator = iterator->getNext();
  }
  throw runtime_error("Value does not exist within the Linked List");
}

int Linked_List::positionFind(int value)
{
  Node * iterator = front;
  for(int i = 0; i < count ; i++)
  {
    if(iterator->getContents() == value)//if it is the right value, return the position
    {
      return i;
    }
    iterator = iterator->getNext();
  }
  throw runtime_error("Value does not exist within the Linked List");//if nothing, its an error 

}
