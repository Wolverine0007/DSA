#include <iostream>
using namespace std;

class Sparse
{
  int sp[50][3];
  int k;

public:
  int r, c, n;

  void accept()
  {
    cout << "Enter number of rows, columns, and number of non-zero values: ";
    cin >> sp[0][0] >> sp[0][1] >> sp[0][2];
    cout << "Enter the elements (row, column, value): ";
    for (int i = 1; i <= sp[0][2]; i++)
    {
      cin >> sp[i][0] >> sp[i][1] >> sp[i][2];
    }
  }

  void display()
  {
    cout << "\nSparse Matrix:\n";
    for (int i = 0; i <= sp[0][2]; i++)
    {
      cout << sp[i][0] << " " << sp[i][1] << " " << sp[i][2] << endl;
    }
  }

  void add(Sparse s1, Sparse s2)
  {
    if (s1.sp[0][0] != s2.sp[0][0] || s1.sp[0][1] != s2.sp[0][1])
    {
      cout << "\nAddition not possible" << endl;
      return;
    }

    int i = 1, j = 1, k = 1;
    sp[0][0] = s1.sp[0][0];
    sp[0][1] = s1.sp[0][1];
    sp[0][2] = 0;

    while (i <= s1.sp[0][2] && j <= s2.sp[0][2])
    {
     
    // Row same hai kya ?
      if (s1.sp[i][0] == s2.sp[j][0])
      {
        // Column same hai kya ? hai to add krdo
        if (s1.sp[i][1] == s2.sp[j][1])
        {
          sp[k][0] = s1.sp[i][0];
          sp[k][1] = s1.sp[i][1];
          sp[k][2] = s1.sp[i][2] + s2.sp[j][2];
          i++;
          j++;
        }
        else if (s1.sp[i][1] < s2.sp[j][1])
        {
          sp[k][0] = s1.sp[i][0];
          sp[k][1] = s1.sp[i][1];
          sp[k][2] = s1.sp[i][2];
          i++;
        }
        else
        {
          sp[k][0] = s2.sp[j][0];
          sp[k][1] = s2.sp[j][1];
          sp[k][2] = s2.sp[j][2];
          j++;
        }
        k++;
      }
      else if (s1.sp[i][0] < s2.sp[j][0])
      {
        sp[k][0] = s1.sp[i][0];
        sp[k][1] = s1.sp[i][1];
        sp[k][2] = s1.sp[i][2];
        i++;
        k++;
      }
      else
      {
        sp[k][0] = s2.sp[j][0];
        sp[k][1] = s2.sp[j][1];
        sp[k][2] = s2.sp[j][2];
        j++;
        k++;
      }
    }
    // Remaining elements ko copy krdo 
    while (i <= s1.sp[0][2])
    {
      sp[k][0] = s1.sp[i][0];
      sp[k][1] = s1.sp[i][1];
      sp[k][2] = s1.sp[i][2];
      i++;
      k++;
    }

    while (j <= s2.sp[0][2])
    {
      sp[k][0] = s2.sp[j][0];
      sp[k][1] = s2.sp[j][1];
      sp[k][2] = s2.sp[j][2];
      j++;
      k++;
    }

    sp[0][2] = k - 1;
  }

  void transpose(Sparse s1)
  {
    int k = 1;
    sp[0][0] = s1.sp[0][1];
    sp[0][1] = s1.sp[0][0];
    sp[0][2] = s1.sp[0][2];

    for (int i = 0; i < s1.sp[0][1]; i++)
    {
      for (int j = 1; j <= s1.sp[0][2]; j++)
      {
        if (s1.sp[j][1] == i)
        {
          sp[k][0] = s1.sp[j][1];
          sp[k][1] = s1.sp[j][0];
          sp[k][2] = s1.sp[j][2];
          k++;
        }
      }
    }
  }

  void fast_transpose(Sparse s1)
  {
    int cnt[20] = {0}, loc[20], colno, index;
    for (int i = 1; i <= s1.sp[0][2]; i++)
    {
      colno = s1.sp[i][1];
      cnt[colno]++;
    }
    loc[0] = 1;
    for (int i = 1; i < s1.sp[0][1]; i++)
    {
      loc[i] = loc[i - 1] + cnt[i - 1];
    }
    for (int i = 1; i <= s1.sp[0][2]; i++)
    {
      colno = s1.sp[i][1];
      index = loc[colno];
      sp[index][0] = s1.sp[i][1];
      sp[index][1] = s1.sp[i][0];
      sp[index][2] = s1.sp[i][2];
      loc[colno]++;
    }
    sp[0][0] = s1.sp[0][1];
    sp[0][1] = s1.sp[0][0];
    sp[0][2] = s1.sp[0][2];
  }

  void multiply(Sparse s1, Sparse s2)
  {
    if (s1.sp[0][1] != s2.sp[0][0])
    {
      cout << "Can't Multiply \n";
      return;
    }

    Sparse s4;
    s4.transpose(s2); // Transpose of the second matrix

    int i = 1, k = 1;
    while (i <= s1.sp[0][2])
    {
      int r = s1.sp[i][0];
      int j = 1;
      while (j <= s4.sp[0][2])
      {
        int c = s4.sp[j][0];
        int sum = 0;
        int a = i, b = j;

        while (a <= s1.sp[0][2] && s1.sp[a][0] == r && b <= s4.sp[0][2] && s4.sp[b][0] == c)
        {
          if (s1.sp[a][1] == s4.sp[b][1])
          {
            sum += s1.sp[a][2] * s4.sp[b][2];
            a++;
            b++;
          }
          else if (s1.sp[a][1] < s4.sp[b][1])
          {
            a++;
          }
          else
          {
            b++;
          }
        }

        if (sum != 0)
        {
          sp[k][0] = r;
          sp[k][1] = c;
          sp[k][2] = sum;
          k++;
        }

        while (j <= s4.sp[0][2] && s4.sp[j][0] == c)
        {
          j++;
        }
      }

      while (i <= s1.sp[0][2] && s1.sp[i][0] == r)
      {
        i++;
      }
    }

    sp[0][0] = s1.sp[0][0];
    sp[0][1] = s2.sp[0][1];
    sp[0][2] = k - 1;
  }
};

int main()
{
  Sparse s1, s2, s3;
  int choice;

  do
  {
    cout << "\nMenu:";
    cout << "\n1. Simple Transpose";
    cout << "\n2. Fast Transpose";
    cout << "\n3. Addition";
    cout << "\n4. Multiplication";
    cout << "\n5. Exit";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "\nEnter the matrix: ";
      s1.accept();
      s2.transpose(s1);
      cout << "\nSimple Transpose of s1 is: ";
      s2.display();
      break;

    case 2:
      cout << "\nEnter the matrix: ";
      s1.accept();
      s2.fast_transpose(s1);
      cout << "\nFast Transpose of s1 is: ";
      s2.display();
      break;

    case 3:
      cout << "\nEnter the first matrix: ";
      s1.accept();
      cout << "\nEnter the second matrix: ";
      s2.accept();
      s3.add(s1, s2);
      cout << "\nAddition of s1 and s2 is: ";
      s3.display();
      break;

    case 4:
      cout << "\nEnter the first matrix: ";
      s1.accept();
      cout << "\nEnter the second matrix: ";
      s2.accept();
      s3.multiply(s1, s2);
      cout << "\nMultiplication of s1 and s2 is: ";
      s3.display();
      break;

    case 5:
      cout << "\nExiting...";
      break;

    default:
      cout << "\nInvalid choice!";
    }
  } while (choice != 5);

  return 0;
}
