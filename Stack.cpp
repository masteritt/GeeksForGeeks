#include <iostream>

using namespace std;
#define MAX 10

class stackArray{
	int a[MAX]; 
	int tos;
public:
	stackArray(){ tos = 0; }
	bool isEmpty(){ return (tos == 0) ? true : false; }
	bool isFull(){ return (tos == MAX) ? true : false; }
	bool push(int x){
		if (!isFull()){
			a[tos++] = x;
			return true;
		}
		return false;
	}
	bool pop(int &x){
		if (!isEmpty()){
			x = a[--tos];
			return true;
		}
		return false;
	}
}; 
class node{
public:
	int d;
	node *next;
	node(int data){
		next = NULL;
		d = data;
	}
};
class stackLL{
	node *top;
public:
	stackLL(){ top = NULL; }
	bool empty(){ return ((top == NULL) ? 1 : 0); }
	void push(int d){
		node *p = new node(d);
		p->next = top;
		top = p;
	}
	bool pop(int &i){
		if (empty()){
			return false;
		}
		else{
			node *p = top;
			top = top->next;
			i = p->d;
			delete p;
			return true;
		}
	}
};
