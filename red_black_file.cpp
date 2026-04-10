#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
        string name;
        Color color;
        Node *left, *right, *parent;
};
    
class RBTree {
private:
    Node *root;
    Node* createNode(string name) {
        Node* n = new Node;
        n->name = name;
        n->color = RED;
        n->left = n->right = n->parent = NULL;
        return n;
    }

    //Left Rotate
    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;

        if (y->left != NULL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    //Right Rotate
    void rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;

        if (x->right != NULL)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == NULL)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    //Fix Insert
    void fixInsert(Node *k) {
        while (k != root && k->parent->color == RED) {

            if (k->parent == k->parent->parent->left) {
                Node *u = k->parent->parent->right;

                if (u != NULL && u->color == RED) {
                    k->parent->color = BLACK;
                    u->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            } else {
                Node *u = k->parent->parent->left;

                if (u != NULL && u->color == RED) {
                    k->parent->color = BLACK;
                    u->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    //Inorder Traversal
    void inorder(Node *r) {
        if (r == NULL) return;

        inorder(r->left);
        cout << r->name << " (" 
             << (r->color == RED ? "R" : "B") << ") ";
        inorder(r->right);
    }

public:
    RBTree() {
        root = NULL;
    }

    //Insert Directory
    void insert(string name) {
        Node *node = createNode(name);

        Node *y = NULL;
        Node *x = root;

        while (x != NULL) {
            y = x;
            if (node->name < x->name)
                x = x->left;
            else
                x = x->right;
        }

        node->parent = y;

        if (y == NULL)
            root = node;
        else if (node->name < y->name)
            y->left = node;
        else
            y->right = node;

        if (node->parent == NULL) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == NULL)
            return;

        fixInsert(node);
    }

    //Display
    void display() {
        cout << "Directory Structure:\n";
        inorder(root);
        cout << endl;
    }
};

int main() {
    RBTree fs;

    fs.insert("Documents");
    fs.insert("Pictures");
    fs.insert("Downloads");
    fs.insert("Videos");
    fs.insert("Music");
    fs.display();

    return 0;
}
