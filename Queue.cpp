#include <iostream>
using namespace std;

class fronta
{
public:
  fronta(int size);
	~fronta();
	bool Put(int arg);
	int Get();
	bool empty();
	bool full();
private:
	int size;
	int *pole;
	int tail;
	int head;
	bool canbefull;
	bool canbeempty;
};

fronta::fronta(int size)
{
	this->size = size;
	pole = new int[size];
	tail = 0;
	head = 0;
	canbefull=size==0;
	canbeempty=true;
}
fronta::~fronta()
{

}

bool fronta::Put(int arg)
{
	if (full())
	{
		cout<<"full"<<endl;
		return false;
	}

	canbefull=true;
	canbeempty=false;
	pole[tail] = arg;
	tail = ++tail % size;
}
int fronta::Get()
{
	if(empty())
	{
		cout<<"empty"<<endl;
		return -1;
	}


	canbefull=false;
	canbeempty=true;
	int temp = head;
	head = ++head % size;
	return pole[temp];
}
bool fronta::empty()
{
	return head==tail && canbeempty;
}
bool fronta::full()
{
	return head==tail && canbefull;
}


int main()
{

	fronta f(3);


	return 0;
}
