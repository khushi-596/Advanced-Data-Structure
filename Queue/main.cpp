#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include "queue.h"
using namespace std;

int main() {
    Queue q;

    srand(time(0));   

    cout << "Enqueuing random numbers:\n";
    for (int i = 0; i < 5; i++) {
        int num = rand() % 100;   // 0–99
        cout << num << " ";
        q.enqueue(num);
    }

    cout << "\n\nDequeuing elements:\n";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}

