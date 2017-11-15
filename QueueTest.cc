#include <iostream>
#include "Queue.h"
using namespace std;
int main() {

    Queue<int> q;

    try {
        // check empty
        //q.Pop();

        // add item 5 times and pop 4 time
        q.Push(1);
        q.Push(2);
        q.Push(3);
        q.Push(4);
        q.Push(5);
        q.Pop();
        q.Pop();
        q.Pop();
        q.Pop();
        q.Push(6);
        q.Push(7);
        q.Push(8);
        q.Push(9);
        q.Push(10);
        q.Push(11);
        q.Push(12);
        q.Push(13);
        q.Push(14);
        cout << q.Front() << endl; // 5
        cout << q.Rear() << endl;  // 14
        // make queue full. We expect the queue is doubled
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    return 0;
}
