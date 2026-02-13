#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BST.h"
using namespace std;

int main() {
    BST T(50);
    srand(time(0));

    cout << "Inserted: ";
    for (int i = 0; i < 10; i++) {
        int x = rand() % 100;
        cout << x << " ";
        T.insert(x);
    }

    cout << "\nInorder: ";
    T.inorder(0);

    int del;
    cout << "\nEnter element to delete: ";
    cin >> del;
    T.remove(del);

    cout << "After Deletion (Inorder): ";
    T.inorder(0);

    cout << "\nHeight: " << T.height(0);
    return 0;
}

