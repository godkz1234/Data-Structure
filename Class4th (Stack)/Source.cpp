#include <iostream>

using namespace std;

template <typename T>

#define SIZE 10

class Stack
{
private:
	int top;
	int size;
	T container[SIZE];
public:
	Stack()
	{
		top = -1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void Push(T data)
	{
		if (top >= SIZE - 1)
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			container[++top] = data;
		}
	}

	void PoP()
	{
		if (Empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top--;
		}
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int& Size()
	{
		size = top + 1;

		return size;
	}

	T& Top()
	{
		return container[top];
	}
};

int main()
{
	Stack<int> stack;

	//	for (int i = 0; i < 11; i++)
	//	{
	//		stack.Push(1);
	//	}

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);

	cout << "Stack의 크기 : " << stack.Size() << endl;

	while (stack.Empty() == false)
	{
		cout << stack.Top() << endl;

		stack.PoP();
	}

	return 0;
};
