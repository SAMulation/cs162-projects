#ifndef BAG_H
#define BAG_H

class Bag {
public:
    static const int CAPACITY = 30;
    Bag() : used(0) {} // inline function definition
    void insert(int); // insert a number into the Bag
    int getValue(int) const; // return value at element number passed in
    int size() const { return used; }
private:
    int data[CAPACITY];
    int used;
};

#endif