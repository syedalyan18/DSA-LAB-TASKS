#include <iostream>
using namespace std;

template <int N>
bool isSafe(int (&arr)[N][N], int x, int y, int n, int (&visited)[N][N])
{
    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    return false;
}

template <int N>
bool ratinMaze(int (&arr)[N][N], int x, int y, int n, int (&solArr)[N][N], int (&visited)[N][N])
{

    if ((x == (n - 1)) && (y == (n - 1)))
    {
        solArr[x][y] = 1;
        visited[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, visited))
    {
        solArr[x][y] = 1;
        visited[x][y] = 1;

        // 1. Move DOWN
        if (ratinMaze(arr, x + 1, y, n, solArr, visited))
        {
            return true;
        }

        // 2. Move RIGHT
        if (ratinMaze(arr, x, y + 1, n, solArr, visited))
        {
            return true;
        }

        // 3. Move UP
        if (ratinMaze(arr, x - 1, y, n, solArr, visited))
        {
            return true;
        }

        // 4. Move LEFT
        if (ratinMaze(arr, x, y - 1, n, solArr, visited))
        {
            return true;
        }

        cout << "[BACKTRACK] Dead end reached at coordinates: (" << x << ", " << y << ")" << endl;
        solArr[x][y] = 0; 
        visited[x][y] = 0; 
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
  
    const int n5 = 5;
    int arr5[n5][n5] = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    
    int solArr5[n5][n5] = {0};
    int visited5[n5][n5] = {0}; 

    cout << "================ RUNNING 5X5 4-WAY MAZE ================" << endl;
    if (ratinMaze(arr5, 0, 0, n5, solArr5, visited5)) {
        cout << "\nFinal Solution Path Matrix:" << endl;
        printsol(solArr5, n5);
    } else {
        cout << "\nNo valid path exists out of this maze." << endl;
    }

    return 0;
}
