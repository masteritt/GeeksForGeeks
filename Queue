#include <iostream>

using namespace std;
#define MAX 10

class Queue{
private:
	int item[MAX];
	int rear;
	int front;
public:
	Queue(){
		rear = -1;
		front = -1;
	}
	bool isFull(){
		if (rear + 1 == MAX)
			return true;
		else
			return false;
	}
	bool isEmpty() {
		if ((front == -1) || (front>rear))
			return true;
		else
			return false;
	}
	bool push(int x){
		if (!isFull()){
			item[++rear] = x;
			if (front == -1)
				front = 0;
			return true;
		}
		return false;
	}
	bool pop(int &x){
		if (!isEmpty())
		{
			x = item[front++];
			return true;
		}
		else
			return false;
	}
};

class cqueue
{
	int a[MAX], front, rear;
public:
	cqueue()
	{
		front = rear = -1;
	}
	bool isFull(){
		if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
			return true;
		else
			return false;
	}
	bool isEmpty() {
		if (front == -1)
			return true;
		else
			return false;
	}
	bool push(int x){
		if (!isFull())
		{
			if (rear == MAX - 1)
				rear = 0;
			else
				rear++;
			a[rear] = x;
			if (front == -1)
				front = 0;
			return true;
		}
		return false;
	}
	bool pop(int &x){
		if (!isEmpty())
		{
			x = a[front];
			if (front == rear)
				front = rear = -1;
			else
			{
				if (front == MAX - 1)
					front = 0;
				else
					front++;
			}
			return true;
		}
		return false;
	}
};
