#include <iostream>
using namespace std;

const int N = 4; 
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int grid[N][N], int row, int col, int num) {

    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col]==num) {
            return false;
        }
    }
   
      
    int subgridSize = 2;
    int startRow = row - row % subgridSize;
    int startCol = col - col % subgridSize;
    for (int x = 0; x < subgridSize; x++) {
        for (int y = 0; y < subgridSize; y++) {
            if (grid[startRow + x][startCol + y] == num) {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int grid[N][N]) {
    int row, col;  
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    if (!isEmpty) {
        return true;
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true; 
            }
            grid[row][col] = 0; 
        } 
    }
    return false; 
}
int main() {
    int grid[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    cout << "Enter the Sudoku puzzle (4x4 grid), 0 for empty cells: \n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin>>grid[row][col];
        }
    }
    if (solveSudoku(grid)) {
         cout << "Sudoku Solution:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}