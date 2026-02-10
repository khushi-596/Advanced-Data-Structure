class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue();          
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    bool isFull();
};
