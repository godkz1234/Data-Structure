#include <iostream>

using namespace std;

#define SIZE 10

template<typename T>

class Heap
{
private:
	int index;
	T container[SIZE];
public:
	Heap()
	{
		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}
		index = 0;
	}

	void Insert(T data)
	{
		if (index >= SIZE)
		{
			cout << "Heap Overflow" << endl;
		}
		else
		{
			container[++index] = data;

			int child = index;
			int parent = child / 2;

			while (child > 1)
			{
				if (container[parent] < container[child])
				{
					std::swap(container[parent], container[child]);
				}

				child = parent;
				parent = child / 2;
			};
		}
	}

	void Remove()
	{

	}

	void Show()
	{
		for (int i = 1; i <= index; i++)
		{
			cout << container[i] << " ";
		}
	}
};

int main()
{
	Heap<int> heap;

	heap.Insert(5);
	heap.Insert(7);
	heap.Insert(9);
	heap.Insert(16);

	heap.Show();

	return 0;
}
