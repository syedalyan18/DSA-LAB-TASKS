#include <iostream>
using namespace std;

class Matrix {
private:
    int **matrix;
    int rows;
    int cols;

    void deepCopy(const Matrix &other) {
        rows = other.rows;
        cols = other.cols;
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        matrix = new int *[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    Matrix(const Matrix &other) {
        deepCopy(other);
    }

    Matrix &operator=(const Matrix &other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) delete[] matrix[i];
            delete[] matrix;
            deepCopy(other);
        }
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            cout << "Enter row " << i << ": ";
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getElement(int r, int c) const { return matrix[r][c]; }
    void setElement(int r, int c, int val) { matrix[r][c] = val; }

    static Matrix add(const Matrix &m1, const Matrix &m2) {
        if (m1.rows != m2.rows || m1.cols != m2.cols) {
            cout << "Addition failed: dimensions don't match\n";
            return Matrix(0, 0);
        }
        Matrix result(m1.rows, m1.cols);
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.cols; j++) {
                result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        }
        return result;
    }

    static Matrix multiply(const Matrix &m1, const Matrix &m2) {
        if (m1.cols != m2.rows) {
            cout << "Multiplication failed: cols of first != rows of second\n";
            return Matrix(0, 0);
        }
        Matrix result(m1.rows, m2.cols);
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < m1.cols; k++) {
                    result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and cols for Matrix A: ";
    cin >> r1 >> c1;
    Matrix A(r1, c1);
    A.input();

    cout << "Enter rows and cols for Matrix B: ";
    cin >> r2 >> c2;
    Matrix B(r2, c2);
    B.input();

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add\n";
        cout << "2. Multiply\n";
        cout << "3. Display Matrices\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Matrix result = Matrix::add(A, B);
            if (result.getRows() > 0 && result.getCols() > 0) {
                cout << "Result of Addition:\n";
                result.display();
            }
        } else if (choice == 2) {
            Matrix result = Matrix::multiply(A, B);
            if (result.getRows() > 0 && result.getCols() > 0) {
                cout << "Result of Multiplication:\n";
                result.display();
            }
        } else if (choice == 3) {
            cout << "Matrix A:\n";
            A.display();
            cout << "Matrix B:\n";
            B.display();
        }
    } while (choice != 4);

    return 0;
}