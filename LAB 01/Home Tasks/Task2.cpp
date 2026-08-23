#include <iostream>
#include <cstring>
using namespace std;

class Matrix{
    private:
    int rows;
    int cols;
    int **data;

    void allocate(int r,int c){
        rows=r;
        cols=c;
        data=new int*[rows];
        for(int i=0;i<rows;i++){
            data[i]=new int[cols]();
        }
    }

      void deallocate() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }

     void deepCopy(const Matrix& other) {
        allocate(other.rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    public:

    Matrix(int r, int c) {
        cout << "Constructor called" << endl;
        allocate(r, c);
    }

    ~Matrix() {
        cout << "Destructor called" << endl;
        deallocate();
    }

    Matrix(const Matrix& other) {
        cout << "Copy constructor called" << endl;
        deepCopy(other);
    }

    Matrix& operator=(const Matrix& other) {
        cout << "Copy assignment operator called" << endl;
        if (this == &other) {
            return *this;
        }
        deallocate();
        deepCopy(other);
        return *this;
    }

    void set(int r, int c, int value) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = value;
        } else {
            cout << "Error: Index out of bounds" << endl;
        }
    }

    int get(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        } else {
            cout << "Error: Index out of bounds" << endl;
            return 0;
        }
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Error: Matrix dimensions must match for addition" << endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    cout << "=== Creating matrices ===" << endl;
    Matrix m1(2, 3);
    Matrix m2(2, 3);

    cout << "\n=== Filling m1 ===" << endl;
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(0, 2, 3);
    m1.set(1, 0, 4);
    m1.set(1, 1, 5);
    m1.set(1, 2, 6);

    cout << "\n=== Filling m2 ===" << endl;
    m2.set(0, 0, 6);
    m2.set(0, 1, 5);
    m2.set(0, 2, 4);
    m2.set(1, 0, 3);
    m2.set(1, 1, 2);
    m2.set(1, 2, 1);

    cout << "\n=== m1 ===" << endl;
    m1.display();

    cout << "\n=== m2 ===" << endl;
    m2.display();

    cout << "\n=== m1 + m2 ===" << endl;
    Matrix m3 = m1 + m2;
    m3.display();

    cout << "\n=== Copy construction ===" << endl;
    Matrix m4(m1);
    cout << "m4 (copy of m1):" << endl;
    m4.display();

    cout << "\n=== Copy assignment ===" << endl;
    Matrix m5(2, 3);
    m5 = m2;
    cout << "m5 (assigned from m2):" << endl;
    m5.display();

    cout << "\n=== Modifying m1 to verify independence ===" << endl;
    m1.set(0, 0, 99);
    cout << "m1 after modification:" << endl;
    m1.display();
    cout << "m4 (should be unchanged):" << endl;
    m4.display();
    cout << "m5 (should be unchanged):" << endl;
    m5.display();

    return 0;
}