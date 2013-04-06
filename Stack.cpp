#include <iostream>
using namespace std;

class stack
{
public:
  stack(int size);
	~stack();
	int push(int arg);
	int pop();
	bool full();
	bool empty();
	int poponindex(int index);
private:
	int size;
	int *pole;
	int head;

};

stack::stack(int size)
{
	this->size = size;
	pole = new int[size];
	head = 0;
}
stack::~stack()
{
	delete []pole;
}
bool stack::empty()
{
	return head == 0;
}
bool stack::full()
{
	return head == size - 1;		
}
int stack::push(int arg)
{
	if (full())
	{
		cout << "stack is full!" << endl;
		return -1;
	}
	pole[head] = arg;
	head++;
	return true;
}
int stack::pop()
{
	if (empty())
	{
		cout<<"stack is empty!"<<endl;
		return -1;
	}
	int prvek=pole[head-1];
	head--;

	return prvek;
}
int stack::poponindex(int index)
{
	if(index<0 || index>size)
	{
		return 0;
	}
	else
	{
		cout<<"prvek je: "<<pole[index]<<endl;
		return 1;
	}
}

int main()
{
	stack s(4);
		
	return 0;
}
