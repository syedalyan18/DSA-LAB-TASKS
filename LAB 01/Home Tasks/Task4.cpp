#include <iostream>
using namespace std;

class Buffer {
private:
    int* data;
    int length;

public:
    Buffer(int len) {
        cout << "Constructor called" << endl;
        length = len;
        data = new int[length];
        for (int i = 0; i < length; i++) data[i] = 0;
    }

    void setValue(int index, int value) {
        if (index >= 0 && index < length) {
            data[index] = value;
        }
    }

    void display() const {
        for (int i = 0; i < length; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    ~Buffer() {
        cout << "Destructor called" << endl;
        delete[] data;
    }

    // Deep-copy copy constructor
    Buffer(const Buffer& other) {
        cout << "Copy constructor called" << endl;
        length = other.length;
        data = new int[length];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    // Deep-copy copy assignment operator
    Buffer& operator=(const Buffer& other) {
        cout << "Copy assignment operator called" << endl;
        if (this == &other) {
            return *this;
        }
        delete[] data;
        length = other.length;
        data = new int[length];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
};

int main() {
    cout << "=== Creating b1 ===" << endl;
    Buffer b1(5);
    b1.setValue(0, 10);

    cout << "\n=== Copy construction b2 = b1 ===" << endl;
    Buffer b2 = b1;

    cout << "\n=== Modifying b2[1] = 20 ===" << endl;
    b2.setValue(1, 20);

    cout << "\n=== b1 display (should show 10 0 0 0 0) ===" << endl;
    b1.display();

    cout << "\n=== b2 display (should show 10 20 0 0 0) ===" << endl;
    b2.display();

    cout << "\n=== Copy assignment test ===" << endl;
    Buffer b3(3);
    b3 = b1;
    cout << "b3 (copy assigned from b1): ";
    b3.display();

    b3.setValue(0, 999);
    cout << "After modifying b3[0] = 999:" << endl;
    cout << "b1: ";
    b1.display();
    cout << "b3: ";
    b3.display();

    return 0;
}