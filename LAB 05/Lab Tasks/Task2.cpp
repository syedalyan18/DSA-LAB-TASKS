#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    string url;
    Node(string s) {
        url = s;
        next = NULL;
    }
};

class stack {
private:
    Node* top;
public:
    stack() {
        top = NULL;
    }
    
    void visit(string s) {
        Node* newval = new Node(s);
        if (!top) {
            top = newval;
             cout << "Now at:" << top->url << endl;
            return;
        }
        newval->next = top;
        top = newval;
        cout << "Now at:" << top->url << endl;
    }
    
    void goback() {
        if (!top) {
            cout << "no previous history" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "back to: " << temp->url << endl;
        delete temp;
    }
    
  
    ~stack() {
        while (top) {
            goback();
        }
    }
};

int main() {
    stack s;
    s.visit("google.com");
    s.visit("github.com");
    s.visit("anas.com");
    s.goback();
    s.goback();
    s.goback();
    return 0;
}
