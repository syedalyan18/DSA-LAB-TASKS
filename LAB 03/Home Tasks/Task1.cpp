#include <iostream>
using namespace std;

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int i = j;

            while (i >= gap && arr[i - gap] > temp)
            {
                arr[i] = arr[i - gap];
                i -= gap;
            }

            arr[i] = temp;
        }

        cout << "After gap " << gap << ": ";
        displayArray(arr, n);
    }
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = 5;

    cout << "Original array: ";
    displayArray(arr, n);

    shellSort(arr, n);

    cout << "Final sorted array: ";
    displayArray(arr, n);

    return 0;
}

//Shell Sort improves on ordinary Insertion Sort by comparing elements that are far apart using gaps. This moves elements closer to their correct positions faster, so the final insertion-sort pass has much less work to do.