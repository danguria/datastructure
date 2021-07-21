#include <iostream>
using namespace std;

template <class T>
void Display(T* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << endl;
}

    template <class T>
void Merge(T* initList, T* mergedList, const int l, const int m, const int n)
{
    // initList[l:m] and initList[m + 1:n] are sorted lists.
    // They are merged to obtain the sorted list mergedList[l:n]

    int i = l, i1 = l, i2 = m + 1;
    for ( ; i1 <= m && i2 <= n; i++)
    {
        if (initList[i1] < initList[i2])
        {
            mergedList[i] = initList[i1++];
        } else {
            mergedList[i] = initList[i2++];
        }
    }

    // copy remaining records, if any, of first list
    copy (initList + i1, initList + m + 1, mergedList + i);
    
    // copy remaining records, if any, of second list
    copy (initList + i2, initList + n + 1, mergedList + i);
}

int main()
{

    int init[] = {1,3,5,7, 2,4,6,8};
    int merge[10];
    Merge(init, merge, 0, 3, 7);
    Display(merge, 8);

    return 0;
}
