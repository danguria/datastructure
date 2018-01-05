#ifndef __TREE_NODE
#define __TREE_NODE
#include <iostream>
#include "Stack.h"

template <class T> class BinaryTree; // forward declaration

template <class T>
class BinaryTreeNode
{
    friend class BinaryTree<T>;
    public:
        BinaryTreeNode(BinaryTreeNode<T>& rhs);
        BinaryTreeNode(T data);
        ~BinaryTreeNode();
        BinaryTreeNode& operator=(BinaryTreeNode<T>& rhs);
//    private:
        BinaryTreeNode<T>* leftChild;
        BinaryTreeNode<T>* rightChild;
        
        T data;
};

template <class T>
class BinaryTree
{
    friend class InorderIterator;
    public:
        // Constructors
        BinaryTree();  // creates an empty binary tree
        BinaryTree(BinaryTreeNode<T>* root);
        // creates a binary tree whose left subtree is bt1,
        // whose right subtree is bt2, and whose root node contains item
        BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);

        // copy constructor
        BinaryTree(BinaryTree<T>& rhs);
        ~BinaryTree();

        // copy assign operator
        BinaryTree<T>& operator=(BinaryTree<T>& rhs);


        bool IsEmpty(); // return true iff the binary tree is empty
        BinaryTree<T> LeftSubtree(); // return the left subtree of *this
        BinaryTree<T> RightSubtree();// return the right subtree of *this

        T RootData(); // return the data in the root node of *this

        // BinaryTree traversal operations
        void Inorder();
        void Postorder();
        void Preorder();
        void NonrecInorder();
        void NoStackInorder();

    private:
        void Inorder(BinaryTreeNode<T>* currentNode);
        void Postorder(BinaryTreeNode<T>* currentNode);
        void Preorder(BinaryTreeNode<T>* currentNode);
        void Visit(BinaryTreeNode<T>* currentNode);

   // private:
    public:
        BinaryTreeNode<T>* root;

    public:
        class InorderIterator
        {
            public:
                InorderIterator(BinaryTreeNode<T>* currentNode)
                {
                    this->currentNode = currentNode;
                }
               
                T* Next();
            private:
                Stack<BinaryTreeNode<T>*> s;
                BinaryTreeNode<T>* currentNode;
        };

};

/*******************************************
 * Implementations of BinaryTreeNodes
*******************************************/
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T data) :data(data)
{
    leftChild = rightChild = nullptr;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode<T>& rhs)
    : data(rhs.data) {}

template <class T>
BinaryTreeNode<T>& BinaryTreeNode<T>::operator=(BinaryTreeNode<T>& rhs)
{
    data = rhs.data;
    return *this;
}

template <class T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    if (leftChild != nullptr) delete leftChild;
    if (rightChild != nullptr) delete rightChild;
}


/*******************************************
 * Implementations of BinaryTreeNodes
*******************************************/
template <class T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T>* root)
{
    this->root = root;
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& bt1, T& item,
        BinaryTree<T>& bt2)
{
    this->root = new BinaryTreeNode<T>(item);
    this->root->leftChild = bt1.root;
    this->root->rightChild = bt2.root;
}

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& rhs)
{
    this->root = rhs.root;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    delete this->root;
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T>& rhs)
{
    this->root = rhs.root;
    return *this;
}

template <class T>
bool BinaryTree<T>::IsEmpty()
{
    return this->root != nullptr;
}

template <class T>
BinaryTree<T> BinaryTree<T>::LeftSubtree()
{
    return this->root->leftChild;
}

template <class T>
BinaryTree<T> BinaryTree<T>::RightSubtree()
{
    return this->root->rightChild;
}

template <class T>
T BinaryTree<T>::RootData()
{
    return this->data;
}

// Driver calls workhorse for traversal of entire tree.
// The driver is declared as a public member function of BinaryTree.
template <class T>
void BinaryTree<T>::Inorder()
{
    Inorder(root);
}

template <class T>
void BinaryTree<T>::Postorder()
{
    Postorder(root);
}

template <class T>
void BinaryTree<T>::Preorder()
{
    Preorder(root);
}

// Workhorse traverses the subtree rooted at currentNode.
// The workhorse is declared as a private member function of BinaryTree.
template <class T>
void BinaryTree<T>::Inorder(BinaryTreeNode<T>* currentNode)
{
    if (currentNode) {
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}
        
template <class T>
void BinaryTree<T>::Postorder(BinaryTreeNode<T>* currentNode) {
    if (currentNode) {
        Inorder(currentNode->leftChild);
        Inorder(currentNode->rightChild);
        Visit(currentNode);
    }
}

template <class T>
void BinaryTree<T>::Preorder(BinaryTreeNode<T>* currentNode) {
    if (currentNode) {
        Visit(currentNode);
        Inorder(currentNode->leftChild);
        Inorder(currentNode->rightChild);
    }
}

template <class T>
void BinaryTree<T>::NonrecInorder() {

    Stack<BinaryTreeNode<T>*> s;
    BinaryTreeNode<T>* currentNode = root;
    while (1) {
        while (currentNode) {
            s.Push(currentNode);
            currentNode = currentNode->leftChild;
        }

        if (s.IsEmpty()) return;
        currentNode = s.Top();
        s.Pop();

        Visit(currentNode);
        currentNode = currentNode->rightChild;
    }
}

template <class T>
void BinaryTree<T>::NoStackInorder()
{ // Inorder traversal of binary tree using a fixed amount of additional storage
    if (!root) return; // empty binary tree

    BinaryTreeNode<T> *top = 0, *lastRight = 0, *p, *q, *r, *r1;
    p = q = root;
    while (1) {
        while (1) {
            if ((!p->leftChild) && (!p->rightChild)) { // leaf node
                Visit(p);
                break;
            }
            if (p->leftChild) {
                // move to p->leftChild
                r = p->leftChild;
                p->leftChild = q;
                q = p;
                p = r;
            } else {
                // visit p and move to p->rightChild
                Visit(p);
                r = p->rightChild;
                p->rightChild = q;
                q = p;
                p = r;
            }
        } // end of inner while
        // p is a leaf node, move upward to a node whose
        // right subtree has not yet been examined
        BinaryTreeNode<T> *av = p;
        while (1) {
            if (p == root) return;
            if (!q->leftChild) { // q is linked via rightChild
                r = q->rightChild;
                q->rightChild = p;
                p = q;
                q = r;
            } else if (!q->rightChild) { // q is linked via leftChild
                r = q->leftChild;
                q->leftChild = p;
                p = q;
                q = r;
                Visit(p);
            } else { // check if p is a rightChild of q
                if (q == lastRight) {
                    r = top;
                    lastRight = r->leftChild;
                    top = r->rightChild; // unstack
                    r->leftChild = r->rightChild = 0;
                    r = q->rightChild;
                    q->rightChild = p;
                    p = q;
                    q = r;
                } else { // p is leftChild of q
                    Visit(q);
                    av->leftChild = lastRight;
                    av->rightChild = top;
                    top = av;
                    lastRight = q;
                    r = q->leftChild;
                    q->leftChild = p; // restore link to p
                    r1 = q->rightChild;
                    q->rightChild = r;
                    p = r1;
                    break;
                }
            }
        } // end of inner while loop
    } // end of outer while loop
}


template <class T>
void BinaryTree<T>::Visit(BinaryTreeNode<T>* currentNode)
{
    std::cout << currentNode->data;
}

template <class T>
T* BinaryTree<T>::InorderIterator::Next()
{
    while (currentNode)
    {
        s.Push(currentNode);
        currentNode = currentNode->leftChild;
    }

    if (s.IsEmpty()) return 0;
    currentNode = s.Top();
    s.Pop();
    T& temp = currentNode->data;
    currentNode = currentNode->rightChild;
    return &temp;
}

#endif // __TREE_NODE
