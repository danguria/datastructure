#include <iostream>
#include "Bag.h"
using namespace std;

int main() {
    Bag bag;

    cout << "Current size: " << bag.Size() << endl;
    for (int i = 0; i < 15; i++)
        bag.Push(i);

    for (int i = 0; i < 10; i++)
        bag.Pop();

    cout << "Element: " << bag.Element() << endl;
    return 0;
}
