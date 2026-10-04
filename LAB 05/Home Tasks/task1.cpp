#include <iostream>
using namespace std;
// stack implemation using ll
class Node
{
public:
    Node *next;
    char ch;
    Node(char c)
    {
        ch = c;
        next = nullptr;
    }
};
class stack
{
private:
    Node *top;

public:
    stack()
    {
        top = nullptr;
    }
    bool isempty() { return top == nullptr; }
    char gettop() { return top->ch; }
    void push(char c)
    {
        Node *temp = new Node(c);

        if (top == nullptr)
        {
            top = temp;
            return;
        }
        temp->next = top;
        top = temp;
        return;
    }
    void pop()
    {
        if (!top)
        {
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        return;
    }

    ~stack()
    {
        while (top)
        {
            pop();
        }
    }
};
int getprecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return -1;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;

    return false;
}

bool isValidinfix(const string &str)
{
    int count = 0;
    for (char c : str)
    {
        if (c == '(')
        {
            count++;
        }
        if (c == ')')
        {
            count--;

            if (count < 0)
            {
                return false;
            }
        }
    }

    return count == 0;
}
string reverse(const string &str)
{
    int length = str.length();
    string reverse = "";
    for (int i = length - 1; i >= 0; i--)
    {
        reverse += str[i];
    }
    return reverse;
}
string infixprefix(string infix)
{
    string prefix = "";
    stack s;

    // reverse string
    infix = reverse(infix);

    // reverse ()
    int i = 0;
    for (char ch : infix)
    {
        if (ch == ')')
            infix[i] = '(';
        else if (ch == '(')
            infix[i] = ')';
        i++;
    }

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            prefix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isempty() && s.gettop() != '(')
            {
                prefix += s.gettop();
                s.pop();
            }
            if (!s.isempty())
                s.pop();
        }
        else if (isOperator(ch))
        {
            int prefrenceCurr = getprecedence(ch);

            while (!s.isempty() && s.gettop() != '(')
            {
                int prefrenceTop = getprecedence(s.gettop());
                if ((ch == '^' && prefrenceTop >= prefrenceCurr) ||
                    (ch != '^' && prefrenceTop > prefrenceCurr))
                {
                    prefix += s.gettop();
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push(ch);
        }
    }
    while (!s.isempty())
    {
        prefix += s.gettop();
        s.pop();
    }
    return reverse(prefix);
}

int main()
{
    string infix;
    cout << "Enter infix:";
    cin >> infix;

    if (isValidinfix(infix))
    {
        string prefix = infixprefix(infix);
        cout << "prefix :" << prefix << endl;
    }
    else
    {
        cout << "Not valid" << endl;
    }
    return 0;
}