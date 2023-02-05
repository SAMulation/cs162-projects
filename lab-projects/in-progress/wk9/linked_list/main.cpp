/*************************
 * Name: Linked List Class from Class
 * Author: Sam Sarsten
 * Date: 02-04-2023
 * Purpose: Linked List class from Making CS Easy channel
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

    Node* current = myList.getHeadPtr();
    while (current != NULL)
    {
        cout << current->getData() << " ";
        current = current->getLink();
    }
    cout << endl;

    return 0;
}