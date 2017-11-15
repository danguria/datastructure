#ifndef _STACK_H_
#define _STACK_H_

#include <algorithm>
#include "utils.h"

template <class T>
class Stack
{ // A finite ordered list with zero or more elements.
    public:
        // Create an empty stack whost initial capacity is stackCapacity.
        Stack(int stackCapacity = 10);

        ~Stack();

        // If number of elements in the stack is 0, return true, else return false.
        bool IsEmpty() const;

        // Return top element of stack.
        T& Top() const;

        // Return the number of element in stack.
        int Size() const;

        // Insert item into the top of the stack.
        void Push(const T&);

        // Delete the top element of the stack.
        void Pop();

    private:
        int capacity;
        int top;
        T* stack;

};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity) {
    if (capacity < 1 ) throw "Stack capacity must be > 0";
    stack = new T[stackCapacity];
    top = -1;
}

template <class T>
Stack<T>::~Stack() { delete [] stack; }

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const {
    if (IsEmpty()) throw "Stack is empty";
    return stack[top];
}

template <class T>
inline int Stack<T>::Size() const { return top + 1; }

template <class T>
void Stack<T>::Push(const T& item) {
    if (top + 1 == capacity) {
        ChangeSize1D(stack, capacity, 2 * capacity);
        capacity *= 2;
    }

    stack[++top] = item;
}

template <class T>
void Stack<T>::Pop() {
    if (IsEmpty()) throw "Stack is empty, cannot delete";
    stack[top--].~T();
}


#endif
