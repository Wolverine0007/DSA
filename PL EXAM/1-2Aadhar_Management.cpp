#include <bits/stdc++.h>
using namespace std;

class Aadhar {
public:
    int id;
    char name[50];
    char address[100];
    long long aadhar_number;
    char dob[15];

    void insert();
    void Delete(Aadhar records[], int &n);
    void display();
    void update(int search_id);
};

void Aadhar::insert() {
    cout << "\nEnter Aadhar ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(name, 50);
    cout << "Enter Address: ";
    cin.getline(address, 100);
    cout << "Enter Aadhar Number: ";
    cin >> aadhar_number;
    cin.ignore();
    cout << "Enter Date of Birth (DD-MM-YYYY): ";
    cin.getline(dob, 15);
    cout << endl;
}

void Aadhar::Delete(Aadhar records[], int &n) {
    int delete_id;
    cout << "Enter Aadhar ID of the record to be DELETED: ";
    cin >> delete_id;

    int i;
    for (i = 0; i < n; i++) {
        if (records[i].id == delete_id) {
            cout << "Record Found. Deleting...\n";
            break;
        }
    }
    if (i == n) {
        cout << "Record not found!\n";
        return;
    }

    for (int j = i; j < n - 1; j++) {
        records[j] = records[j + 1];
    }
    n--;
    cout << "Record Deleted Successfully!\n";
}

void Aadhar::display() {
    cout << "\nAadhar ID: " << id;
    cout << "\nName: " << name;
    cout << "\nAddress: " << address;
    cout << "\nAadhar Number: " << aadhar_number;
    cout << "\nDate of Birth: " << dob << "\n";
}

void Aadhar::update(int search_id) {
    if (id != search_id) {
        return;
    }

    int ch;
    cout << "1. Update Name\n";
    cout << "2. Update Address\n";
    cout << "3. Update Aadhar Number\n";
    cout << "4. Update Date of Birth\n";
    cout << "5. Update Nothing\n";
    cout << "Enter Your Choice: ";
    cin >> ch;

    switch (ch) {
    case 1:
        cout << "Enter NEW Name: ";
        cin.ignore();
        cin.getline(name, 50);
        break;
    case 2:
        cout << "Enter NEW Address: ";
        cin.ignore();
        cin.getline(address, 100);
        break;
    case 3:
        cout << "Enter NEW Aadhar Number: ";
        cin >> aadhar_number;
        break;
    case 4:
        cout << "Enter NEW Date of Birth (DD-MM-YYYY): ";
        cin.ignore();
        cin.getline(dob, 15);
        break;
    case 5:
        cout << "No Updates Made.\n";
        break;
    default:
        cout << "INVALID CHOICE\n";
        break;
    }
}

int main() {
    Aadhar records[100];
    int choice, record_count = 0;
    int total = sizeof(records) / sizeof(records[0]);

    do {
        cout << "\tMENU\n1. Insert\n2. Display\n3. Update\n4. Delete\n5. EXIT\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (record_count < total) {
                int entries;
                cout << "How many entries to be made: ";
                cin >> entries;

                for (int i = 0; i < entries && record_count < total; i++) {
                    records[record_count].insert();
                    record_count++;
                }
                if (record_count == total) {
                    cout << "No more records can be added.\n";
                }
            } else {
                cout << "No more space for new records.\n";
            }
            break;

        case 2:
            for (int i = 0; i < record_count; i++) {
                records[i].display();
            }
            break;

        case 3: {
            int search_id;
            cout << "Enter the Aadhar ID to be updated: ";
            cin >> search_id;
            bool found = false;
            for (int i = 0; i < record_count; i++) {
                records[i].update(search_id);
                found = true;
            }
            if (!found) {
                cout << "Record not found!\n";
            }
            break;
        }

        case 4:
            records->Delete(records, record_count);
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

