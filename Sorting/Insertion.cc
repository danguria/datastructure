#include <iostream>
using namespace std;

template <class T>
void Display(T* a, int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << ", ";
    cout << endl;
}

template <class T>
void Insert(const T& e, T* a, int i)
{
    // Insert e into the ordered sequence a[1:i] such that
    // the resulting sequence a[1:i+1] is also ordered.
    // The array a must have sapce allocated for at lease
    // i + 2 elements.

    a[0] = e; // why this line is required?

    while (e < a[i])
    {
        a[i+1] = a[i];
        i--;
    }

    a[i+1] = e;
}

template <class T>
void InsertionSort(T* a, const int n)
{
    // Sort a[1:n] into nondecreasing order.
    if (n < 2) return;

    for (int i = 2; i <= n; i++) {
        T temp = a[i];
        Insert(temp, a, i-1);
        Display(a, n);
    }
}


int main()
{

    int test[] = {0, 5, 4, 3, 2, 1};

    InsertionSort(test, 5);

    return 0;
}
