#include "Bag.h"
#include <algorithm>


template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
    if (newSize < 0) throw "New length must be >= 0";

    T* temp = new T[newSize];
    int number = std::min(oldSize, newSize);
    std::copy(a, a + number, temp);
    delete [] a;
    a = temp;
}


Bag::Bag(int bagCapacity) : capacity(bagCapacity) {
    if (capacity < 1) throw "Capacity must be > 0";
    array = new int[capacity];
    top = -1;
}

Bag::~Bag() { delete [] array; }

void Bag::Push(const int x) {
    if (top + 1 == capacity) ChangeSize1D(array, capacity, 2 * capacity);
    capacity *= 2;

    array[++top] = x;
}

void Bag::Pop() {
    if (IsEmpty()) throw "Bag is empty, cannot delete";
    int deletPos = top / 2;

    std::copy(array + deletPos + 1, array + top + 1, array + deletPos);
    top--;
}
