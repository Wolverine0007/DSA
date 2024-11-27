#include <bits/stdc++.h>
using namespace std;

class Customer {
public:
    int id;
    char name[100];
    char email[100];
    char phone[15];

    void insert();
    void Delete(Customer customers[], int &n);
    void display();
    void update(int search_id);
};

void Customer::insert() {
    cout << "\nEnter Customer ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(name, 100);
    cout << "Enter Email: ";
    cin.getline(email, 100);
    cout << "Enter Phone: ";
    cin.getline(phone, 15);
    cout << "Customer added successfully!\n";
}

void Customer::Delete(Customer customers[], int &n) {
    int delete_id;
    cout << "Enter Customer ID to DELETE: ";
    cin >> delete_id;

    int i;
    for (i = 0; i < n; i++) {
        if (customers[i].id == delete_id) {
            cout << "Customer Found. Deleting...\n";
            break;
        }
    }
    if (i == n) {
        cout << "Customer not found!\n";
        return;
    }

    for (int j = i; j < n - 1; j++) {
        customers[j] = customers[j + 1];
    }
    n--;
    cout << "Customer Deleted Successfully!\n";
}

void Customer::display() {
    cout << "\nCustomer ID: " << id;
    cout << "\nName: " << name;
    cout << "\nEmail: " << email;
    cout << "\nPhone: " << phone << "\n";
}

void Customer::update(int search_id) {
    if (id != search_id) {
        return;
    }

    int ch;
    cout << "1. Update Name\n";
    cout << "2. Update Email\n";
    cout << "3. Update Phone\n";
    cout << "4. Update Nothing\n";
    cout << "Enter Your Choice: ";
    cin >> ch;

    switch (ch) {
    case 1:
        cout << "Enter NEW Name: ";
        cin.ignore();
        cin.getline(name, 100);
        break;
    case 2:
        cout << "Enter NEW Email: ";
        cin.ignore();
        cin.getline(email, 100);
        break;
    case 3:
        cout << "Enter NEW Phone: ";
        cin.ignore();
        cin.getline(phone, 15);
        break;
    case 4:
        cout << "No Updates Made.\n";
        break;
    default:
        cout << "INVALID CHOICE\n";
        break;
    }
}

int main() {
    Customer customers[100];
    int choice, customer_count = 0;
    int total = sizeof(customers) / sizeof(customers[0]);

    do {
        cout << "\tCUSTOMER MANAGEMENT SYSTEM\n";
        cout << "1. Add Customer\n2. Display All Customers\n3. Update Customer\n4. Delete Customer\n5. EXIT\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (customer_count < total) {
                int entries;
                cout << "How many customers to add: ";
                cin >> entries;

                for (int i = 0; i < entries && customer_count < total; i++) {
                    customers[customer_count].insert();
                    customer_count++;
                }
                if (customer_count == total) {
                    cout << "No more space for new customers.\n";
                }
            } else {
                cout << "No more space for new customers.\n";
            }
            break;

        case 2:
            for (int i = 0; i < customer_count; i++) {
                customers[i].display();
            }
            break;

        case 3: {
            int search_id;
            cout << "Enter the Customer ID to update: ";
            cin >> search_id;
            bool found = false;
            for (int i = 0; i < customer_count; i++) {
                if (customers[i].id == search_id) {
                    customers[i].update(search_id);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Customer not found!\n";
            }
            break;
        }

        case 4:
            customers->Delete(customers, customer_count);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice.\n";
            break;
        }

    } while (choice != 5);

    return 0;
}

