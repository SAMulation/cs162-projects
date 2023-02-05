#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
 public:
    LinkedList(Node* hPtr = NULL, int nodes = 0);
    void insert(int val);
    Node* getHeadPtr() const { return headPtr; }
 private:
    Node* headPtr; 
    int numNodes;
};

#endif