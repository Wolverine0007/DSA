#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int rollno;
    string name;
    string branch;
    char div;
    string placementStatus;
    string companyName;
    Node* next;
};

class PlacementSystem {
public:
    Node* head;

    PlacementSystem() {
        head = NULL;
    }

    void create();
    void insert();
    void display();
    void update();
    void deleteNode();
    void search();
    void sort();
};

void PlacementSystem::create() {
    char continu;
    Node* newNode;
    Node* current;

    do {
        newNode = new Node();
        cout << "Enter roll no: ";
        cin >> newNode->rollno;

        cout << "Enter name: ";
        cin >> newNode->name;

        cout << "Enter branch: ";
        cin >> newNode->branch;

        cout << "Enter division: ";
        cin >> newNode->div;

        cout << "Enter placement status (Placed/Not Placed): ";
        cin >> newNode->placementStatus;

        if (newNode->placementStatus == "Placed") {
            cout << "Enter company name: ";
            cin >> newNode->companyName;
        } else {
            newNode->companyName = "N/A";
        }

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

        cout << "Do you want to add another record? (y/n): ";
        cin >> continu;

    } while (continu != 'n');
}

void PlacementSystem::display() {
    if (head == NULL) {
        cout << "Placement Information System is empty." << endl;
    } else {
        Node* temp = head;

        while (temp != NULL) {
            cout << "\nRoll No: " << temp->rollno;
            cout << "\nName: " << temp->name;
            cout << "\nBranch: " << temp->branch;
            cout << "\nDivision: " << temp->div;
            cout << "\nPlacement Status: " << temp->placementStatus;
            cout << "\nCompany Name: " << temp->companyName << endl;

            temp = temp->next;
        }
    }
}

void PlacementSystem::search() {
    int rno;
    Node* temp = head;
    bool found = false;

    if (head == NULL) {
        cout << "Placement Information System is empty." << endl;
        return;
    }

    cout << "Enter roll no to search: ";
    cin >> rno;

    while (temp != NULL) {
        if (temp->rollno == rno) {
            cout << "\nRecord Found:";
            cout << "\nRoll No: " << temp->rollno;
            cout << "\nName: " << temp->name;
            cout << "\nBranch: " << temp->branch;
            cout << "\nDivision: " << temp->div;
            cout << "\nPlacement Status: " << temp->placementStatus;
            cout << "\nCompany Name: " << temp->companyName << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }
}

void PlacementSystem::update() {
    int rno;
    Node* temp = head;
    bool found = false;

    if (head == NULL) {
        cout << "Placement Information System is empty." << endl;
        return;
    }

    cout << "Enter roll no to update: ";
    cin >> rno;

    while (temp != NULL) {
        if (temp->rollno == rno) {
            cout << "\nRecord Found.";
            cout << "\nUpdating record...";

            cout << "Enter new name: ";
            cin >> temp->name;

            cout << "Enter new branch: ";
            cin >> temp->branch;

            cout << "Enter new division: ";
            cin >> temp->div;

            cout << "Enter new placement status (Placed/Not Placed): ";
            cin >> temp->placementStatus;

            if (temp->placementStatus == "Placed") {
                cout << "Enter new company name: ";
                cin >> temp->companyName;
            } else {
                temp->companyName = "N/A";
            }

            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Record updated successfully." << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

void PlacementSystem::deleteNode() {
    int rno;
    Node *temp = head, *prev = NULL;

    if (head == NULL) {
        cout << "Placement Information System is empty." << endl;
        return;
    }

    cout << "Enter roll no to delete: ";
    cin >> rno;

    while (temp != NULL && temp->rollno != rno) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Record not found!" << endl;
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Record deleted successfully." << endl;
    }
}

void PlacementSystem::sort() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *i = head, *j = NULL;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->rollno > j->rollno) {
                swap(i->rollno, j->rollno);
                swap(i->name, j->name);
                swap(i->branch, j->branch);
                swap(i->div, j->div);
                swap(i->placementStatus, j->placementStatus);
                swap(i->companyName, j->companyName);
            }
            j = j->next;
        }
        i = i->next;
    }

    cout << "Records sorted successfully." << endl;
    display();
}

void PlacementSystem::insert() {
    cout << "Use the create option to add new records." << endl;
}

int main() {
    PlacementSystem ps;
    int choice;

    do {
        cout << "\n--- Placement Information System ---" << endl;
        cout << "1. Create Records" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Update Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Sort Records" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ps.create();
                break;
            case 2:
                ps.display();
                break;
            case 3:
                ps.search();
                break;
            case 4:
                ps.update();
                break;
            case 5:
                ps.deleteNode();
                break;
            case 6:
                ps.sort();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

