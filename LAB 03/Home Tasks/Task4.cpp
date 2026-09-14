
#include <iostream>
using namespace std;
 

unsigned long lcgSeed = 88172645463325252UL;
 
int nextRandom(int maxExclusive) {
    lcgSeed = lcgSeed * 6364136223846793005UL + 1442695040888963407UL;
    unsigned long value = (lcgSeed >> 33); // take upper bits for better randomness
    return (int)(value % (unsigned long)maxExclusive);
}
 
// ---------- Sorting Algorithms (operate on plain int arrays) ----------
// Each returns its operation count (comparisons + swaps) via reference parameters,
// used as our stand-in for "running time" since no timing library is available.
 
void bubbleSort(int arr[], int n, long& comparisons, long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
 
void selectionSort(int arr[], int n, long& comparisons, long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
        swaps++;
    }
}
 
void insertionSort(int arr[], int n, long& comparisons, long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        if (j >= 0) comparisons++; // count the comparison that ended the while loop
        arr[j + 1] = key;
    }
}
 
void shellSort(int arr[], int n, long& comparisons, long& swaps) {
    comparisons = 0;
    swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && (comparisons++, arr[j - gap] > temp)) {
                arr[j] = arr[j - gap];
                swaps++;
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
 
int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1) return 1;
    return gap;
}
 
void combSort(int arr[], int n, long& comparisons, long& swaps) {
    comparisons = 0;
    swaps = 0;
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
}
 
// ---------- Helper functions ----------
 
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = nextRandom(1000000);
}
 
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = source[i];
}
 
void sortAscendingHelper(int arr[], int n) {
    // simple insertion sort used only to build "already sorted" / "reverse sorted" test data
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
 
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
 
// Runs a sort on a COPY of arr (so the original is untouched) and reports total operations.
long runSort(void (*sortFunc)(int[], int, long&, long&), int arr[], int n) {
    int* copy = new int[n];
    copyArray(arr, copy, n);
 
    long comparisons = 0, swaps = 0;
    sortFunc(copy, n, comparisons, swaps);
 
    delete[] copy;
    return comparisons + swaps;
}
 
void runSizeTest(int n) {
    int* arr = new int[n];
    generateRandomArray(arr, n);
 
    cout << n << "\t"
         << runSort(bubbleSort, arr, n) << "\t"
         << runSort(selectionSort, arr, n) << "\t"
         << runSort(insertionSort, arr, n) << "\t"
         << runSort(shellSort, arr, n) << "\t"
         << runSort(combSort, arr, n) << endl;
 
    delete[] arr;
}
 
int main() {
    cout << "NOTE: No timing library is available with only <iostream>, so\n";
    cout << "'operations' (comparisons + swaps) is used as the performance metric\n";
    cout << "instead of milliseconds. Fewer operations = faster algorithm.\n\n";
 
    cout << "=== Part 1: Random arrays of increasing size (total operations) ===\n";
    cout << "n\tBubble\tSelection\tInsertion\tShell\tComb\n";
 
    int sizes[] = {100, 1000, 10000, 50000};
    for (int i = 0; i < 4; i++) {
        runSizeTest(sizes[i]);
    }
 
    cout << "\n=== Part 2: n = 10,000, different input orders (total operations) ===\n";
    int n = 10000;
 
    int* randomArr = new int[n];
    generateRandomArray(randomArr, n);
 
    int* sortedArr = new int[n];
    copyArray(randomArr, sortedArr, n);
    sortAscendingHelper(sortedArr, n);
 
    int* reverseArr = new int[n];
    copyArray(sortedArr, reverseArr, n);
    reverseArray(reverseArr, n);
 
    cout << "Order\t\tBubble\tSelection\tInsertion\tShell\tComb\n";
 
    cout << "Random\t\t"
         << runSort(bubbleSort, randomArr, n) << "\t"
         << runSort(selectionSort, randomArr, n) << "\t"
         << runSort(insertionSort, randomArr, n) << "\t"
         << runSort(shellSort, randomArr, n) << "\t"
         << runSort(combSort, randomArr, n) << endl;
 
    cout << "Sorted\t\t"
         << runSort(bubbleSort, sortedArr, n) << "\t"
         << runSort(selectionSort, sortedArr, n) << "\t"
         << runSort(insertionSort, sortedArr, n) << "\t"
         << runSort(shellSort, sortedArr, n) << "\t"
         << runSort(combSort, sortedArr, n) << endl;
 
    cout << "Reverse\t\t"
         << runSort(bubbleSort, reverseArr, n) << "\t"
         << runSort(selectionSort, reverseArr, n) << "\t"
         << runSort(insertionSort, reverseArr, n) << "\t"
         << runSort(shellSort, reverseArr, n) << "\t"
         << runSort(combSort, reverseArr, n) << endl;
 
    delete[] randomArr;
    delete[] sortedArr;
    delete[] reverseArr;
 
    return 0;
}

