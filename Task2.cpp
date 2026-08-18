#include <iostream>
using namespace std;

class Rectangle {
private:
    int* width;
    int* height;

public:
  
    Rectangle(int w, int h) {
        width = new int(w);  
        height = new int(h);
        cout << "Rectangle created with width=" << *width 
             << " and height=" << *height << endl;
    }

    int area() const {
        return (*width) * (*height);
    }

    void display() const {
        cout << "Width: " << *width << endl;
        cout << "Height: " << *height << endl;
        cout << "Area: " << area() << endl;
    }

    ~Rectangle() {
        delete width;
        delete height;
        cout << "Rectangle destroyed" << endl;
    }
};

int main() {
    Rectangle rect(10, 5); 
    rect.display();        
    return 0;
}