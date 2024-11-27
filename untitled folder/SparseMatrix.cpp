 #include <iostream>
using namespace std;

class sparsematrix {
    int Triplet[50][3], result[150][3], r, c, n;

public:
    sparsematrix(int r1, int c1, int n1) {
        r = r1;
        c = c1;
        n = n1;
    }

    void getTriplet() {
        cout << "Enter the Triplet in (row index, column index, value, e.g., 1 2 4)" << endl;
        for (int i = 1; i <= n; i++) {
            cin >> Triplet[i][0] >> Triplet[i][1] >> Triplet[i][2];
        }
        Triplet[0][0] = r;
        Triplet[0][1] = c;
        Triplet[0][2] = n;
    }

    void display() {
        cout << "The Triplet is:" << endl;
        for (int i = 0; i <= n; i++) {
            cout << Triplet[i][0] << "\t" << Triplet[i][1] << "\t" << Triplet[i][2] << endl;
        }
    }

   void addition(sparsematrix s2) {
    int R[100][3], i = 1, j = 1, k = 1;

    
    if (Triplet[0][0] == s2.Triplet[0][0] && Triplet[0][1] == s2.Triplet[0][1]) {

       
        R[0][0] = Triplet[0][0]; 
        R[0][1] = Triplet[0][1]; 

        
        while (i <= n && j <= s2.n) {
            if (Triplet[i][0] == s2.Triplet[j][0]) {
                if (Triplet[i][1] == s2.Triplet[j][1]) {
                    
                    R[k][0] = Triplet[i][0];
                    R[k][1] = Triplet[i][1];
                    R[k][2] = Triplet[i][2] + s2.Triplet[j][2];
                    ++i;
                    ++j;
                } else if (Triplet[i][1] < s2.Triplet[j][1]) {
                   
                    R[k][0] = Triplet[i][0];
                    R[k][1] = Triplet[i][1];
                    R[k][2] = Triplet[i][2];
                    ++i;
                } else {
                    
                    R[k][0] = s2.Triplet[j][0];
                    R[k][1] = s2.Triplet[j][1];
                    R[k][2] = s2.Triplet[j][2];
                    ++j;
                }
            } else if (Triplet[i][0] < s2.Triplet[j][0]) {
               
                R[k][0] = Triplet[i][0];
                R[k][1] = Triplet[i][1];
                R[k][2] = Triplet[i][2];
                ++i;
            } else {

                R[k][0] = s2.Triplet[j][0];
                R[k][1] = s2.Triplet[j][1];
                R[k][2] = s2.Triplet[j][2];
                ++j;
            }
            ++k; 
        }

       
        while (i <= n) {
            R[k][0] = Triplet[i][0];
            R[k][1] = Triplet[i][1];
            R[k][2] = Triplet[i][2];
            ++i;
            ++k;
        }

        
        while (j <= s2.n) {
            R[k][0] = s2.Triplet[j][0];
            R[k][1] = s2.Triplet[j][1];
            R[k][2] = s2.Triplet[j][2];
            ++j;
            ++k;
        }

       
        R[0][2] = k - 1;
    } else {
       
        cout << "Matrices cannot be added, they have different dimensions." << endl;
        return;
    }

    
    cout << "The Addition of the Matrices is:" << endl;
    for (int i = 0; i < k; i++) {
        cout << R[i][0] << "\t" << R[i][1] << "\t" << R[i][2] << endl;
    }
}

    void transpose() {
        int k = 1;
        for (int i = 0; i <=c; i++) {
            for (int j = 1; j <= n; j++) {
                if (Triplet[j][1] == i) {
                    result[k][0] = Triplet[j][1];
                    result[k][1] = Triplet[j][0];
                    result[k][2] = Triplet[j][2];
                    ++k;
                }
            }
        }

        result[0][0] = c;
        result[0][1] = r;
        result[0][2] = n;
    }

    void displayresult() {
        for (int i = 0; i <= result[0][2]; i++) {
            cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
        }
    }

    void multiplication(sparsematrix s2) {
        int mul[100][3] = {0};

        if (c != s2.r) {
            cout << "Multiplication not possible for the given matrices" << endl;
            return;
         }

         int k = 1;
         for (int i = 1; i <= n; i++) {
            int r1 = Triplet[i][0];
            int c1 = Triplet[i][1];
            int v1 = Triplet[i][2];

            for (int j = 1; j <= s2.n; j++) {
                int r2 = s2.Triplet[j][0];
                int c2 = s2.Triplet[j][1];
                int v2 = s2.Triplet[j][2];

                if (c1 == r2) {
                    bool found = false;

                    for (int l = 1; l < k; l++) {
                        if (mul[l][0] == r1 && mul[l][1] == c2) {
                            mul[l][2] += v1 * v2;
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        mul[k][0] = r1;
                        mul[k][1] = c2;
                        mul[k][2] = v1 * v2;
                        k++;
                    }
                }
            }
        }

        mul[0][0] = r;
        mul[0][1] = s2.c;
        mul[0][2] = k - 1;

        cout << "The result of multiplication is:" << endl;
        for (int i = 0; i < k; i++) {
            cout << mul[i][0] << "\t" << mul[i][1] << "\t" << mul[i][2] << endl;
        }
    }
    void fast_transpose() {
        int total[50] = {0};
        int index[50];

        for (int i = 1; i <= n; i++) {
            ++total[Triplet[i][1]];
        }

        index[0] = 1;
        for (int i = 1; i < c; i++) {
            index[i] = index[i - 1] + total[i - 1];
        }

        for (int i = 1; i <= n; i++) {
            int col = Triplet[i][1];
            int pos = index[col];
            result[pos][0] = Triplet[i][1];
            result[pos][1] = Triplet[i][0];
            result[pos][2] = Triplet[i][2];
            ++index[col];
        }

        result[0][0] = Triplet[0][1];
        result[0][1] = Triplet[0][0];
        result[0][2] = Triplet[0][2];
    }
};

int main() {
    bool run = true;
    int r1, c1, n1;
    char choice;

    cout << "First Matrix: (num of rows, num of columns, number of non-zero elements, e.g., 3 3 4)" << endl;
    cin >> r1 >> c1 >> n1;
                sparsematrix s1(r1, c1, n1);
                s1.getTriplet();
                s1.display();

                cout << "Second Matrix: (num of rows, num of columns, number of non-zero elements, e.g., 3 3 4)" << endl;
                cin >> r1 >> c1 >> n1;

                sparsematrix s2(r1, c1, n1);
                s2.getTriplet();
                s2.display();

    while (run) {
        cout << "What operation would you like to implement?" << endl;
        cout << "1. Addition of the sparse matrices" << endl;
        cout << "2. Multiplication of the sparse matrices" << endl;
        cout << "3. Transpose of the matrix" << endl;
        cout << "4. Fast Transpose of matrix" << endl;

        cin >> choice;

        switch (choice) {
            case '1': {

                s1.addition(s2);
                break;
            }

            case '2': {
                
                s1.multiplication(s2);
                break;
            }
                                         
            case '3': {
                s1.transpose();

                cout << "Transpose of the matrix is:" << endl;
                s1.displayresult();
                break;
            }

            case '4':{

                cout << "Fast Transpose of the matrix is:" << endl;
                s1.displayresult();
                break;

            }

            case '5': {
                run = false;
                break;
            }

            default: {
                cout << "Wrong choice" << endl;
            }
        }
    }
  return 0;
}
