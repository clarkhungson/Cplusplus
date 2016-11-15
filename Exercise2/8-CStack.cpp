#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

#define MAX_SIZE 100

class CStack
{
private:
	int stack[MAX_SIZE];
	int size;
public:
	CStack(){size = 0;}
	~CStack(){}
	void push(int x);
	int pop();
	void show();
};

void CStack::push(int x)
{
	if(size >= MAX_SIZE)
	{
		cout << "Stack is overflow\n";
	}
	else
		stack[size++] = x;
}

int CStack::pop()
{
	if(size == 0)
	{
		cout << "Stack is empty";
	}
	else
		return stack[--size];
}

void CStack::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << "s[" << i << "] = " << stack[i] << "\n";
	}

}

int main()
{
	CStack stack;
	int x;
	stack.push(4);
	stack.push(-5);
	stack.push(2);
	stack.show();
	x = stack.pop();
	cout << "x = " << x << endl;
	stack.show();
	return 0;
}