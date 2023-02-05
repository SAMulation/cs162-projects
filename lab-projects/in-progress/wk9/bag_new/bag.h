#ifndef BAG_H
#define BAG_H

class Bag {
    public:
        static const int CAPACITY = 30;
        Bag() : used(0) {} // inline function definition
        void insert(int); // insert a number into the Bag
        int getValue(int) const; // return value at element number passed in
        int size() const { return used; }
        int showSum() const; // computes and returns the sum of values in the ArrayBag
        int largest() const; // finds and returns the largest value in the ArrayBag
        bool operator == (Bag); // returns true if the two ArrayBags have the same number
                                // of items in the bags
        void removeAll(int); // removes all copies of the target value in the ArrayBag
    private:
        int data[CAPACITY];
        int used;
};

#endif