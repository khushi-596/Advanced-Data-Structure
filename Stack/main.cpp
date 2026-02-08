#include<iostream>
#include<cstdlib>
#include<ctime>
#include "stack.h"
using namespace std;

int main() {
	Stack s;
	srand(time(0));
	cout << "pushing numbers into stack\n";
	for(int i = 0; i < 5; i++) {
	        int num = rand() % 100;
	        cout << num << " ";
	        s.push(num);
	}
	
	cout <<"\n Popping elements from stack\n";
	while(!s.isEmpty()) {
	        cout << s.pop() << " ";
	}
	return 0;
}
