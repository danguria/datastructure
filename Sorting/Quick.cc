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
void QuickSort(T* a, const int left, const int right)
{
    // Sort a[left:right] into nondecreasing order.
    // a[left] is arbitrarily chosen as the pivot.
    // Variables i and j are used to partition the subarray so that
    // at any time a[m] <= pivot, m < i, and a[m] >= pivot, m > j.
    // It is assumed that a[left] <= a[right + 1]
    
    if (left >= right) return;

    int i = left;
    int j = right + 1;
    int pivot = a[left];

    do
    {
        do i++; while (a[i] < pivot);
        do j--; while (a[j] > pivot);
        cout << "i: " << i << ", j: " << j << endl;
        if (i < j) swap(a[i], a[j]);
    } while (i < j);

    swap(a[left], a[j]);

    QuickSort(a, left, j - 1);
    QuickSort(a, j + 1, right);

}

int main()
{
    int test[] = {0, 5, 4, 3, 2, 1};
    QuickSort(test, 1, 5);
    Display(test, 5);
    return 0;
}
