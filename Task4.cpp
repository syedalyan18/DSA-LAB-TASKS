#include <iostream>
using namespace std;

class Rectangle {
public: // temporarily public for pointer address check
    int* width;
    int* height;

    Rectangle(int w, int h) {
        width = new int(w);
        height = new int(h);
        cout << "Rectangle created with width=" << *width 
             << " and height=" << *height << endl;
    }

    // Deep Copy Constructor
    Rectangle(const Rectangle &other) {
        width = new int(*other.width);  
        height = new int(*other.height); 
        cout << "Rectangle copied with width=" << *width 
             << " and height=" << *height << endl;
    }

    void display() const {
        cout << "Width: " << *width << endl;
        cout << "Height: " << *height << endl;
        cout << "Area: " << (*width) * (*height) << endl;
    }

    ~Rectangle() {
        delete width;
        delete height;
        cout << "Rectangle destroyed" << endl;
    }
};

int main() {
    Rectangle r1(4, 5);  
    Rectangle r2 = r1;   

    cout << "\nAddresses of width pointers:" << endl;
    cout << "r1.width = " << r1.width << endl;
    cout << "r2.width = " << r2.width << endl;

    *(r2.width) = 10;
    cout << "\nAfter modifying r2.width:" << endl;
    r1.display(); 
    r2.display();  

    return 0;
}
