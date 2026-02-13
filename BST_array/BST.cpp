#include<iostream>
#include<climits>
#include "BST.h"
using namespace std;

BST :: BST(int n) {
	s = n;
	A = new int[s];
	if(!A) return;
	for(int i = 0; i < s; i++) 
		A[i] = INT_MIN;
}

void BST :: insert(int key) {
        int i = 0;
        while(i < s) {
	        if(A[i] == INT_MIN) {
		        A[i] = key;
		        return;
	        }
	        if(key < A[i])
	                i = 2 * i + 1;
	        else if(key > A[i])
	                i = 2 * i + 2;
	        else return;
	}
}

bool BST :: search(int key) {
        int i = 0;
        while(i < s && A[i] != INT_MIN) {
                if(A[i] == key)
                        return true;
                if(key < A[i])
                        i = 2 * i + 1;
                else 
                        i = 2 * i + 2;
        }
        return false;
}

void BST :: inorder(int i) {
        if(i >= s || A[i] == INT_MIN) return;
        inorder(2 * i + 1);
        cout << A[i] << " ";
        inorder(2 * i + 2);
}

void BST::preorder(int i) {
        if (i >= s || A[i] == INT_MIN) return;
        cout << A[i] << " ";
        preorder(2*i + 1);
        preorder(2*i + 2);
}

void BST::postorder(int i) {
        if (i >= s || A[i] == INT_MIN) return;
        postorder(2*i + 1);
        postorder(2*i + 2);
        cout << A[i] << " ";
}

int BST::findMin() {
        int i = 0;
        while (2*i + 1 < s && A[2*i + 1] != INT_MIN)
            i = 2*i + 1;
        return A[i];
}

int BST::findMax() {
        int i = 0;
        while (2*i + 2 < s && A[2*i + 2] != INT_MIN)
            i = 2*i + 2;
        return A[i];
}

int BST::height(int i) {
        if (i >= s || A[i] == INT_MIN) return -1;
        int l = height(2*i + 1);
        int r = height(2*i + 2);
        return (l > r ? l : r) + 1;
}

void BST :: remove(int key) {
        int i = 0;
        //find node
        while(i < s && A[i] != INT_MIN && A[i] != key) {
              if(key < A[i])
                    i = 2 * i + 1;
              else
                    i = 2 * i + 2;
        }
        //not found
        if(i >= s || A[i] == INT_MIN) {
              return;
        }
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        //leaf
        if((left >= s || A[left] == INT_MIN) && (right >= s || A[right] == INT_MIN)) {
                A[i] = INT_MIN;
        }
        
        //one child
        else if(left < s && A[left] != INT_MIN && (right >= s || A[right] == INT_MIN)) {
                A[i] = A[left];
                A[left] = INT_MIN;
        }
        else if(right < s && A[right] != INT_MIN && (left >= s || A[left] == INT_MIN)) {
                A[i] = A[right];
                A[right] = INT_MIN;
        }
        
        //two children
        else {
                int succ = right;
                while(2 * succ + 1 < s && A[2 * succ + 1] != INT_MIN)
                      succ = 2 * succ + 1;
                A[i] = A[succ];
                A[succ] = INT_MIN;        
        }
}
