class BST {
	int* A;
	int s;
public:
	BST(int n = 50);
	void insert(int key);
	bool search(int key);
	
	void inorder(int i);
	void preorder(int i);
	void postorder(int i);
	
	int findMin();
	int findMax();
	int height(int i);
	void remove(int key);
};
