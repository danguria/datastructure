#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "utils.h"
#include "Bag.h"

template <class T>
class Queue : public Bag<T>
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

        // Given below is not used in Queue.
        int Size() const;
        T& Element() const;

    private:
        int front,    // one counterclockwise from front
            rear;     // array position of rear element
};


template <class T>
Queue<T>::Queue(int queueCapacity) : Bag<T>(queueCapacity) {
    front = rear = 0;
}

template <class T>
Queue<T>::~Queue() {}

template <class T>
inline bool Queue<T>::IsEmpty() const {
    return front == rear;
}

template <class T>
inline T& Queue<T>::Front() const {
    if (IsEmpty()) throw "Queue is empty. No front element.";
    return this->array[(front + 1) % this->capacity];
}

template <class T>
inline T& Queue<T>::Rear() const {
    if (IsEmpty()) throw "Queue is empty. No rear element.";
    return this->array[rear];
}

template <class T>
void Queue<T>::Push(const T& item) {
    // if the queue is full, double it.
    if ((rear + 1) % this->capacity == front) {
        T* newQueue = new T[2 * this->capacity];

        // Copy from queue to newQueue
        int start = (front + 1) % this->capacity;
        if (start < 2) { // no wrap around
            std::copy(this->array + start,
                    this->array + this->capacity -1,
                    newQueue);
        } else { // wrap around
            std::copy(this->array+ start,
                    this->array+ this->capacity,
                    newQueue);
            std::copy(this->array,
                    this->array+ rear + 1,
                    newQueue + this->capacity - start);
        }

        // Switch to newQueue
        front = 2 * this->capacity - 1;
        rear = this->capacity - 2;
        this->capacity *= 2;
        delete [] this->array;
        this->array= newQueue;
    }

    rear = (rear + 1) % this->capacity;
    this->array[rear] = item;
}

template <class T>
void Queue<T>::Pop() {
    if (IsEmpty()) throw "Queue is empty, cannot delete.";

    front = (front + 1) % this->capacity;
    this->array[front].~T();
}

template <class T>
inline int Queue<T>::Size() const {
    throw "Function Size() cannot be used in Queue";
}

template <class T>
inline T& Queue<T>::Element() const {
    throw "Function Element() cannot be used in Queue";
}

#endif
