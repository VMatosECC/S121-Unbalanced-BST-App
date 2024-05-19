#pragma once
#include <queue>
#include "Node.h"

template <class T>
struct BST
{
    //------------------------------------------------------------------------------
    // Version 0. Intentionally, all fields and functions made public for easy access
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

    //Delete a node from the tree
    bool remove(T key) {
        //Is the tree empty?
        if (root == nullptr) return false;

        //Find the node to be deleted
        Node<T>* current = search(key);
        if (current == nullptr) return false;

        //Case 1: Node has no children
        if (current->left == nullptr && current->right == nullptr) {
            //Adjust the parent's left or right pointer
            if (current->parent->left == current)
                current->parent->left = nullptr;
            else
                current->parent->right = nullptr;
            //Delete the node
            delete current;
            return true;
        }

        //Case 2: Node has only one child
        if (current->left  == nullptr && current->right != nullptr || 
            current->right == nullptr && current->left  != nullptr) {
            //Set the parent's left or right pointer to the child
            Node<T>* child = current->left == nullptr ? current->right : current->left;
            //Adjust the parent's left or right pointer
            if (current->parent->left == current)
                current->parent->left = child;
            else
                current->parent->right = child;
            //Delete the node
            delete current; 
            return true;
        }

        //Case 3: Node has two children - Apply Hiddard's Algorithm 
        //Find the Rightmost node of Left Subtree.
        Node<T>* successor = current->left;

        while (successor->right != nullptr)
            successor = successor->right;

        //Copy the data of the successor to the current node
        current->data = successor->data;

        //Adjust the succesor's parent's left or right pointer
        if (successor->parent->left == successor)
            successor->parent->left = successor->left;
        else
            successor->parent->right = successor->left;
        
        
        //If needed, adjust the succesor's left child to point to the successor's parent 
        if (successor->left != nullptr) { successor->left->parent = successor->parent; }
        
        //Delete the successor node
        delete successor;
        return true;    
    
    
    }

};

