#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int ticketNo;
    string passengerName;
    int age;
    string destination;
    string travelDate;
    string seatClass; // e.g., First, Second, Sleeper
    Node* next;
};

class RailwayReservation {
public:
    Node* head;

    RailwayReservation() {
        head = NULL;
    }

    void create();
    void display();
    void search();
    void update();
    void deleteNode();
    void sort();
};

void RailwayReservation::create() {
    char continu;
    Node* newNode;
    Node* current;

    do {
        newNode = new Node();
        cout << "Enter ticket number: ";
        cin >> newNode->ticketNo;

        cout << "Enter passenger name: ";
        cin >> newNode->passengerName;

        cout << "Enter age: ";
        cin >> newNode->age;

        cout << "Enter destination: ";
        cin >> newNode->destination;

        cout << "Enter travel date (DD/MM/YYYY): ";
        cin >> newNode->travelDate;

        cout << "Enter seat class (First/Second/Sleeper): ";
        cin >> newNode->seatClass;

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

void RailwayReservation::display() {
    if (head == NULL) {
        cout << "No reservations available." << endl;
    } else {
        Node* temp = head;

        while (temp != NULL) {
            cout << "\nTicket Number: " << temp->ticketNo;
            cout << "\nPassenger Name: " << temp->passengerName;
            cout << "\nAge: " << temp->age;
            cout << "\nDestination: " << temp->destination;
            cout << "\nTravel Date: " << temp->travelDate;
            cout << "\nSeat Class: " << temp->seatClass << endl;
            temp = temp->next;
        }
    }
}

void RailwayReservation::search() {
    int tNo;
    Node* temp = head;
    bool found = false;

    if (head == NULL) {
        cout << "No reservations available." << endl;
        return;
    }

    cout << "Enter ticket number to search: ";
    cin >> tNo;

    while (temp != NULL) {
        if (temp->ticketNo == tNo) {
            cout << "\nReservation Found:";
            cout << "\nTicket Number: " << temp->ticketNo;
            cout << "\nPassenger Name: " << temp->passengerName;
            cout << "\nAge: " << temp->age;
            cout << "\nDestination: " << temp->destination;
            cout << "\nTravel Date: " << temp->travelDate;
            cout << "\nSeat Class: " << temp->seatClass << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Reservation not found!" << endl;
    }
}

void RailwayReservation::update() {
    int tNo;
    Node* temp = head;
    bool found = false;

    if (head == NULL) {
        cout << "No reservations available." << endl;
        return;
    }

    cout << "Enter ticket number to update: ";
    cin >> tNo;

    while (temp != NULL) {
        if (temp->ticketNo == tNo) {
            cout << "\nReservation Found.";
            cout << "\nUpdating reservation...";

            cout << "Enter new passenger name: ";
            cin >> temp->passengerName;

            cout << "Enter new age: ";
            cin >> temp->age;

            cout << "Enter new destination: ";
            cin >> temp->destination;

            cout << "Enter new travel date (DD/MM/YYYY): ";
            cin >> temp->travelDate;

            cout << "Enter new seat class (First/Second/Sleeper): ";
            cin >> temp->seatClass;

            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << "Reservation updated successfully." << endl;
    } else {
        cout << "Reservation not found!" << endl;
    }
}

void RailwayReservation::deleteNode() {
    int tNo;
    Node *temp = head, *prev = NULL;

    if (head == NULL) {
        cout << "No reservations available." << endl;
        return;
    }

    cout << "Enter ticket number to delete: ";
    cin >> tNo;

    while (temp != NULL && temp->ticketNo != tNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Reservation not found!" << endl;
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Reservation deleted successfully." << endl;
    }
}

void RailwayReservation::sort() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *i = head, *j = NULL;

    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->ticketNo > j->ticketNo) {
                swap(i->ticketNo, j->ticketNo);
                swap(i->passengerName, j->passengerName);
                swap(i->age, j->age);
                swap(i->destination, j->destination);
                swap(i->travelDate, j->travelDate);
                swap(i->seatClass, j->seatClass);
            }
            j = j->next;
        }
        i = i->next;
    }

    cout << "Reservations sorted successfully." << endl;
    display();
}

int main() {
    RailwayReservation rr;
    int choice;

    do {
        cout << "\n--- Railway Reservation System ---" << endl;
        cout << "1. Create Reservation" << endl;
        cout << "2. Display Reservations" << endl;
        cout << "3. Search Reservation" << endl;
        cout << "4. Update Reservation" << endl;
        cout << "5. Delete Reservation" << endl;
        cout << "6. Sort Reservations" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rr.create();
                break;
            case 2:
                rr.display();
                break;
            case 3:
                rr.search();
                break;
            case 4:
                rr.update();
                break;
            case 5:
                rr.deleteNode();
                break;
            case 6:
                rr.sort();
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

