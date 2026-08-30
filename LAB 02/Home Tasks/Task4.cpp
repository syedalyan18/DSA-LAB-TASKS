#include <iostream>
using namespace std;

class DynamicSafeArray {
private:
    int *array;
    int count;
    int cap;

    void deepCopy(const DynamicSafeArray &other) {
        cap = other.cap;
        count = other.count;
        array = new int[cap];
        for (int i = 0; i < count; i++) {
            array[i] = other.array[i];
        }
    }

public:
    DynamicSafeArray(int cap = 2) {
        this->cap = cap;
        array = new int[cap];
        count = 0;
    }

    ~DynamicSafeArray() {
        delete[] array;
    }

    DynamicSafeArray(const DynamicSafeArray &other) {
        deepCopy(other);
    }

    DynamicSafeArray& operator=(const DynamicSafeArray &other) {
        if (this != &other) {
            delete[] array;
            deepCopy(other);
        }
        return *this;
    }

    void resize() {
        cap *= 2;
        int *newarray = new int[cap];
        for (int i = 0; i < count; i++) {
            newarray[i] = array[i];
        }
        delete[] array;
        array = newarray;
    }

    void pushBack(int val) {
        if (count == cap) {
            resize();
        }
        array[count++] = val;
    }

    void set(int pos, int val) {
        if (pos < 0 || pos >= count) {
            cout << "Boundary error\n";
            return;
        }
        array[pos] = val;
    }

    int get(int pos) {
        if (pos < 0 || pos >= count) {
            cout << "Boundary error\n";
            return -1;
        }
        return array[pos];
    }

    bool removeAt(int pos) {
        if (pos < 0 || pos >= count) {
            cout << "Boundary error\n";
            return false;
        }
        for (int i = pos; i < count - 1; i++) {
            array[i] = array[i + 1];
        }
        count--;
        return true;
    }

    void display() const {
        cout << "Array: ";
        for (int i = 0; i < count; i++) {
            cout << array[i] << " ";
        }
        cout << " (count=" << count << ", cap=" << cap << ")" << endl;
    }

    int getCount() const { return count; }
    int getCapacity() const { return cap; }
};

int main() {
    cout << "=== Creating DynamicSafeArray with capacity 2 ===" << endl;
    DynamicSafeArray arr(2);

    cout << "\n=== Pushing 6 elements (will trigger resize) ===" << endl;
    arr.pushBack(10);
    arr.display();
    arr.pushBack(20);
    arr.display();
    arr.pushBack(30);
    arr.display();
    arr.pushBack(40);
    arr.display();
    arr.pushBack(50);
    arr.display();
    arr.pushBack(60);
    arr.display();

    cout << "\n=== Testing get/set ===" << endl;
    cout << "get(2): " << arr.get(2) << endl;
    arr.set(2, 999);
    cout << "After set(2, 999): ";
    arr.display();

    cout << "\n=== Testing boundary errors ===" << endl;
    cout << "get(10): " << arr.get(10) << endl;
    arr.set(10, 5);

    cout << "\n=== Removing element at index 2 ===" << endl;
    arr.removeAt(2);
    arr.display();

    cout << "\n=== Testing copy constructor ===" << endl;
    DynamicSafeArray arr2 = arr;
    cout << "arr2 (copy of arr): ";
    arr2.display();

    cout << "\n=== Modifying arr2, arr should be unchanged ===" << endl;
    arr2.set(0, 77);
    cout << "arr:  ";
    arr.display();
    cout << "arr2: ";
    arr2.display();

    cout << "\n=== Testing copy assignment ===" << endl;
    DynamicSafeArray arr3(1);
    arr3 = arr;
    cout << "arr3 (assigned from arr): ";
    arr3.display();

    arr3.set(1, 888);
//     cout << "After modifying arr3:" << endl;
//     cout << "arr:  ";
//     arr.display();
//     cout << "arr3: ";
//     arr3.display();

//     return 0;
// }