#ifndef _BAG_H_
#define _BAG_H_

class Bag
{
    public:
        Bag(int bagCapacity = 10);
        ~Bag ();

        // return number of elements in bag
        int Size() const;

        // return true if the bag is empty; false otherwise
        bool IsEmpty() const;

        // return an element that is in the bag
        int Element() const;

        // insert an integer into the bag
        void Push(const int);

        // delete an interger from the bag
        void Pop();

    private:
        int *array;
        int capacity;
        int top;
};

inline int Bag::Size() const { return top + 1; }

inline bool Bag::IsEmpty() const { return top == -1; }

inline int Bag::Element() const {
    if (IsEmpty()) throw "Bag is empty";
    return array[0];
}

#endif
