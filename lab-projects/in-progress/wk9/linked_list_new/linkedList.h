#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
  public:
    LinkedList(Node* hPtr = NULL, int nodes = 0);
    void insert(int val);
    int get_second() const;
    void add_multiple(int entry, int how_many);
    bool same_firstTwo(LinkedList list1, LinkedList list2);
    Node* getHeadPtr() const { return headPtr; }
  private:
    Node* headPtr; 
    int numNodes;
};

#endif