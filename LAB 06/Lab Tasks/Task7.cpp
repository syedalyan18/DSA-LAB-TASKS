#include <iostream>
using namespace std;


template <int N>
bool isSafe(int (&arr)[N][N], int x, int y, int n, int (&solArr)[N][N])
{
    if (x < n && y < n && x >= 0 && y >= 0 && arr[x][y] == 1 && solArr[x][y] == 0)
    {
        return true;
    }
    return false;
}

template <int N>
bool ratinMaze(int (&arr)[N][N], int x, int y, int n, int (&solArr)[N][N])
{
    if ((x == (n - 1)) && (y == (n - 1)))
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, solArr))
    {
        solArr[x][y] = 1;

        if (ratinMaze(arr, x + 1, y, n, solArr))
        {
            return true;
        }

        if (ratinMaze(arr, x, y + 1, n, solArr))
        {
            return true;
        }
        if (ratinMaze(arr, x - 1, y, n, solArr))
        {
            return true;
        }

        if (ratinMaze(arr, x, y - 1, n, solArr))
        {
            return true;
        }
        cout << "[BACKTRACK] Dead end reached. Backtracking from coordinates: (" << x << ", " << y << ")" << endl;
        solArr[x][y] = 0; // Backtracking
        return false;
    }

    return false;
}

template <int N>
void printsol(int (&arr)[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int n4 = 4;
    int arr4[n4][n4] = {
         {1, 0, 0, 0},
         {1, 0, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    int solArr4[n4][n4] = {0};
    cout << "================ RUNNING 4X4 MAZE ================" << endl;
    ratinMaze(arr4, 0, 0, n4, solArr4);
    printsol(solArr4, n4);
    cout << endl;

    const int n3 = 3; 
    int arr3[n3][n3] = {
        {1, 1, 0},
        {0, 0, 0}, 
        {1, 1, 1}};
    int solArr3[n3][n3] = {0};
    cout << "================ RUNNING 3X3 MAZE ================" << endl;
    ratinMaze(arr3, 0, 0, n3, solArr3);
    printsol(solArr3, n3);
    return 0;
}
