#include <bits/stdc++.h>
using namespace std;

#define N 4
#define vacant 0

void inputGrid(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
}

void printGrid(int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool usedinRow(int a[N][N], int row, int num) {
    for (int i = 0; i < N; i++) {
        if (a[row][i] == num) {
            return true;
        }
    }
    return false;
}

bool usedinCol(int a[N][N], int col, int num) {
    for (int i = 0; i < N; i++) {
        if (a[i][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedinBox(int a[N][N], int sr, int sc, int num) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[sr + i][sc + j] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int a[N][N], int row, int col, int num) {
    return !usedinRow(a, row, num) && !usedinCol(a, col, num) && !usedinBox(a, row - row % 2, col - col % 2, num);
}

// Solve the Sudoku using Backtracking
bool solveSudoku(int a[N][N]) {
    int row, col;

    // Find the next vacant cell
    bool empty = true;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (a[row][col] == vacant) {
                empty = false;
                break;
            }
        }
        if (!empty) break;
    }

    if (empty) return true;  // If no empty cell is found, we're done.

    for (int num = 1; num <= N; num++) {
        if (isSafe(a, row, col, num)) {
            a[row][col] = num;  // Try this number
            if (solveSudoku(a)) {
                return true;  // If successful, return true
            }
            a[row][col] = vacant;  // Backtrack
        }
    }

    return false;  // Trigger backtracking
}

int main() {
    int grid[N][N];
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Grid\n";
        cout << "2. Print Grid\n";
        cout << "3. Solve Sudoku\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Sudoku grid (0 for vacant spots):\n";
                inputGrid(grid);
                break;
            case 2:
                cout << "Printing the Sudoku grid:\n";
                printGrid(grid);
                break;
            case 3:
                cout << "Solving Sudoku...\n";
                if (solveSudoku(grid)) {
                    cout << "Sudoku solved successfully!\n";
                    printGrid(grid);
                } else {
                    cout << "No solution exists.\n";
                }
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}


