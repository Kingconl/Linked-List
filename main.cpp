/*  Author: Connor Liu
    Program Description: A program that demostrates a stacked list. 
    Date Created: 04/05/2024
    Date Modified: 06/05/2024

    Replit Link: https://replit.com/join/xhmzfvwgbw-connorliu2
*/
// =================== Preprocessor Commands =========================

#include <iostream>
#include "Node.h"
#include "Linked_List.h"
using namespace std;

// ===================  Function Definitions  ==========================

int main() {
  Linked_List test;
  Linked_List test2;
  Linked_List test3;
  Node * node1 = new Node(nullptr, nullptr, 1);
  Node * node2 = new Node(nullptr, nullptr, 2);
  Node * node3 = new Node(nullptr, nullptr, 3);
  Node * node4 = new Node(nullptr, nullptr, 4);
  Node * node5 = new Node(nullptr, nullptr, 5);
  Node * node6 = new Node(nullptr, nullptr, 6);
  Node * node7 = new Node(nullptr, nullptr, 7);
  Node * node8 = new Node(nullptr, nullptr, 8);
  Node * node9 = new Node(nullptr, nullptr, 9);
  Node * node10 = new Node(nullptr, nullptr, 10);
  Node * node11 = new Node(nullptr, nullptr, 11);
  Node * node12 = new Node(nullptr, nullptr, 12);
 

 
  

cout << "Add to an empty list\n";
  try{
    test.insertAfter(node1, nullptr);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test.display();
cout << "-----------------------------------------------" << endl; 
  cout << "Add to the front of a list containing one Node \n";
  try{
    test.insertAfter(node2, nullptr);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  
  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Add to the back of a list containing one Node \n";
  cout << "removed: " << test.remove(node2) << endl;
  try{
    test.insertAfter(node3, node1);

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test.display();
  
  cout << "-----------------------------------------------" << endl;
  cout << "Add to the front of a list containing multiple Nodes\n";
  try{
   test.insertAfter(node4, nullptr);

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Add to the back of a list containing multiple Nodes \n";
  try{
    test.insertAfter(node5, node3);

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Add to the interior of a list containing multiple Node\n";
  try{

   test.insertAfter(node6, node1);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Remove from an empty list \n";

  try{
    cout << "removed: " << test2.remove(node3) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  cout << "-----------------------------------------------" << endl;
  cout << "Remove from the front of a list containing one Node \n";

  try{
    test2.insertAfter(node7, nullptr);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }


  test2.display();

  try{
    cout << "removed: " << test2.remove(node7) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  test2.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Remove from the end of a list containing one Node \n";

  try{
    test2.insertAfter(node8, nullptr);

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test2.display();

  try{
    cout << "removed position: " << test2.removePosition(0) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  test2.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Remove the front of a list containing multiple Nodes \n";

  try{
    cout << "removed: " << test.remove(node4) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
    test.display();


      cout << "-----------------------------------------------" << endl;
      cout << "Remove the back of a list containing multiple Nodes \n"; 
  
  try{
    cout << "removed: " << test.remove(node5) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Remove from the interior of list containing multiple Nodes\n"; 
  try{
    cout << "removed: " << test.remove(node6) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Search an empty list\n"; 

  cout << boolalpha;// makes cout false/true and not 0s and 1s
  cout << test3.valueSearch(0) << endl;
  test3.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Search for an value that is in the list\n"; 
  try{
    test.insertAfter(node9, nullptr);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  
  try{
    test.insertAfter(node10, node9);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  
  try{

    test.insertAfter(node11, node3);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }
  
  try{
    test.insertAfter(node12, node3);
  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }




  cout << test.valueSearch(1) << endl;
  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Search for an value that is not in the list.\n"; 
  cout << test.valueSearch(100) << endl;
  test.display();

  cout << "-----------------------------------------------" << endl;
  cout << "Uses the index function to return the 3rd value in the list (your list will need at least 3 values)\n"; 


  try{
   cout << "The value at position 2:" <<  test.positionValue(2) << endl;//third value is at second position since we start counting at 0;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  cout << "-----------------------------------------------" << endl;
  cout << "Use the find Index function to determine the position of a value in the list\n"; 


  try{
   cout << "The position at value 12:" <<  test.positionFind(12) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }

  cout << "-----------------------------------------------" << endl;
  cout << "Use the find Index function to determine the position of a value not in the list.\n"; 


  try{
   cout << "The position at value 100:" <<  test.positionFind(100) << endl;

  }catch(exception& e)
    {
      cerr << e.what() << endl;
    }




  

  

  


  
  
  return 0;
}