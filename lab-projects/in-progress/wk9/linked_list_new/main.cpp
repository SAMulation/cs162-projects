/*************************
 * Name: Linked List Class from Class - Updated
 * Author: Sam Sarsten
 * Date: 02-04-2023
 * Purpose: Linked List class from Making CS Easy channel
 *          with the added functions from assn
 * NOTE: If using VS Code, use the following 2 commands to run:
 *       g++ -o output_file main.cpp node.cpp linkedList
 *       ./output_file
**************************/

#include "linkedList.h"
#include <iostream>
using namespace std;

int main() {
  LinkedList myList;
  myList.insert(2);
  myList.insert(5);
  myList.add_multiple(3, 3);

  cout << "Second element in myList: " << myList.get_second() << endl;

  LinkedList myOtherList;
  myOtherList.insert(2);
  myOtherList.insert(5);
  myOtherList.add_multiple(3, 3);
  cout << "Lists have same first two elements: " << (myList.same_firstTwo(myList, myOtherList) ? "Yes" : "No") << endl;

  return 0;
}
