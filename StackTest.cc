#include <iostream>
#include "Stack.h"
using namespace std;

int main() {


    try {
        Stack<int> s(0);
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    Stack<string> s(5);

    try {
        s.Top();
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    

    try {
        for (int i = 0; i < 10; i++) {
            s.Push(to_string(i));
            cout << s.Top() << endl;
        }

        for (int i = 0; i < 11; i++) {
            cout << s.Top() << endl;
            s.Pop();
        }

    } catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        s.Pop();
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    cout << "size: " << s.Size() << endl;

    return 0;
}
