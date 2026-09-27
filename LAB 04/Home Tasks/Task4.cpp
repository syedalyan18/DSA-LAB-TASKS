#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL
{
private:
    Node *head;
    Node *tail;

public:
    DLL()
    {
        head = tail = nullptr;
    }

    void insertAtStart(int val)
    {
        Node *n = new Node(val);

        if (!head && !tail)
        {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }
    void insertAtEnd(int val)
    {
        Node *n = new Node(val);
        if (!head && !tail)
        {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos < 0)
        {
            return;
        }
        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node *current = head;
        for (int index = 0; index < pos - 1 && current != nullptr; index++)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            return;
        }
        if (current == tail)
        {
            insertAtEnd(val);
            return;
        }

        Node *node = new Node(val);
        node->next = current->next;
        node->prev = current;
        current->next->prev = node;
        current->next = node;
    }

    void deleteFromStart()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd()
    {
        if (tail == nullptr)
        {
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail == nullptr)
        {
            head = nullptr;
        }
        else
        {
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteValue(int val)
    {
        Node *current = head;
        while (current != nullptr && current->data != val)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << val << " was not found" << endl;
            return;
        }
        if (current == head)
        {
            deleteFromStart();
        }
        else if (current == tail)
        {
            deleteFromEnd();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    void reverse(){
        if (head == nullptr){
            return;
        }
        Node *current = head;

        while (current != nullptr)
        {
            Node *next = current->next;
            current->next = current->prev;
            current->prev = next;
            current = next;
        }
        Node *temp = head;
        head = tail;
        tail = temp;
        
    }

    void displayForward()
    {
        if (!head && !tail)
        {
            return;
        }

        Node *cur = head;

        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }

        cout << endl;
    }
    void displayBackward()
    {
        if (!head && !tail)
        {
            return;
        }

        Node *cur = tail;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->prev;
        }
        cout << endl;
    }
};

int main()
{
    DLL list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.displayForward();
    list.reverse();
    list.displayForward();
    list.displayBackward();
    return 0;
}