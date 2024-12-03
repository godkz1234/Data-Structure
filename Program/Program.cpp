#include <iostream>

using namespace std;

#define SIZE 10

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

		for (int  i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;

			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = NULL;
			}
		}
	 }

};

int main()
{

	return 0;
}

//   A B C D
// A 0 1 0 1
// B 0 0 1 1
// C 0 0 0 1
// D 0 0 0 0

