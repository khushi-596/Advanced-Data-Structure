#include <iostream>
#include <climits>
#include <cstdlib>  
#include <ctime>    
using namespace std;

class Heap {
    int* A;
    int size;
    int last;

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (A[i] > A[parent]) {
                swap(A[i], A[parent]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int left, right, largest;

        while (true) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            largest = i;

            if (left <= last && A[left] > A[largest])
                largest = left;

            if (right <= last && A[right] > A[largest])
                largest = right;

            if (largest != i) {
                swap(A[i], A[largest]);
                i = largest;
            } else break;
        }
    }

public:
    Heap(int s) {
        size = s;
        last = -1;
        A = new int[size];
    }

    void insert(int value) {
        if (last == size - 1) {
            cout << "Heap Full\n";
            return;
        }
        A[++last] = value;
        heapifyUp(last);
    }

    int removeMax() {
        if (last == -1) return INT_MIN;

        int maxVal = A[0];
        A[0] = A[last--];
        heapifyDown(0);

        return maxVal;
    }

    void display() {
        for (int i = 0; i <= last; i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap h(10);

    srand(time(0));  

    cout << "Customer Purchases:\n";
    for (int i = 0; i < 10; i++) {
        int value = rand() % 2000 + 100;  
        cout << value << " ";
        h.insert(value);
    }

    cout << "\n\nMax Heap:\n";
    h.display();

    cout << "\nTop 3 Highest Spenders:\n";
    int top1 = h.removeMax();
    int top2 = h.removeMax();
    int top3 = h.removeMax();

    cout << top1 << " " << top2 << " " << top3 << endl;

    cout << "\nHeap after removing top spenders:\n";
    h.display();

    return 0;
}
