//Railway Reservation- CLL
#include <iostream>
using namespace std;

class Node {
public:
    int seatNumber;
    bool isReserved;
    Node* next;

    Node(int seat) {
        seatNumber = seat;
        isReserved = false;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList(int totalSeats) {
        head = nullptr;

        // Create circular linked list with given number of seats
        for (int i = 1; i <= totalSeats; ++i) {
            append(i);
        }
    }

    // Function to add a new node to the circular linked list
    void append(int seat) {
        Node* newNode = new Node(seat);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to display the status of seats
    void displayStatus() {
        if (!head) {
            cout << "No seats available." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << "Seat " << temp->seatNumber << ": ";
            if (temp->isReserved) {
                cout << "Reserved" << endl;
            } else {
                cout << "Available" << endl;
            }
            temp = temp->next;
        } while (temp != head);
    }

    // Function to book a seat
    void bookSeat(int seat) {
        Node* temp = head;
        do {
            if (temp->seatNumber == seat && !temp->isReserved) {
                temp->isReserved = true;
                cout << "Seat " << seat << " booked successfully." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Seat " << seat << " not available or already reserved." << endl;
    }

    // Function to cancel a reservation
    void cancelReservation(int seat) {
        Node* temp = head;
        do {
            if (temp->seatNumber == seat && temp->isReserved) {
                temp->isReserved = false;
                cout << "Reservation for seat " << seat << " canceled successfully." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Seat " << seat << " is not reserved or does not exist." << endl;
    }
};

int main() {
    int totalSeats;
    cout << "Enter the total number of seats: ";
    cin >> totalSeats;

    CircularLinkedList reservationSystem(totalSeats);

    int choice, seatNumber;
    do {
        cout << "\nRailway Reservation System\n";
        cout << "1. Display Seat Status\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reservationSystem.displayStatus();
                break;

            case 2:
                cout << "Enter the seat number to book: ";
                cin >> seatNumber;
                reservationSystem.bookSeat(seatNumber);
                break;

            case 3:
                cout << "Enter the seat number to cancel reservation: ";
                cin >> seatNumber;
                reservationSystem.cancelReservation(seatNumber);
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}