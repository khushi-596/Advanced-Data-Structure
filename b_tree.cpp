#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

class BTree {
private:
    struct node {
        int key[3];        
        node *child[4];    
        int count;
        bool leaf;
    };

    node* root;

    //Create Node
    node* createNode(bool leaf) {
        node* newNode = new node;
        newNode->leaf = leaf;
        newNode->count = 0;

        for (int i = 0; i < 3; i++)
            newNode->child[i] = NULL;

        return newNode;
    }

    //Split Child
    void splitChild(node* parent, int i, node* fullChild) {
        node* newChild = createNode(fullChild->leaf);

        newChild->count = 1;
        newChild->key[0] = fullChild->key[1];

        if (!fullChild->leaf) {
            newChild->child[0] = fullChild->child[2];
            newChild->child[1] = NULL;
        }

        fullChild->count = 1;

        for (int j = parent->count; j >= i + 1; j--)
            parent->child[j + 1] = parent->child[j];

        parent->child[i + 1] = newChild;

        for (int j = parent->count - 1; j >= i; j--)
            parent->key[j + 1] = parent->key[j];

        parent->key[i] = fullChild->key[1]; // middle key
        parent->count++;
    }

    //Insert Non-Full
    void insertNonFull(node* root, int k) {
        int i = root->count - 1;

        if (root->leaf) {
            while (i >= 0 && k < root->key[i]) {
                root->key[i + 1] = root->key[i];
                i--;
            }
            root->key[i + 1] = k;
            root->count++;
        } else {
            while (i >= 0 && k < root->key[i])
                i--;

            i++;

            if (root->child[i]->count == 2) {
                splitChild(root, i, root->child[i]);

                if (k > root->key[i])
                    i++;
            }
            insertNonFull(root->child[i], k);
        }
    }

    //Simple Delete (leaf)
    node* deleteKey(node* root, int k) {
        if (!root) return root;

        int i;
        for (i = 0; i < root->count; i++) {
            if (root->key[i] == k) break;
        }

        if (i < root->count && root->leaf) {
            for (int j = i; j < root->count - 1; j++)
                root->key[j] = root->key[j + 1];
            root->count--;
        } else if (!root->leaf) {
            root->child[i] = deleteKey(root->child[i], k);
        }

        return root;
    }

public:
    BTree() {
        root = NULL;
    }

    //Insert
    void insert(int k) {
        if (root == NULL) {
            root = createNode(true);
            root->key[0] = k;
            root->count = 1;
            return;
        }

        if (root->count == 2) {
            node* newRoot = createNode(false);
            newRoot->child[0] = root;

            splitChild(newRoot, 0, root);

            int i = 0;
            if (k > newRoot->key[0])
                i++;

            insertNonFull(newRoot->child[i], k);
            root = newRoot;
        } else {
            insertNonFull(root, k);
        }
    }

    //Delete
    void remove(int k) {
        root = deleteKey(root, k);
    }

    //Level Order Traversal
    void levelOrder() {
        if (!root) return;

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                node* temp = q.front();
                q.pop();

                cout << "[ ";
                for (int i = 0; i < temp->count; i++)
                    cout << temp->key[i] << " ";
                cout << "] ";

                if (!temp->leaf) {
                    for (int i = 0; i <= temp->count; i++)
                        if (temp->child[i])
                            q.push(temp->child[i]);
                }
            }
            cout << endl;
        }
    }

    void insertRandom(int n) {
        srand(time(0));

        cout << "Inserted values: ";
        for (int i = 0; i < n; i++) {
            int val = rand() % 100; 
            cout << val << " ";
            insert(val);
        }
        cout << endl;
    }
};

int main() {
    BTree tree;

    tree.insertRandom(7);   

    cout << "\nLevel Order:\n";
    tree.levelOrder();

    cout << "\nAfter deleting a value:\n";
    tree.remove(20); 
    tree.levelOrder();

    return 0;
}
