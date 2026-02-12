#include <iostream>
#include "BST.h"
using namespace std;

BST::BST() {
    root = NULL;
}

Node* BST::insert(Node* node, int value) {
    if (node == NULL) {
        Node* temp = new Node;
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

bool BST::search(Node* node, int key) {
    if (node == NULL)
        return false;

    if (node->data == key)
        return true;

    if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

/* ---------- TRAVERSALS ---------- */
void BST::inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::preorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int BST::countNodes(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left)
             + countNodes(node->right);
}

int BST::height(Node* node) {
    if (node == NULL)
        return -1;

    int lh = height(node->left);
    int rh = height(node->right);

    return (lh > rh ? lh : rh) + 1;
}

Node* BST::findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* BST::deleteNode(Node* node, int key) {
    if (node == NULL)
        return node;

    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        // Case 1: No child
        if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
        }
        // Case 2: One child
        else if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
}

