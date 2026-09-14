#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key, int &iterations)
{
    int low = 0;
    int high = n - 1;

    iterations = 0;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        iterations++;

        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                return low;

            return -1;
        }

        int pos = low +
                  ((key - arr[low]) * (high - low))
                  / (arr[high] - arr[low]);

        if (arr[pos] == key)
        {
            return pos;
        }

        if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return -1;
}

int main()
{
    // Uniformly distributed array
    int arr[20];

    for (int i = 0; i < 20; i++)
    {
        arr[i] = (i + 1) * 5;
    }

    int iterations;
    int result;

    cout << "Uniformly distributed array:\n";

    result = interpolationSearch(arr, 20, 50, iterations);

    cout << "Searching for 50\n";

    if (result != -1)
        cout << "50 found at index " << result << endl;
    else
        cout << "50 not found\n";

    cout << "Iterations: " << iterations << endl;

    result = interpolationSearch(arr, 20, 55, iterations);

    cout << "\nSearching for 55\n";

    if (result != -1)
        cout << "55 found at index " << result << endl;
    else
        cout << "55 not found\n";

    cout << "Iterations: " << iterations << endl;


    // Non-uniform array
    int nonUniform[] = {1, 2, 3, 4, 5, 1000};

    cout << "\nNon-uniform array:\n";

    result = interpolationSearch(
        nonUniform,
        6,
        1000,
        iterations
    );

    cout << "Searching for 1000\n";

    if (result != -1)
        cout << "1000 found at index " << result << endl;
    else
        cout << "1000 not found\n";

    cout << "Interpolation Search iterations: "
         << iterations << endl;

    return 0;
}

//Interpolation Search estimates where the key should be located based on the values in the array. When the data is uniformly distributed, this estimate is very effective, giving an average complexity of O(log log n). With non-uniform data, the estimated position can be poor, causing the algorithm to approach O(n) in the worst case.