
#define MAX 100
class Stack {
	int arr[MAX];
	int top;
	
public:
        Stack();
        void push(int data);
        int pop();
        bool isEmpty();
        bool isFull();
};


	

