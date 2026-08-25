#include <iostream>
using namespace std;

void display(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int rows, cols;
    cout << "Enter rows and cols:";
    cin >> rows >> cols;
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    int **Tmatrix = new int *[cols];
    for (int i = 0; i < cols; i++)
    {
        Tmatrix[i] = new int[rows];
    }

    // input
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter elements of row " << i + 1 << " :";
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // transpose of matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Tmatrix[j][i] = matrix[i][j];
        }
    }

    int sumR[rows] = {0};
    int sumC[cols] = {0};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sumR[i] += matrix[i][j];
            sumC[j] += matrix[i][j];
        }
    }

    display(matrix, rows, cols);
    display(Tmatrix, cols, rows);
    cout << "Sum of each " << rows << " rows:";
    for (int i = 0; i < rows; i++)
    {
        cout << sumR[i] << " ";
    }
    cout << endl;
    cout << "Sum of each " << cols << " Cols:";
    for (int i = 0; i < cols; i++)
    {
        cout << sumC[i] << " ";
    }
    cout << endl;

    // delete
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    for (int i = 0; i < cols; i++)
    {
        delete[] Tmatrix[i];
    }
    delete[] matrix;
    delete[] Tmatrix;
    return 0;
}