#include <iostream>
#include "Bag.h"
using namespace std;

int main() {
    Bag<int> bag;

    try {
        bag.Pop();
        cout << "Current size: " << bag.Size() << endl;
        for (int i = 0; i < 15; i++)
            bag.Push(i);

        for (int i = 0; i < 10; i++)
            bag.Pop();

        cout << "Element: " << bag.Element() << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    return 0;
}
