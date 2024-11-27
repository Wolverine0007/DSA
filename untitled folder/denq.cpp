#include <iostream>
using namespace std;

const int size = 20;

class dequeue {
    int a[size], front, rear;

public:
    dequeue() {
        front = rear = -1;
    }
    void insertbig();
    void insertlast();
    void deletebig();
    void deleteend();
    void display();
};

void dequeue::insertbig() {
    int choice = 1;
    int element;
    do {
        cout << "Enter Element to be inserted: ";
        cin >> element;
        if (front == -1) {
            front = 0;
            a[++rear] = element;
        } else if (front > 0) {
            a[--front] = element;
        } else {
            cout << "Item Cannot Be Added at the Front (Overflow)" << endl;
        }
        cout << "1. Add Item\n2. Exit\n";
        cin >> choice;
    } while (choice == 1);
    cout << "********************************************" << endl;
}

void dequeue::insertlast() {
    int choice = 1;
    int element;
    do {
        cout << "Enter Element to be inserted: ";
        cin >> element;
        if (rear == size - 1) {
            cout << "Item Cannot Be Added at the Rear (Overflow)" << endl;
        } else if (front == -1) {
            front = 0;
            a[++rear] = element;
        } else {
            a[++rear] = element;
        }
        cout << "1. Add Item\n2. Exit\n";
        cin >> choice;
    } while (choice == 1);
    cout << "********************************************" << endl;
}

void dequeue::deletebig() {
    if (front == -1) {
        cout << "Queue is Empty, Cannot Delete Item" << endl;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    cout << "********************************************" << endl;
}

void dequeue::deleteend() {
    if (front == -1) {
        cout << "Queue is Empty, Cannot Delete Item" << endl;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
    cout << "********************************************" << endl;
}

void dequeue::display() {
    if (front == -1) {
        cout << "Queue is Empty, Cannot Display Anything" << endl;
    } else {
        for (int i = front; i <= rear; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    cout << "********************************************" << endl;
}

int main() {
    dequeue dq;
    int choice;
    do {
        cout << "1. Input Restricted Queue\n2. Output Restricted Queue\n3. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Input Restricted: Insertion at Rear Only" << endl;
            int subChoice;
            do {
                cout << "1. Insert Item\n2. Delete Beginning\n3. Delete End\n4. Display\n5. Exit\n";
                cin >> subChoice;
                switch (subChoice) {
                case 1:
                    dq.insertlast();
                    break;
                case 2:
                    dq.deletebig();
                    break;
                case 3:
                    dq.deleteend();
                    break;
                case 4:
                    dq.display();
                    break;
                case 5:
                    subChoice = 0;
                    break;
                }
            } while (subChoice != 0);
            break;
        }
        case 2: {
            cout << "Output Restricted: Deletion from Front Only" << endl;
            int subChoice;
            do {
                cout << "1. Delete Item\n2. Insert Beginning\n3. Insert End\n4. Display\n5. Exit\n";
                cin >> subChoice;
                switch (subChoice) {
                case 1:
                    dq.deletebig();
                    break;
                case 2:
                    dq.insertbig();
                    break;
                case 3:
                    dq.insertlast();
                    break;
                case 4:
                    dq.display();
                    break;
                case 5:
                    subChoice = 0;
                    break;
                }
            } while (subChoice != 0);
            break;
        }
        case 3:
            cout << "Exiting Program." << endl;
            break;
        default:
            cout << "Invalid Choice. Please Try Again." << endl;
        }
    } while (choice != 3);
    return 0;
}
