#include <iostream>

using namespace std;

template <typename T>
class CircleLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
public:
	CircleLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}
		size++;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;
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
			Node* deleteNode = head->next;

			if (head->next == head) // 1개이상일때
			{
				head = nullptr;
			}
			else                    // 2개이상일때
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;
			size--;
		}
	}

	void PoPBack()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;
			Node* currentNode = head;
			if (head == head->next)
			{
				head == nullptr;
			}
			else
			{

				for (int i = 0; i < size - 1; i++)
				{
					currentNode = currentNode->next;
				}

				currentNode->next = head->next;

				head = currentNode;
			}

			delete deleteNode;

			size--;
		}
	}

	void Show()
	{
		if (head != nullptr)
		{
			Node* currentNode = head->next;

			for (int i = 0; i < size; i++)
			{
				cout << currentNode->data << " ";

				currentNode = currentNode->next;
			}
		}
		cout << endl;
	}

	~CircleLinkedList()
	{
		while (head != nullptr)
		{
			PoPFront();
		}
	}
};


int main()
{
	CircleLinkedList<int> circleLinkedList;

	circleLinkedList.PushBack(10);
	circleLinkedList.PushBack(20);
	circleLinkedList.PushBack(30);

	circleLinkedList.PushFront(5);

	circleLinkedList.PoPFront();
	circleLinkedList.PoPBack();

	circleLinkedList.Show();

	return 0;
};
