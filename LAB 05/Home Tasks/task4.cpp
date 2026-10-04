#include <cctype>
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int number) : value(number), next(nullptr) {}
};

class Stack
{
private:
    Node *topNode;

public:
    Stack() : topNode(nullptr) {}

    bool isEmpty() const
    {
        return topNode == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    bool pop(int &value)
    {
        if (isEmpty())
        {
            return false;
        }

        Node *oldTop = topNode;
        value = oldTop->value;
        topNode = oldTop->next;
        delete oldTop;
        return true;
    }

    ~Stack()
    {
        int value;
        while (pop(value))
        {
        }
    }
};

bool evaluatePostfix(const string &expression, int &result)
{
    Stack values;

    for (char symbol : expression)
    {
        if (isspace(static_cast<unsigned char>(symbol)))
        {
            continue;
        }

        if (isdigit(static_cast<unsigned char>(symbol)))
        {
            values.push(symbol - '0');
            continue;
        }

        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
        {
            return false;
        }

        int right;
        int left;
        if (!values.pop(right) || !values.pop(left))
        {
            return false;
        }

        if (symbol == '/' && right == 0)
        {
            return false;
        }

        switch (symbol)
        {
        case '+':
            values.push(left + right);
            break;
        case '-':
            values.push(left - right);
            break;
        case '*':
            values.push(left * right);
            break;
        case '/':
            values.push(left / right);
            break;
        }
    }

    if (!values.pop(result) || !values.isEmpty())
    {
        return false;
    }

    return true;
}

int main()
{
    string expression;
    cout << "Input: ";
    getline(cin, expression);

    int result;
    if (evaluatePostfix(expression, result))
    {
        cout << "Output: " << result << endl;
    }
    else
    {
        cout << "Error: Malformed expression" << endl;
    }

    return 0;
}
