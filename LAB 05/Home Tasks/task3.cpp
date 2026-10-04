#include <iostream>
#include <string>
using namespace std;

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

bool isBalanced(string expr){
    stack s;
    for(char c : expr){
        if(c == '(' || c == '[' || c == '{'){
            s.push(c);
        }else if (c == ')' || c == ']' || c == '}'){
            if(s.isempty()){
                return false;
            }

            char opening = s.gettop();
            bool matches = (c == ')' && opening == '(') ||
                           (c == ']' && opening == '[') ||
                           (c == '}' && opening == '{');
            if(!matches){
                return false;
            }
            s.pop();
        }
    }
    return s.isempty();
}
int main(){
    string expr;
    cout << "Input:";
    cin >> expr;
    cout << (isBalanced(expr) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}