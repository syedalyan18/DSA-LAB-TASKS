#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int val;
    Node(int c)
    {
        val = c;
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
    int gettop() { return top->val; }
    void push(int value)
    {
        Node *temp = new Node(value);

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

class Queue{
    private:
    stack stackIn;
    stack stackOut;
    public:
    Queue(){}
    void enqueue(int val){
        stackIn.push(val);
        cout << "Enqueued:" << val << endl;
    }
    void dequeue(){
        if(stackOut.isempty()){
            while(!stackIn.isempty()){
                stackOut.push(stackIn.gettop());
                stackIn.pop();
            }
        }

        if(!stackOut.isempty()){
            cout << "dequeued:" << stackOut.gettop() << endl;
            stackOut.pop();
        }else{
            cout << "Queue is empty\n";
        }
        return;
    }
};

int main(){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.dequeue();
    q1.enqueue(4);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    return 0;
}