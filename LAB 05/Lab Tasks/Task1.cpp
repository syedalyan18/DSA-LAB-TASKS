#include<iostream>
#include<string>
using namespace std;

class ToDoList{
private:
    string tasks[100];
    int top;

public:
    ToDoList(){
        top=-1;
    }

    void push(string task){
        if(top==99){
            cout<<"To-Do List is full!\n";
            return;
        }
        tasks[++top]=task;
        cout<<"Task added: "<<task<<endl;
    }

    string pop(){
        if(isEmpty()){
            return "";
        }
        return tasks[top--];
    }

    string peek(){
        if(isEmpty()){
            return "";
        }
        return tasks[top];
    }

    bool isEmpty(){
        return top==-1;
    }

    void display(){
        if(isEmpty()){
            cout<<"No pending tasks.\n";
            return;
        }

        cout<<"\nPending Tasks (most recent to oldest):\n";

        for(int i=top;i>=0;i--){
            cout<<"- "<<tasks[i]<<endl;
        }
    }

    void undoLastTask(){
        if(isEmpty()){
            cout<<"No task to remove.\n";
            return;
        }

        string removedTask=pop();
        cout<<"Removed: "<<removedTask<<endl;
    }

    void search(string task){
        if(isEmpty()){
            cout<<"The To-Do List is empty.\n";
            return;
        }

        ToDoList temp;
        bool found=false;
        int above=0;

        while(!isEmpty()){
            string current=pop();

            if(current==task){
                found=true;
                break;
            }

            temp.push(current);
            above++;
        }

        while(!temp.isEmpty()){
            push(temp.pop());
        }

        if(found){
            cout<<"Task found: "<<task<<endl;
            cout<<"Tasks above it: "<<above<<endl;
        }
        else{
            cout<<"Task not found: "<<task<<endl;
        }
    }
};

int main(){
    ToDoList todo;
    int choice;
    string task;

    do{
        cout<<"\n===== To-Do List Manager =====\n";
        cout<<"1. Add Task\n";
        cout<<"2. Remove Last Task\n";
        cout<<"3. View All Tasks\n";
        cout<<"4. Search Task\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        cin.ignore();

        switch(choice){
        case 1:
            cout<<"Enter task: ";
            getline(cin,task);
            todo.push(task);
            break;

        case 2:
            todo.undoLastTask();
            break;

        case 3:
            todo.display();
            break;

        case 4:
            cout<<"Enter task to search: ";
            getline(cin,task);
            todo.search(task);
            break;

        case 5:
            cout<<"Exiting To-Do List Manager...\n";
            break;

        default:
            cout<<"Invalid choice. Please try again.\n";
        }

    }while(choice!=5);

    return 0;
}