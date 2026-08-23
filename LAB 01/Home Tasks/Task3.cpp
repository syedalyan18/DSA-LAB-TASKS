#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        cout << "Resized to capacity: " << capacity << endl;
    }

    void deepCopy(const DynamicArray& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

public:
    DynamicArray() : size(0), capacity(2) {
        cout << "Constructor called" << endl;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        cout << "Destructor called" << endl;
        delete[] arr;
    }

    DynamicArray(const DynamicArray& other) {
        cout << "Copy constructor called" << endl;
        deepCopy(other);
    }

    DynamicArray& operator=(const DynamicArray& other) {
        cout << "Copy assignment operator called" << endl;
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        deepCopy(other);
        return *this;
    }

    void pushBack(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        ++size;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds" << endl;
            static int dummy = 0;
            return dummy;
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== Creating DynamicArray and pushing 6 values ===" << endl;
    DynamicArray arr;
    arr.pushBack(10);
    arr.pushBack(20);
    arr.pushBack(30);
    arr.pushBack(40);
    arr.pushBack(50);
    arr.pushBack(60);

    cout << "\n=== Array contents ===" << endl;
    arr.print();

    cout << "\n=== Copy construction ===" << endl;
    DynamicArray arr2(arr);
    cout << "arr2 (copy of arr): ";
    arr2.print();

    cout << "\n=== Modifying arr2 ===" << endl;
    arr2[0] = 999;
    arr2[2] = 888;

    cout << "arr (should be unchanged): ";
    arr.print();
    cout << "arr2 (modified): ";
    arr2.print();

    cout << "\n=== Copy assignment ===" << endl;
    DynamicArray arr3;
    arr3 = arr;
    cout << "arr3 (assigned from arr): ";
    arr3.print();

    cout << "\n=== Modifying arr3 ===" << endl;
    arr3[1] = 777;
    cout << "arr (should be unchanged): ";
    arr.print();
    cout << "arr3 (modified): ";
    arr3.print();

    return 0;
}