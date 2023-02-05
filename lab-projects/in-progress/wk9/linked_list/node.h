#ifndef NODE_H
#define NODE_H

#include<cstdlib>
using namespace std;

class Node {
    public:
        Node(int val = 0, Node* nPtr = NULL);
        void setData(int val) { data = val; }
        void setLink(Node* nPtr) { link = nPtr; }
        int getData() const { return data; }
        Node* getLink() const { return link; }
    private:
        int data;
        Node* link;
};

#endif