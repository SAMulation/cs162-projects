#include "bag.h"
#include <cassert>
using namespace std;

void Bag::insert(int value) {
    assert(used < CAPACITY);
    data[used] = value;
    used++;
    return;
}

int Bag::getValue(int element) const {
    assert(element >= 0 && element < used);
    return data[element];
}