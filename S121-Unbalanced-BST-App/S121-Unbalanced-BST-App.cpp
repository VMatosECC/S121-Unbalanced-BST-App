// S121-Unbalanced-BST-App.cpp 
// Goal: Implement a basic BST (no balancing operations yet!)
//       include methods: insert, search, print.
// -------------------------------------------------------------
#include <iostream>
#include "Node.h"
#include "BST.h"
using namespace std;

void experiment01();
void experiment02();


int main()
{
    //experiment01();
    experiment02();
    cout << "\nAll done!\n";
}

// =============================================================
void experiment02()
{
    BST<int> t;
    t.insert(40);
    t.insert(20);
    t.insert(30);
    t.insert(45);
    t.insert(16);
    t.insert(90);
    t.insert(7);
    t.insert(8);

    t.preorder();
    t.postorder();

    t.rowWise();
}





void experiment01()
{
    Node<int>* n1 = new Node<int>(25);
    cout << "n1 " << *n1 << endl;

    Node<string>* n2 = new Node<string>("LAX");
    cout << "n2 " << *n2 << endl;

}