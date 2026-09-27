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

	void insert(int pos, int value)
	{
		if (pos < 0)
		{
			return;
		}
		if (pos == 0)
		{
			Node *node = new Node(value);
			if (head == nullptr)
			{
				head = node;
				node->next = head;
				return;
			}

			Node *tail = head;
			while (tail->next != head)
			{
				tail = tail->next;
			}
			node->next = head;
			tail->next = node;
			head = node;
			return;
		}

		Node *current = head;
		for (int index = 0; index < pos - 1 && current != nullptr; index++)
		{
			current = current->next;
			if (current == head)
			{
				return;
			}
		}
		if (current == nullptr)
		{
			return;
		}

		Node *node = new Node(value);
		node->next = current->next;
		current->next = node;
	}

	void deleteValue(int value)
	{
		if (head == nullptr)
		{
			return;
		}

		Node *previous = head;
		while (previous->next != head && previous->next->data != value)
		{
			previous = previous->next;
		}

		Node *target = nullptr;
		if (head->data == value)
		{
			target = head;
			if (head->next == head)
			{
				head = nullptr;
			}
			else
			{
				Node *tail = head;
				while (tail->next != head)
				{
					tail = tail->next;
				}
				head = head->next;
				tail->next = head;
			}
		}
		else if (previous->next != head && previous->next->data == value)
		{
			target = previous->next;
			previous->next = target->next;
		}

		if (target != nullptr)
		{
			delete target;
		}
	}

	bool search(int key)
	{
		if (head == nullptr)
		{
			return false;
		}

		Node *current = head;
		do
		{
			if (current->data == key)
			{
				return true;
			}
			current = current->next;
		} while (current != head);

		return false;
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
	list.append(30);
	list.insert(1, 20);
	list.display();

	cout << boolalpha << "Search 20: " << list.search(20) << endl;
	list.deleteValue(20);
	list.display();

	return 0;
}