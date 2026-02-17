#include<iostream>
#include<fstream>
using namespace std;

#define MAX 100

class Heap {
	int h[MAX];
	int hSize;
	
	//For insertion
	void heapifyUp(int index) {
		while(index > 0) {
			int parent = (index - 1) / 2;
			if(h[parent] < h[index]) {
				swap(h[parent], h[index]);
				index = parent;
			} else {
				break;
			}
		}
	}
	
	//For deletion
	void heapifyDown(int index) {
		int largest = index;
		while(true) {
			int left = 2 * index + 1;
			int right = 2 * index + 2;
			largest = index;
			if(left < hSize && h[left] > h[largest])
				largest = left;
			if(right < hSize && h[right] > h[largest])
				largest = right;
			if(largest != index) {
				swap(h[index], h[largest]);
				index = largest;
			} else {
				break;
			}
		}
	}
	
public:
	Heap() {
		hSize = 0;
	}
	
	void insert(int value) {
		if(hSize == MAX) return;
		h[hSize] = value;
		heapifyUp(hSize);
		hSize++;
	}
	
	void removeRoot() {
		if(hSize == 0) return;
		h[0] = h[hSize - 1];
		hSize--;
		heapifyDown(0);
	}
	
	int getMax() {
		if(hSize == 0) return-1;
		return h[0];
	}
	
	void display() {
		if(hSize == 0) return;
		for(int i = 0; i < hSize; i++)
			cout << h[i] << " ";
		cout << endl;
	}
	
	int size() {
		return hSize;
	}
	
	void loadFile(const char *filename) {
		ifstream file(filename);
		int value;
		if(!file) return;
		while(file >> value) {
			insert(value);
		}
		file.close();
	}
};

int main() {
	Heap H;
	H.loadFile("num.txt");
	cout << "Heap elements: \n";
	H.display();
	cout << "\nMax element: \n" << H.getMax() << endl;
	cout << "\nDelete root \n";
	H.removeRoot();
	cout << "\nHeap after deletion: \n";
	H.display();
	cout << "\nSize of heap: \n" << H.size() << endl;
	return 0;	
}
