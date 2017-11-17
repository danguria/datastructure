#ifndef _STACK_H_
#define _STACK_H_

#include <algorithm>
#include "Bag.h"
#include "utils.h"

template <class T>
class Stack : public Bag<T>
{ // A finite ordered list with zero or more elements.
    public:
        // Create an empty stack whost initial capacity is stackCapacity.
        Stack(int stackCapacity = 10);

        ~Stack();

        // Return top element of stack.
        T& Top() const;

        // Delete the top element of the stack.
        void Pop();

        // Throw an exception when this function is called
        // because we don't want this function is called.
        T& Element() const;

};

// Constructure for Stack calls constructor for Bag.
template <class T>
Stack<T>::Stack(int stackCapacity) : Bag<T>(stackCapacity) {}

// Destructor for Bag is automatically called when Stack
// is destroyed. This ensures that array is deleted.
template <class T>
Stack<T>::~Stack() {}

template <class T>
inline T& Stack<T>::Top() const {
    if (this->IsEmpty()) throw "Stack is empty";
    return this->array[this->top];
}

template <class T>
void Stack<T>::Pop() {
    if (this->IsEmpty()) throw "Stack is empty, cannot delete";
    this->array[this->top--].~T();
}

template <class T>
inline T& Stack<T>::Element() const {
    throw "Function Element() cannot be called.";
}

#endif
