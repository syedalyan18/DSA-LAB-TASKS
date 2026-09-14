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

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Binary Search
int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    const int MAX = 100;

    int original[MAX];
    int sorted[MAX];

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];

        // Make a copy for sorting
        sorted[i] = original[i];
    }

    bool isSorted = false;
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Sort the array\n";
        cout << "2. Binary Search on sorted array\n";
        cout << "3. Linear Search on original array\n";
        cout << "4. Display current array and Exit\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int sortChoice;

                cout << "\nChoose Sorting Algorithm:\n";
                cout << "1. Bubble Sort\n";
                cout << "2. Selection Sort\n";
                cout << "3. Insertion Sort\n";
                cout << "Enter your choice: ";
                cin >> sortChoice;

                // Reset sorted array from original array
                for (int i = 0; i < n; i++)
                {
                    sorted[i] = original[i];
                }

                if (sortChoice == 1)
                {
                    bubbleSort(sorted, n);
                    cout << "Array sorted using Bubble Sort.\n";
                }
                else if (sortChoice == 2)
                {
                    selectionSort(sorted, n);
                    cout << "Array sorted using Selection Sort.\n";
                }
                else if (sortChoice == 3)
                {
                    insertionSort(sorted, n);
                    cout << "Array sorted using Insertion Sort.\n";
                }
                else
                {
                    cout << "Invalid sorting choice.\n";
                    break;
                }

                isSorted = true;

                cout << "Sorted array: ";
                displayArray(sorted, n);

                break;
            }

            case 2:
            {
                if (!isSorted)
                {
                    cout << "Please sort the array first using Option 1.\n";
                    break;
                }

                int key;

                cout << "Enter the key to search: ";
                cin >> key;

                int result = binarySearch(sorted, n, key);

                if (result != -1)
                {
                    cout << "Key found at index " << result
                         << " in the sorted array.\n";
                }
                else
                {
                    cout << "Key not found in the sorted array.\n";
                }

                break;
            }

            case 3:
            {
                int key;

                cout << "Enter the key to search: ";
                cin >> key;

                int result = linearSearch(original, n, key);

                if (result != -1)
                {
                    cout << "Key found at index " << result
                         << " in the original array.\n";
                }
                else
                {
                    cout << "Key not found in the original array.\n";
                }

                break;
            }

            case 4:
            {
                cout << "\nCurrent array: ";

                if (isSorted)
                {
                    displayArray(sorted, n);
                }
                else
                {
                    displayArray(original, n);
                }

                cout << "Program exiting...\n";
                break;
            }

            default:
            {
                cout << "Invalid choice. Please try again.\n";
            }
        }

    } while (choice != 4);

    return 0;
}