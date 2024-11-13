#include <iostream>

using namespace std;

template <typename T>
class SingleLinkedList 
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

		int size;
		Node * head;

public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;
	};

	void PushFront(T data)
	{
		if (head == nullptr)
		{
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node * newNode = new Node;

			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}

		size++;
		
	}
	void PoPFront()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node * deleteNode = head;
			
			head = deleteNode->next;

			delete deleteNode;
			
			size--;
		}
	}
	void PushBack(T data)
	{
		if (head == nullptr)
		{
			head = new Node;

			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node* currentNode = head;

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			Node * newNode = new Node;

			currentNode->next = newNode;

			newNode->data = data;
			newNode->next = nullptr;
		}

		size++;
	}
	void Show()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << std::endl;
		}

		Node* currentNode = head;

		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}

		cout << std::endl;
	}
	void PoPBack()
	{
		Node* deleteNode = head;

		if (head->next == nullptr)
		{
			delete deleteNode;
		}
		else
		{
		
		}
	}
};

int main()
{
	SingleLinkedList<int> singleLinkedList;

	singleLinkedList.PushFront(10);
	singleLinkedList.PushFront(20); // [20]<------- [10]

	// [20] - [10]

	singleLinkedList.PushBack(5);
	singleLinkedList.PushBack(0);

	// [20] - [10] - [5] - [0]  

	singleLinkedList.Show();

	singleLinkedList.PoPFront();
	singleLinkedList.PoPFront();

	return 0;
}