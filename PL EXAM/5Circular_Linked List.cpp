#include <bits/stdc++.h>
using namespace std;

#define MM 8  // Corrected macro definition

class node {
public:
    int orderno;
    node *next;

    node(int x) {
        orderno = x;
        next = NULL;
    }
};

class CLL {
private:
    int count;
    node *head;

public:
    CLL() {
        head = NULL;
        count = 0;
    }

    void addOrder(int x);
    void serveOrder();
    void display();
};

void CLL::addOrder(int x) {
    node *temp = new node(x);  // Create a new node

    if (head == NULL) {  // If the list is empty
        head = temp;
        temp->next = head;  // Circular link
    } else {
        node *last = head;
        while (last->next != head) {  // Traverse to the last node
            last = last->next;
        }
        last->next = temp;  // Link last node to the new node
        temp->next = head;  // Circular link to head
    }
    count++;
}

void CLL::serveOrder() {
    if (head == NULL) {
        cout << "No orders to serve." << endl;
        return;
    }

    node *temp = head;
    if (head->next == head) {  // If there's only one order
        head = NULL;
    } else {
        node *last = head;
        while (last->next != head) {  // Traverse to the last node
            last = last->next;
        }
        last->next = head->next;  // Skip the head node
        head = head->next;  // Update head to the next order
    }
    delete temp;  // Free the memory
    count--;
}

void CLL::display() {
    if (head == NULL) {
        cout << "No orders to display." << endl;
        return;
    }

    node *temp = head;
    do {
        cout << "Order ID: " << temp->orderno << endl;
        temp = temp->next;
    } while (temp != head);  // Loop until we return to the head
}

int main() {
    CLL orders;
    int choice, orderId;

    do {
        // Menu-driven interface
        cout << "\nMenu:\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // Add an order
                cout << "Enter order ID to add: ";
                cin >> orderId;
                orders.addOrder(orderId);
                cout << "Order " << orderId << " added successfully.\n";
                break;
            case 2:
                // Serve an order
                orders.serveOrder();
                cout << "First order served.\n";
                break;
            case 3:
                // Display all orders
                cout << "Displaying all orders:\n";
                orders.display();
                break;
            case 4:
                // Exit the program
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);  // Repeat until user chooses to exit

    return 0;
}


