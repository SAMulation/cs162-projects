#include "linkedList.h"

LinkedList::LinkedList(Node* hPtr, int nodes) {
    headPtr = hPtr;
    numNodes = nodes;
}

void LinkedList::insert(int val) {
    Node* newNode = new Node(val, headPtr);
    headPtr = newNode;
    numNodes++;
}