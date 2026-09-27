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

    void displayForward()
    {
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
    list.displayForward();
    list.displayBackward();
    return 0;
}