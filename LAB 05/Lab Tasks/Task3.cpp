// infix to post fix

#include <iostream>
using namespace std;
// stack implementation
class Node
{
public:
    Node *next;
    char ch;
    Node(char c)
    {
        ch = c;
        next = NULL;
    }
};

class stack
{
private:
    Node *topNode;

public:
    stack()
    {
        topNode = NULL;
    }

    void push(char c)
    {
        Node *newval = new Node(c);
        if (!topNode)
        {
            topNode = newval;
            return;
        }
        newval->next = topNode;
        topNode = newval;
    }

    void pop()
    {
        if (!topNode)
        {
            return;
        }
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    char top()
    {
        return topNode->ch;
    }
    bool isempty()
    {
        return topNode == nullptr;
    }
    ~stack()
    {
        while (topNode)
        {
            pop();
        }
    }
};
// helper for ops precedence
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

bool isValidinfix(string str)
{
    int balance = 0;

    for (char ch : str)
    {
        if (ch == '(')
        {
            balance++;
        }
        if (ch == ')')
        {
            balance--;

            if (balance < 0)
            {
                return false;
            }
        }
    }
    return balance == 0;
}
