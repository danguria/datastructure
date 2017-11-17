#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

    Bag<int> b(3);
    Stack<int> s(3);

    // use Bag::Push
    b.Push(1); b.Push(2); b.Push(3);

    // Stack::Push not defined, so use Bag::Push.
    s.Push(1); s.Push(2); s.Push(3);

    b.Pop(); // use Bag::Pop, which calls Bag::IsEmpty

    // uses Stack::pop, which calls Bag::IsEmpty because IsEmpty has not been redefined in Stack.
    s.Pop();
    s.Element();

    return 0;
}
