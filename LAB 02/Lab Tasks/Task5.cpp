#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    if (rows <= 0)
    {
        cout << "Number of rows must be positive." << endl;
        return 1;
    }

    int **jaggedArray = new int *[rows];
    int *rowSize = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter size of row " << i + 1 << " :";
        cin >> rowSize[i];
        if (rowSize[i] <= 0)
        {
            cout << "Row size must be positive." << endl;
            delete[] rowSize;
            delete[] jaggedArray;
            return 1;
        }
        jaggedArray[i] = new int[rowSize[i]];
    }

    // input
    int *sumRows = new int[rows]();
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter " << rowSize[i] << " Elements of row " << i + 1 << " :";
        for (int j = 0; j < rowSize[i]; j++)
        {
            cin >> jaggedArray[i][j];
            sumRows[i] += jaggedArray[i][j];
        }
    }

    int max = rowSize[0];
    int min = rowSize[0];
    int maxRow = 0;
    int minRow = 0;
    for (int i = 1; i < rows; i++)
    {
        if (max < rowSize[i])
        {
            max = rowSize[i];
            maxRow = i;
        }
        if (min > rowSize[i])
        {
            min = rowSize[i];
            minRow = i;
        }
    }

    // display
    for (int i = 0; i < rows; i++)
    {
        cout << "Elements of row " << i + 1 << " :";
        for (int j = 0; j < rowSize[i]; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        cout << "Row sum of " << i + 1 << ": " << sumRows[i] << endl;
        cout << "Row avg of " << i + 1 << ": " << (float)sumRows[i] / rowSize[i] << endl;
    }

    cout << "Row " << maxRow + 1 << " has most elements" << endl;
    cout << "Row " << minRow + 1 << " has least elements" << endl;

//     for (int i = 0; i < rows; i++)
//     {
//         delete[] jaggedArray[i];
//     }
//     delete[] jaggedArray;
//     delete[] rowSize;
//     delete[] sumRows;
//     return 0;
// }