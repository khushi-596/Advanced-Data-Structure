#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST tree;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.root = tree.insert(tree.root, value);
    }

    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    cout << "\n\nTotal Nodes: " << tree.countNodes(tree.root);
    cout << "\nHeight of BST: " << tree.height(tree.root);

    cout << "\n\nSearch element: ";
    cin >> value;
    cout << (tree.search(tree.root, value) ? "Found" : "Not Found");

    cout << "\n\nDelete element: ";
    cin >> value;
    tree.root = tree.deleteNode(tree.root, value);

    cout << "\nInorder after deletion: ";
    tree.inorder(tree.root);

    return 0;
}

