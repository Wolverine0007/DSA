#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int billNo;
    string customerName;
    vector<pair<string, double> > items; // Pair of item name and price
    double totalAmount;
    Node* next;
};

class BillingSystem {
public:
    Node* head;

    BillingSystem() {
        head = NULL;
    }

    void create();
    void display();
    void search();
    void update();
    void deleteNode();
    void sort();
};

void BillingSystem::create() {
    char continu;
    Node* newNode;
    Node* current;

    do {
        newNode = new Node();
        cout << "Enter bill number: ";
        cin >> newNode->billNo;

        cout << "Enter customer name: ";
        cin >> newNode->customerName;

        int numItems;
        cout << "Enter the number of items: ";
        cin >> numItems;

        newNode->totalAmount = 0;
        for (int i = 0; i < numItems; ++i) {
            string itemName;
            double price;
            cout << "Enter item name: ";
            cin >> itemName;
            cout << "Enter item price: ";
            cin >> price;
            newNode->items.push_back(make_pair(itemName, price));
            newNode->totalAmount += price;
        }

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

        cout << "Do you want to add another bill? (y/n): ";
        cin >> continu;

    } while (continu != 'n');
}

void BillingSystem::display() {
    if (head == NULL) {
        cout << "No bills available." << endl;
    } else {
        Node* temp = head;

        while (temp != NULL) {
            cout << "\nBill Number: " << temp->billNo;
            cout << "\nCustomer Name: " << temp->customerName;
            cout << "\nItems Purchased:" << endl;
            for (size_t i = 0; i < temp->items.size(); ++i) {
                cout << "  - " << temp->items[i].first << " : Rs. " << temp->items[i].second << endl;
            }
            cout << "Total Amount: Rs. " << temp->totalAmount << endl;
            temp = temp->next;
        }
    }
}

void BillingSystem::search() {
    int bNo;
    Node* temp = head;
    bool found = false;

    if (head == NULL) {
        cout << "No bills available." << endl;
        return;
    }

    cout << "Enter bill number to search: ";
    cin >> bNo;

    while (temp != NULL) {
        if (temp->billNo == bNo) {
            cout << "\nBill Found:";
            cout << "\nBill Number: " << temp->billNo;
            cout << "\nCustomer Name: " << temp->customerName;
            cout << "\nItems Purchased:" << endl;
            for (size_t i = 0; i < temp->items.size(); ++i) {
                cout << "  - " << temp->items[i].first << " : Rs. " << temp->items[i].second << endl;
            }
            cout << "Total Amount: Rs. " << temp->totalAmount << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Bill not found!" << endl;
    }
}

void BillingSystem::update() {
    int bNo;
    Node* temp = head;
    bool found = false;

    if (head == NULL) {
        cout << "No bills available." << endl;
        return;
    }

    cout << "Enter bill number to update: ";
    cin >> bNo;

    while (temp != NULL) {
        if (temp->billNo == bNo) {
            cout << "\nBill Found.";
            cout << "\nUpdating bill...";

            cout << "Enter new customer name: ";
            cin >> temp->customerName;

            temp->items.clear();
            temp->totalAmount = 0;

            int numItems;
            cout << "Enter the number of items: ";
            cin >> numItems;

            for (int i = 0; i < numItems; ++i) {
                string itemName;
                double price;
                cout << "Enter item name: ";
                cin >> itemName;
                cout << "Enter item price: ";
                cin >> price;
                temp->items.push_back(make_pair(itemName, price));
                temp->totalAmount += price;
            }

            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Bill updated successfully." << endl;
    } else {
        cout << "Bill not found!" << endl;
    }
}

void BillingSystem::deleteNode() {
    int bNo;
    Node *temp = head, *prev = NULL;

    if (head == NULL) {
        cout << "No bills available." << endl;
        return;
    }

    cout << "Enter bill number to delete: ";
    cin >> bNo;

    while (temp != NULL && temp->billNo != bNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Bill not found!" << endl;
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Bill deleted successfully." << endl;
    }
}

void BillingSystem::sort() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *i = head, *j = NULL;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->billNo > j->billNo) {
                swap(i->billNo, j->billNo);
                swap(i->customerName, j->customerName);
                swap(i->items, j->items);
                swap(i->totalAmount, j->totalAmount);
            }
            j = j->next;
        }
        i = i->next;
    }

    cout << "Bills sorted successfully." << endl;
    display();
}

int main() {
    BillingSystem bs;
    int choice;

    do {
        cout << "\n--- Mall Billing System ---" << endl;
        cout << "1. Create Bill" << endl;
        cout << "2. Display Bills" << endl;
        cout << "3. Search Bill" << endl;
        cout << "4. Update Bill" << endl;
        cout << "5. Delete Bill" << endl;
        cout << "6. Sort Bills" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bs.create();
                break;
            case 2:
                bs.display();
                break;
            case 3:
                bs.search();
                break;
            case 4:
                bs.update();
                break;
            case 5:
                bs.deleteNode();
                break;
            case 6:
                bs.sort();
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

