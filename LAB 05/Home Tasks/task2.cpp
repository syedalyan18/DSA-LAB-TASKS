/*
    This linear queue reports full when rear reaches the last array index, even
    when dequeuing has left unused slots at the front. A circular queue reuses
    those slots by wrapping rear back to the beginning of the array.
*/

#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int *arr;
    int N;

public:
    Queue(int n)
    {
        N = n;
        front  = 0;
        rear = -1;
        arr = new int[N];
    }

    bool isFull(){ return rear == N - 1;}
    bool isEmpty() { return front > rear;}

    void enqueue(int val){
        if(isFull()){
            cout << "Queue is FULL\n";
            return;
        }
        arr[++rear] = val;
        cout << "Enqueue:" << arr[rear] << endl;
        return;
    }
    void dequeue(){
        if(isEmpty()){
           cout <<"Queue is empty\n";
           return;
        }
        cout << "Dequeued:" << arr[front] << endl;
        front++;
    }
    ~Queue(){
        delete [] arr;
    }
};

int main(){
    Queue q1(6);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(60);
    q1.enqueue(70);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    return 0;
}