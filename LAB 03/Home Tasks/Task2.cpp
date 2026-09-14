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

void combSort(int arr[], int n, long long &comparisons, long long &swaps)
{
    int gap = n;
    const double shrink = 1.3;
    bool swapped = true;

    comparisons = 0;
    swaps = 0;

    while (gap != 1 || swapped)
    {
        gap = (int)(gap / shrink);

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            comparisons++;

            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;

                swaps++;
                swapped = true;
            }
        }
    }
}

void bubbleSort(int arr[], int n, long long &comparisons, long long &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    const int n = 20;

    int combArray[n];
    int bubbleArray[n];

    // Reverse-sorted array
    for (int i = 0; i < n; i++)
    {
        combArray[i] = n - i;
        bubbleArray[i] = n - i;
    }

    long long combComparisons, combSwaps;
    long long bubbleComparisons, bubbleSwaps;

    combSort(combArray, n, combComparisons, combSwaps);
    bubbleSort(bubbleArray, n, bubbleComparisons, bubbleSwaps);

    cout << "Reverse-sorted array of 20 elements\n\n";

    cout << "Comb Sort:\n";
    cout << "Comparisons = " << combComparisons << endl;
    cout << "Swaps       = " << combSwaps << endl;

    cout << "\nBubble Sort:\n";
    cout << "Comparisons = " << bubbleComparisons << endl;
    cout << "Swaps       = " << bubbleSwaps << endl;

    cout << "\nSorted array using Comb Sort: ";
    displayArray(combArray, n);

    return 0;
}