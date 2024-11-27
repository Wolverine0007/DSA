#include <iostream>
#include <string>
using namespace std;

class Customer
{

public:
    string name;
    int Balance;
    double Acno;

    void getdata()
    {
        cout << "Enter Your Name: " << endl;
        cin >> name;

        cout << "Enter your account number: " << endl;
        cin >> Acno;

        cout << "Enter your Balance: " << endl;
        cin >> Balance;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Balance: " << Balance << endl;
        cout << "Account number: " << Acno << endl;
    }

    void insertCustomer(Customer arry[], int &count)
    {

        if (count < 10)
        {
            Customer c;
            c.getdata();
            arry[count++] = c;
            cout << "Customer added" << endl;
        }
        else
        {
            cout << "List is full " << endl;
        }
    }

    void showCustomer(Customer arry[], int count)
    {
        if (count == 0)
        {
            cout << "No customer" << endl;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                arry[i].display();
            }
        }
    }
    void updateCustomer(Customer arry[], int count) {
    int Acno;
    cout << "Enter the Account number to update the details: " << endl;
    cin >> Acno;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (arry[i].Acno == Acno) {
            cout << "Enter new details: " << endl;
            arry[i].getdata();
            cout << "Updated Successfully " << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Customer with account number :" << Acno << " not found " << endl;
    }
}

    void deleteCustomer(Customer arry[], int &count) {
    int Acno;
    cout << "Enter the Account number to delete: " << endl;
    cin >> Acno;

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (arry[i].Acno == Acno) {
            for (int j = i; j < count - 1; j++) {
                arry[j] = arry[j + 1];
            }
            count--;
            cout << "Customer Deleted " << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Customer with account number :" << Acno << " not found " << endl;
    }
}

};

int main()
{

    Customer arry[20];
    Customer c;
    int count = 0;
    int option;

    do
    {

        cout << "1: Insert Customer" << endl;
        cout << "2: Display Customer" << endl;
        cout << "3: Update Customer" << endl;
        cout << "4: Delete Customer" << endl;
        cout << "5: Exit" << endl;

        cout << "Enter option" << endl;
        cin >> option;

        switch (option)
        {

        case 1:
            c.insertCustomer(arry, count);
            break;

        case 2:
            c.showCustomer(arry, count);
            break;

        case 3:
            c.updateCustomer(arry, count);
            break;

        case 4:
            c.deleteCustomer(arry, count);
            break;

        case 5:
            cout << "Exit the prgram " << endl;
            break;

        default:
            cout << "Invalid option " << endl;
        }

    } while (option != 5);

    return 0;
}