#include <iostream>
#include <cstring>
using namespace std;

class DynamicString {
private:
    char* data;

public:

    DynamicString(const char* text) {
        data = new char[strlen(text) + 1];
        strcpy(data, text);
    }

    DynamicString() {
        data = new char[1];
        data[0] = '\0';
    }

    ~DynamicString() {
        delete[] data;
    }

    DynamicString(const DynamicString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    DynamicString& operator=(const DynamicString& other) {

        if (this != &other) {

            delete[] data;

            data = new char[strlen(other.data) + 1];

            strcpy(data, other.data);
        }

        return *this;
    }

    int length() const {
        return strlen(data);
    }

    void print() const {
        cout << data << endl;
    }

    void setChar(int index, char c) {
        if (index >= 0 && index < length()) {
            data[index] = c;
        }
    }
};


int main() {

    DynamicString d1("ABCDE");

    cout << "d1: ";
    d1.print();

    DynamicString d2(d1);

    cout << "d2 after copy construction: ";
    d2.print();

    DynamicString d3;

    cout << "d3 before assignment: ";
    d3.print();

    d3 = d1;

    cout << "d3 after assignment: ";
    d3.print();

    d1.setChar(0, 'X');

    cout << "\nAfter modifying d1:\n";

    cout << "d1: ";
    d1.print();

    cout << "d2: ";
    d2.print();

    cout << "d3: ";
    d3.print();

    cout << "\nLengths:\n";
    cout << "Length of d1: " << d1.length() << endl;
    cout << "Length of d2: " << d2.length() << endl;
    cout << "Length of d3: " << d3.length() << endl;

    return 0;
}
