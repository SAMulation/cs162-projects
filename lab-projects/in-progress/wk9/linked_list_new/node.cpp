#include "node.h"

Node::Node(int val, Node* nPtr) {
  data = val;
  link = nPtr;
}