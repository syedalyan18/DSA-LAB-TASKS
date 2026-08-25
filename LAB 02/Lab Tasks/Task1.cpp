#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Size of array:";
    cin >> n;
    int sum = 0;
    int *arr = new int[n];
    cout << "Enter " << n << " elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    float avg = (float)sum / n;
    cout << "Sum: " << sum << " Max: " << max << " Min: " << min << " Avg: " << avg << endl;
    delete[] arr;
    arr = nullptr;
    return 0;
}