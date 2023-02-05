#include "bag.h"
#include <cassert>

void Bag::insert(int newValue) {
    assert(used < CAPACITY);
    data[used++] = newValue;
    return;
}

int Bag::getValue(int element) const {
    assert(element >= 0 && element < used);
    return data[element];
}

int Bag::showSum() const {
    int sum = 0;
    for (int i = 0; i < used; i++) {
        sum += data[i];
    }
    return sum;
}

int Bag::largest() const {
    int largest = data[0];
    for (int i = 1; i < used; i++) {
        if (data[i] > largest) {
            largest = data[i];
        }
    }
    return largest;
}

bool Bag::operator == (Bag otherBag) {
    if (used != otherBag.used) {
        return false;
    }
    for (int i = 0; i < used; i++) {
        if (data[i] != otherBag.data[i]) {
            return false;
        }
    }
    return true;
}

void Bag::removeAll(int target) {
    int newUsed = 0;
    for (int i = 0; i < used; i++) {
        if (data[i] != target) {
            data[newUsed++] = data[i];
        }
    }
    used = newUsed;
    return;
}