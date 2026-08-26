#include <iostream>
using namespace std;
class SafeArray
{
private:
    int *arr;
    int size;

public:
    SafeArray(int n)
    {
        size = n;
        arr = new int[size];
    }
    void set(int pos, int val)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Boundary Error" << endl;
        }
        else
        {
            arr[pos] = val;
        }
    }
    int get(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Boundary Error" << endl;
            return -1;
        }

        return arr[pos];
    }
    void display() const
    {
        cout << "\narray elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~SafeArray(){
        delete [] arr;
        arr = nullptr;
    }
};
int main()
{
    SafeArray arr(5);

    for (int i = 0; i < 5; i++)
    {
        arr.set(i, (i + 1) * 10);
    }

    arr.display();
    cout << "Values read from valid positions: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr.get(i) << " ";
    }
    cout << endl;

//     cout << "Writing at position 10: ";
//     arr.set(10, 100);
//     cout << "Reading at position -1: " << arr.get(-1) << endl;

//     return 0;
// }