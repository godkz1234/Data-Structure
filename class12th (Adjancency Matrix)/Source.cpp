#include <iostream>

using namespace std;

#define SIZE 8

template <typename T>

class AdjacencyMatrix
{
private:
	int size;                // 정점의 개수
	char vertex[SIZE];       // 정점의 집합
	int matrix[SIZE][SIZE];  // 인접 행렬

public:
	AdjacencyMatrix()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;

			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = NULL;
			}
		}
	}

	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjancency Matrix Overflow" << endl;
		}
		else
		{
			vertex[size++] = data;
		}
	}

	void Connect(int i, int j)
	{
		if (size <= 0)
		{
			cout << "Adjancency Matrix is Empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "Index Out of Range" << endl;
		}
		else
		{
			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	void Show()
	{
		if (size <= 0)
		{
			cout << "Adjancency Matrix is Empty" << endl;
		}
		else
		{
			cout << "    ";

			for (int i = 0; i < size; i++)
			{
				cout << vertex[i] << " ";
			}

			cout << endl;

			for (int i = 0; i < size; i++)
			{
				cout << vertex[i] << " : ";

				for (int j = 0; j < size; j++)
				{
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

};

int main()
{
	AdjacencyMatrix<char> adjancencyMatrix;

	adjancencyMatrix.Insert('A');
	adjancencyMatrix.Insert('B');
	adjancencyMatrix.Insert('C');
	adjancencyMatrix.Insert('D');

	adjancencyMatrix.Connect(0, 1);
	adjancencyMatrix.Connect(0, 2);
	adjancencyMatrix.Connect(1, 2);
	adjancencyMatrix.Connect(2, 3);

	adjancencyMatrix.Show();


	return 0;
}

//   A B C D
// A 0 1 0 1
// B 0 0 1 1
// C 0 0 0 1
// D 0 0 0 0

