#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

    
    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    void sort() {
        if (!head) return;
        bool swapped;
        Node* current;
        do {
            swapped = false;
            current = head;
            while (current->next) {
                if (current->data > current->next->data) {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

   
    void merge(DoublyLinkedList& list2) {
        Node* list1Ptr = head;
        Node* list2Ptr = list2.head;

        cout << "Merged List: ";
        while (list1Ptr && list2Ptr) {
            if (list1Ptr->data < list2Ptr->data) {
                cout << list1Ptr->data << " ";
                list1Ptr = list1Ptr->next;
            } else {
                cout << list2Ptr->data << " ";
                list2Ptr = list2Ptr->next;
            }
        }
       
        while (list1Ptr) {
            cout << list1Ptr->data << " ";
            list1Ptr = list1Ptr->next;
        }
        while (list2Ptr) {
            cout << list2Ptr->data << " ";
            list2Ptr = list2Ptr->next;
        }
        cout << endl;
    }

   
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list1, list2;
    int choice, value, n;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add marks to List 1\n";
        cout << "2. Add marks to List 2\n";
        cout << "3. Sort List 1\n";
        cout << "4. Sort List 2\n";
        cout << "5. Merge both sorted lists\n";
        cout << "6. Display List 1\n";
        cout << "7. Display List 2\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter marks to add to List 1: ";
            cin >> value;
            list1.append(value);
            break;
        case 2:
            cout << "Enter marks to add to List 2: ";
            cin >> value;
            list2.append(value);
            break;
        case 3:
            cout << "Sorting List 1\n";
            list1.sort();
            break;
        case 4:
            cout << "Sorting List 2\n";
            list2.sort();
            break;
        case 5:
            cout << "Merging both sorted lists\n";
            list1.merge(list2);
            break;
        case 6:
            cout << "List 1: ";
            list1.display();
            break;
        case 7:
            cout << "List 2: ";
            list2.display();
            break;
        case 8:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

