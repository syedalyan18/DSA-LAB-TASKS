
#include <iostream>
using namespace std;

class SafeMatrix
{
private:
    int **matrix;
    int rows;
    int cols;

public:
    SafeMatrix(int r, int c)
    {
        rows = r;
        cols = c;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int[cols];
        }
    }
    void set(int r, int c, int val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Boundary Error" << endl;
            return;
        }
        matrix[r][c] = val;
        cout << "Safely set the value\n";
        return;
    }
    int get(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Boundary Error" << endl;
            return -1;
        }
        else
        {
            return matrix[r][c];
        }
    }
    void display() const
    {
        cout << "-----Matrix------" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~SafeMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete matrix[i];
        }
        delete[] matrix;
    }
};
int main()
{
    SafeMatrix m(4, 4);

    m.set(0, 0, 10);
    m.set(0, 1, 20);
    m.set(0, 2, 40);
    m.set(0, 3, 50);
    m.set(1, 0, 30);
    m.set(1, 1, 40);
    m.set(1, 2, 60);
    m.set(1, 3, 90);
    m.set(2, 2, 50);
    m.set(2, 3, 70);
    m.set(2, 0, 65);
    m.set(3, 0, 55);
    m.set(3, 1, 40);
    m.set(3, 3, 60);
    m.set(2, 1, 95);
    m.set(3, 2, 40);

    m.display();

    cout << "\nDemonstrating invalid accesses:\n"
         << endl;

    cout << "Attempt 1 - Invalid row (-1): ";
    m.get(-1, 0);

    cout << "Attempt 2 - Invalid column (10): ";
    m.get(0, 10);

    cout << "Attempt 3 - Invalid row (4): ";
    m.get(4, 0);

    cout << "Attempt 4 - Invalid row and column (-1, -1): ";
    m.get(-1, -1);

    return 0;
}

