#pragma once
#include <queue>
#include "Node.h"

template <class T>
struct BST
{
    Node<T>* root;

    BST() {
        root = nullptr;
    }

    ~BST() {
        //TODO - remove dynamically created Node containers
    }

    void insert(T newData)
    {
        Node<T>* newNode = new Node<T>(newData);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node<T>* previous = nullptr;
        Node<T>* current = root;

        while (current != nullptr) {
            previous = current;
            if (current->data > newData)
                current = current->left;
            else
                current = current->right;
        }

        if (previous->data > newData)
            previous->left = newNode;
        else
            previous->right = newNode;

        newNode->parent = previous;
        
        //fixInsertion();

    }

    void preorder(Node<T>* p) {
        if (p == nullptr) return;
        cout << *p << endl;
        preorder(p->left);
        preorder(p->right);
    }

    void preorder() {
        cout << "\nPreOrder Traversal\n";
        preorder(root);
    }


    void postorder(Node<T>* p) {
        if (p == nullptr) return;
        postorder(p->left);
        postorder(p->right);
        cout << *p << endl;
    }

    void postorder() {
        cout << "\nPostOrder Traversal\n";
        postorder(root);
    }

    void rowWise() {
        cout << "\nRow-Wise Traversal (BFS)\n";

        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();
            cout << *current << endl;
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);

        }
    }
};

