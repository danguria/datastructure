#ifndef _BAG_H_
#define _BAG_H_

#include <algorithm>
#include "utils.h"

template <class T>
class Bag
{
    public:
        Bag(int bagCapacity = 10);
        ~Bag ();

        // return number of elements in bag
        int Size() const;

        // return true if the bag is empty; false otherwise
        bool IsEmpty() const;

        // return an element that is in the bag
        T& Element() const;

        // insert an integer into the bag
        void Push(const T&);

        // delete an interger from the bag
        void Pop();

    private:
        T *array;
        int capacity;
        int top;
};

template <class T>
inline int Bag<T>::Size() const { return top + 1; }

template <class T>
inline bool Bag<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Bag<T>::Element() const {
    if (IsEmpty()) throw "Bag is empty";
    return array[0];
}


template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity) {
    if (capacity < 1) throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag() { delete [] array; }

template <class T>
void Bag<T>::Push(const T& x) {
    if (top + 1 == capacity) ChangeSize1D(array, capacity, 2 * capacity);
    capacity *= 2;

    array[++top] = x;
}

template <class T>
void Bag<T>::Pop() {
    if (IsEmpty()) throw "Bag is empty, cannot delete";
    int deletPos = top / 2;

    std::copy(array + deletPos + 1, array + top + 1, array + deletPos);
    top--;
}

#endif
