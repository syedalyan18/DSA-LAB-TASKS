#include <iostream>
using namespace std;
class Queue{
	public:
		int rear=-1;
		int front=-1;
		string names[100];
		void enqueue(string t){
			rear=(rear+1)%100;
			if (front == -1) {
             front = 0;
            }
			names[rear]=t;
			cout<<t<<" added to queue"<<endl;
			return;
		}
		void dequeue(){
			if(front<=rear){
				cout<<"Served: "<<names[front]<<endl;
				front=(front+1)%100;
				return;
			}
			cout<<"Empty"<<endl;
		}
		void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int left = front, right = rear;
        while (true) {
            cout << names[left] << endl;
            if (left == right) break;
            left = (left + 1) % 100;
        }
    }
};
int main(){
	Queue q;
    q.enqueue("Ali");
    q.enqueue("alyan");
    q.enqueue("Anas");
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}