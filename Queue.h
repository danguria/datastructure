#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "utils.h"

template <class T>
class Queue
{ // A finite ordered list with zero or more elements.
    public:
        // Create an empty queue whose initial capacity is queueCapacity.
        Queue(int queueCapacity = 10);

        // Destroy the queueu
        ~Queue();

        // If number of elements in the queue is 0, return true else return false.
        bool IsEmpty() const;

        // Return the element at the front of the queue.
        T& Front() const;

        // Return the element at the rear of the queue.
        T& Rear() const;

        // Insert item at the rear of the queue.
        void Push(const T&);

        // Delete item at the front of the queue.
        void Pop();

    private:
        T* queue;     // array for queue elements.
        int front,    // one counterclockwise from front
            rear,     // array position of rear element
            capacity; // capacity of queue array
};


template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity) {
    if (queueCapacity < 1) throw "Capacity mubst be > 0";

    queue = new T[capacity];
    front = rear = 0;
}

// TODO: Is destructor necessary?
template <class T>
Queue<T>::~Queue() { delete [] queue; }

template <class T>
inline bool Queue<T>::IsEmpty() const {
    return front == rear;
}

template <class T>
inline T& Queue<T>::Front() const {
    if (IsEmpty()) throw "Queue is empty. No front element.";
    return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const {
    if (IsEmpty()) throw "Queue is empty. No rear element.";
    return queue[rear];
}

template <class T>
void Queue<T>::Push(const T& item) {
    // if the queue is full, double it.
    if ((rear + 1) % capacity == front) {
        T* newQueue = new T[2 * capacity];

        // Copy from queue to newQueue
        int start = (front + 1) % capacity;
        if (start < 2) { // no wrap around
            std::copy(queue + start, queue + capacity -1 , newQueue);
        } else { // wrap around
            std::copy(queue + start, queue + capacity, newQueue);
            std::copy(queue, queue + rear + 1, newQueue + capacity - start);
        }

        // Switch to newQueue
        front = 2 * capacity - 1;
        rear = capacity - 2;
        capacity *= 2;
        delete [] queue;
        queue = newQueue;
    }

    rear = (rear + 1) % capacity;
    queue[rear] = item;
}

template <class T>
void Queue<T>::Pop() {
    if (IsEmpty()) throw "Queue is empty, cannot delete.";

    front = (front + 1) % capacity;
    queue[front].~T();
}


#endif
