#ifndef _UTILS_H_
#define _UTILS_H_

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
    if (newSize < 0) throw "New length must be >= 0";

    T* temp = new T[newSize];
    int number = std::min(oldSize, newSize);
    std::copy(a, a + number, temp);
    delete [] a;
    a = temp;
}

#endif
