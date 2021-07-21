#include <iostream>
#include "BinaryTree.h"
using namespace std;


void test1()
{
    BinaryTree<char> t;
    t.setup();
    t.Inorder();
    cout << endl;
    t.Postorder();
    cout << endl;
    t.Preorder();
    cout << endl;
    t.NonrecInorder();
    cout << endl;


    BinaryTree<char>::InorderIterator *it = new BinaryTree<char>::InorderIterator(t);
    char *data;
    while ((data = it->Next()))
        cout << *data;
    cout << endl;
}

void test2()
{
    int x = 3;
    BinaryTree<int> left(new BinaryTreeNode<int>(1));
    BinaryTree<int> right(new BinaryTreeNode<int>(2));
    BinaryTree<int> root(left, x, right);

    int *data;
    BinaryTree<int>::InorderIterator it(root);
    while ((data = it.Next()))
            cout << *data;
    cout << endl;
}

void test3()
{ // test copy constructor
    char op = '+';
    BinaryTree<char> left(new BinaryTreeNode<char>('2'));
    BinaryTree<char> right(new BinaryTreeNode<char>('3'));
    BinaryTree<char> root(left, op, right);
    root.Inorder();
    cout << endl;

    BinaryTree<char> copied(root);
    copied.Inorder();
    cout << endl;
}

void test4()
{ // test copy constructor
    char op = '+';
    BinaryTree<char> left(new BinaryTreeNode<char>('2'));
    BinaryTree<char> right = left;
    BinaryTree<char> *root = new BinaryTree<char>(left, op, right);
    root->Inorder();
    cout << endl;
    delete root;
}

void test5()
{ // test destructors

    BinaryTree<char>* tree = new BinaryTree<char>();
    tree->setup();
    tree->Inorder();
    cout << endl;
    delete tree;

}

void test6()
{ // test NoStackInorder

    BinaryTree<char>* tree = new BinaryTree<char>();
    tree->setup();
    tree->NoStackInorder();
    cout << endl;
    delete tree;

}
/*
*/
int main() {
    //test1(); // basic operations
    //test2(); // test constructors
    //test3(); // test copy constructor
    //test4(); // test copy assign operator
    test5(); // test destructors
    //test6(); // test NoStackInorder

    return 0;
}
