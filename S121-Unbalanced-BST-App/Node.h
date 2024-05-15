#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T        data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    Node(T newData) {
        data = newData;
        left = right = parent = nullptr;
    }

    friend ostream& operator << (ostream& sout, const Node<T> n) {
        sout << "[ L: " << n.left << ", R: " << n.right
            << ", P: " << n.parent << ", D: " << n.data << " ]";
        return sout;
    }
};

