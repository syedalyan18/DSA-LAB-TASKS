#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int value)
	{
		data = value;
		next = nullptr;
	}
};

class CircularLinkedList
{
private:
	Node *head;

public:
	CircularLinkedList()
	{
		head = nullptr;
	}

	void append(int value)
	{
		Node *node = new Node(value);

		if (head == nullptr)
		{
			head = node;
			node->next = head;
			return;
		}

		Node *current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		current->next = node;
		node->next = head;
	}

	void display()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}

		Node *current = head;
		do
		{
			cout << current->data << " ";
			current = current->next;
		} while (current != head);

		cout << endl;
	}
};

int main()
{
	CircularLinkedList list;
	list.append(10);
	list.append(20);
	list.append(30);
	list.display();

	return 0;
}