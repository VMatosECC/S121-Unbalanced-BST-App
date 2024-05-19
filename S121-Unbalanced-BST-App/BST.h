#pragma once
#include <queue>
#include "Node.h"

template <class T>
struct BST
{
    //------------------------------------------------------------------------------
    //Version 0. Intentionally, all fields and functions made public for easy access
    // Implementing a simple Binary Search Tree (BST) with basic operations
    // insert, search, print, delete, etc.
    //------------------------------------------------------------------------------
    Node<T>* root;

    BST() {
        root = nullptr;
    }

    ~BST() {
        //TODO - must remove dynamically created Node<T> containers!
    }

    void insert(T newData)
    {
        //Create a new node
        Node<T>* newNode = new Node<T>(newData);

        //Is this the first tree node?
        if (root == nullptr) {
            root = newNode;
            return;
        }

        //Traverse the tree to find the right place for the new node
        Node<T>* previous = nullptr;
        Node<T>* current = root;

        while (current != nullptr) {
            previous = current;
            if (current->data > newData)
                current = current->left;
            else
                current = current->right;
        }

        //Attach the new node to the tree (left or right of previous node)
        if (previous->data > newData)
            previous->left = newNode;
        else
            previous->right = newNode;

        newNode->parent = previous;
        
        //fixInsertion();   //TODO - Use this to balance the tree

    }

    //Display the tree in PreOrder Traversal
    void preorder(Node<T>* p) {
        if (p == nullptr) return;
        cout << *p << endl;
        preorder(p->left);
        preorder(p->right);
    }

    //Display the tree in PreOrder Traversal (helper method)
    void preorder() {
        cout << "\nPreOrder Traversal\n";
        preorder(root);
    }

    //Display the tree in PostOrder Traversal
    void postorder(Node<T>* p) {
        if (p == nullptr) return;
        postorder(p->left);
        postorder(p->right);
        cout << *p << endl;
    }

    // Display the tree in PostOrder Traversal (helper method)
    void postorder() {
        cout << "\nPostOrder Traversal\n";
        postorder(root);
    }

    //Display the tree in Breath-First Search (BFS) or Row-Wise Traversal
    void rowWise() {
        cout << "\nRow-Wise Traversal (BFS)\n";

        //Create a queue to store the unvisited nodes
        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            //get the front node from the queue - and remove it from the queue
            Node<T>* current = q.front();
            q.pop();
            //Display the node - and add its children (if any!) to the queue
            cout << *current << endl;
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);

        }
    }

    //Search for a key in the tree
    Node<T>* search(T key) {
        Node<T>* current = root;
        while (current != nullptr) {
            if (current->data == key) 
                return current;
            if (current->data > key)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }
};

