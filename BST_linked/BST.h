struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
public:
    Node* root;

    BST();

    Node* insert(Node* node, int value);
    bool search(Node* node, int key);

    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);

    int countNodes(Node* node);
    int height(Node* node);

    Node* deleteNode(Node* node, int key);
    Node* findMin(Node* node);
};


