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

int LinkedList::get_second() const {
  if (headPtr == NULL || headPtr->getLink() == NULL)
    return -1;
  return headPtr->getLink()->getData();
}

void LinkedList::add_multiple(int entry, int how_many) {
  for (int i = 0; i < how_many; i++)
    insert(entry);
}

bool LinkedList::same_firstTwo(LinkedList list1, LinkedList list2) {
  if (list1.headPtr == NULL || list2.headPtr == NULL)
    return false;
  if (list1.headPtr->getData() != list2.headPtr->getData())
    return false;
  if (list1.headPtr->getLink() == NULL || list2.headPtr->getLink() == NULL)
    return false;
  return list1.headPtr->getLink()->getData() == list2.headPtr->getLink()->getData();
}