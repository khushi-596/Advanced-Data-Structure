#include<iostream>
#include "stack.h"
using namespace std;

Stack :: Stack() {
        top = -1;
}
void Stack :: push(int data) {
	if(!isFull()) {
		arr[++top] = data;
	}
}
	
int Stack :: pop() {
	if(!isEmpty()) return arr[top--];
	return -1;
}
	
bool Stack :: isFull() {
	return top == MAX - 1;
}
	
bool Stack :: isEmpty() {
	return top == -1;
}
