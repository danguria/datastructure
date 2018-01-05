#include <iostream>
#include "BinaryTree.h"
using namespace std;


void test1()
{
    BinaryTreeNode<char> *root = new BinaryTreeNode<char>('+');

    BinaryTreeNode<char> *currentNode = root;
    currentNode->leftChild = new BinaryTreeNode<char>('*');
    currentNode->rightChild = new BinaryTreeNode<char>('E');

    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('*');
    currentNode->rightChild = new BinaryTreeNode<char>('D');
    
    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('/');
    currentNode->rightChild = new BinaryTreeNode<char>('C');
    
    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('A');
    currentNode->rightChild = new BinaryTreeNode<char>('B');

    BinaryTree<char>* tree = new BinaryTree<char>(root);
    tree->Inorder();
    cout << endl;
    tree->Postorder();
    cout << endl;
    tree->Preorder();
    cout << endl;
    tree->NonrecInorder();
    cout << endl;


    BinaryTree<char>::InorderIterator *it = new BinaryTree<char>::InorderIterator(root);
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
    BinaryTree<int>::InorderIterator it(root.root);
    while ((data = it.Next()))
            cout << *data;
    cout << endl;
}

void test3()
{ // test copy constructor
    char op = '+';
    BinaryTree<char> left(new BinaryTreeNode<char>('2'));
    BinaryTree<char> right(left);
    BinaryTree<char> root(left, op, right);
    root.Inorder();
    cout << endl;
}

void test4()
{ // test copy constructor
    char op = '+';
    BinaryTree<char> left(new BinaryTreeNode<char>('2'));
    BinaryTree<char> right = left;
    BinaryTree<char> root(left, op, right);
    root.Inorder();
    cout << endl;
}

void test5()
{ // test destructors
    BinaryTreeNode<char> *root = new BinaryTreeNode<char>('+');

    BinaryTreeNode<char> *currentNode = root;
    currentNode->leftChild = new BinaryTreeNode<char>('*');
    currentNode->rightChild = new BinaryTreeNode<char>('E');

    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('*');
    currentNode->rightChild = new BinaryTreeNode<char>('D');
    
    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('/');
    currentNode->rightChild = new BinaryTreeNode<char>('C');
    
    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('A');
    currentNode->rightChild = new BinaryTreeNode<char>('B');

    BinaryTree<char>* tree = new BinaryTree<char>(root);
    tree->Inorder();
    cout << endl;
    delete tree;

}

void test6()
{ // test NoStackInorder
    BinaryTreeNode<char> *root = new BinaryTreeNode<char>('+');

    BinaryTreeNode<char> *currentNode = root;
    currentNode->leftChild = new BinaryTreeNode<char>('*');
    currentNode->rightChild = new BinaryTreeNode<char>('E');

    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('*');
    currentNode->rightChild = new BinaryTreeNode<char>('D');
    
    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('/');
    currentNode->rightChild = new BinaryTreeNode<char>('C');
    
    currentNode = currentNode->leftChild;
    currentNode->leftChild = new BinaryTreeNode<char>('A');
    currentNode->rightChild = new BinaryTreeNode<char>('B');

    BinaryTree<char>* tree = new BinaryTree<char>(root);
    tree->NoStackInorder();
    cout << endl;
    delete tree;

}

int main() {
    //test1(); // basic operations
    //test2(); // test constructors
    //test3(); // test copy constructor
    //test4(); // test copy assign operator
    //test5(); // test destructors
    test6(); // test NoStackInorder

    return 0;
}
