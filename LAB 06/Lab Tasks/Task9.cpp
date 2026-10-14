#include <iostream>
using namespace std;

template <int N>
bool issafe(int (&board)[N][N], int r, int c) {
    // col check
    for (int i = 0; i < r; i++) {
        if (board[i][c] == 1) {
            return false;
        }
    }
    // diagonal check upper left
    for (int i = r - 1, j = c - 1; j >= 0 && i >= 0; j--, i--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // upper right
    for (int i = r - 1, j = c + 1; j < N && i >= 0; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

template <int N>
bool solveNqueen(int (&board)[N][N], int r) {
    if (r == N) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        if (issafe(board, r, i)) {
            board[r][i] = 1;
            if (solveNqueen(board, r + 1)) return true;
            board[r][i] = 0; // Backtracking
        }
    }
    return false;
}

template <int N>
void printboard(int (&board)[N][N]) {
    cout << "Queen placed for N = " << N << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    const int n2 = 2;
    int board2[n2][n2] = {0};
    if (solveNqueen(board2, 0)) {
        printboard(board2);
    } else {
        cout << "No valid solution exists for N = " << n2 << "\n" << endl;
    }

   
    const int n3 = 3;
    int board3[n3][n3] = {0};
    if (solveNqueen(board3, 0)) {
        printboard(board3);
    } else {
        cout << "No valid solution exists for N = " << n3 << "\n" << endl;
    }

  
    const int n4 = 4;
    int board4[n4][n4] = {0};
    if (solveNqueen(board4, 0)) {
        printboard(board4);
    } else {
        cout << "No valid solution exists for N = " << n4 << "\n" << endl;
    }

   
    const int n5 = 5;
    int board5[n5][n5] = {0};
    if (solveNqueen(board5, 0)) {
        printboard(board5);
    } else {
        cout << "No valid solution exists for N = " << n5 << "\n" << endl;
    }

  
    const int n6 = 6;
    int board6[n6][n6] = {0};
    if (solveNqueen(board6, 0)) {
        printboard(board6);
    } else {
        cout << "No valid solution exists for N = " << n6 << "\n" << endl;
    }

 
    const int n7 = 7;
    int board7[n7][n7] = {0};
    if (solveNqueen(board7, 0)) {
        printboard(board7);
    } else {
        cout << "No valid solution exists for N = " << n7 << "\n" << endl;
    }

  
    const int n8 = 8;
    int board8[n8][n8] = {0};
    if (solveNqueen(board8, 0)) {
        printboard(board8);
    } else {
        cout << "No valid solution exists for N = " << n8 << "\n" << endl;
    }

    return 0;
}
