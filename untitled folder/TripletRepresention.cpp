#include <iostream>
using namespace std;

int main() {
    int row, col;
    
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;
    int a[row][col];
    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    int nonZeroCount = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (a[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    
    int triplet[nonZeroCount][3];
    int k = 0;

    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (a[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = a[i][j];
                k++;
            }
        }
    }

    
    cout << "Triplet Representation of the Sparse Matrix:" << endl;
    cout << "Row  Column  Value" << endl;
    for (int i = 0; i < nonZeroCount; ++i) {
        cout << triplet[i][0] << "      " << triplet[i][1] << "      " << triplet[i][2] << endl;
    }

    return 0;
}
