#include <iostream>
using namespace std;
int *resizeArray(int *arr, int newsize, int oldsize)
{
    int *newarr = new int[newsize];
    int copy = (oldsize < newsize) ? oldsize : newsize;
    for (int i = 0; i < copy; i++)
    {
        newarr[i] = arr[i];
    }
    delete[] arr;
    arr = nullptr;
    return newarr;
}
void display(int *arr, int size)
{
    cout << "\narray elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    int size;
    cout << "Enter initial size of Array:";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " elements";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int choice;

    do
    {
        cout << "\n------Menu------" << endl;
        cout << "1.Grow\n2.Shrink\n3.Display\n4.exit" << endl;
        cout << "Enter choice:";
        cin >> choice;

        if (choice == 1)
        {
            int news;
            cout << "Enter new size:";
            cin >> news;
            if (size > news)
                cout << "new size must be greater than old size\n";
            else
            {
                arr = resizeArray(arr, news, size);
                cout << "Enter remaining " << news - size << " elements" << endl;
                for (int i = size; i < news; i++)
                {
                    cin >> arr[i];
                }
                size = news;
            }
        }
        else if (choice == 2)
        {
            int news;
            cout << "Enter new size:";
            cin >> news;
            if (size < news)
                cout << "new size must be lesser than old size\n";
            else
            {
                arr = resizeArray(arr, news, size);
                size = news;
            }
        }
        else if (choice == 3)
        {
            display(arr, size);
        }

//     } while (choice != 4);
//     delete[] arr;
//     arr = nullptr;
//     return 0;
// }