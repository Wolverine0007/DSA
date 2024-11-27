#include <iostream>
using namespace std;

// Doubly Linked List Node Class
class node {
public:
    int rno;
    float marks;
    string name;
    node* next;
    node* prev;
};

// Doubly Linked List Class
class DLL {
    node* head;

public:
    DLL() {
        head = NULL;
    }

    void create();
    void display();
    void sort();
    void merge(DLL& D1, DLL& D2);
};

void DLL::create() {
    node* last = NULL;
    char choice = 'Y';  // using 'Y' or 'N' for input
    do {
        node* temp = new node;
        cout << "Enter roll number, Name, Marks: ";
        cin >> temp->rno >> temp->name >> temp->marks;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }

        cout << "Do you want to add more nodes? 'Y' or 'N' : ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}

void DLL::display() {
    if (head == NULL) {
        cout << "Empty LIST" << endl;
    } else {
        node* ptr = head;
        while (ptr != NULL) {
            cout << "Roll no. : " << ptr->rno << endl;
            cout << "Name : " << ptr->name << endl;
            cout << "Marks : " << ptr->marks << endl;
            ptr = ptr->next;
        }
    }
}

void DLL::merge(DLL& D1, DLL& D2) {
    node *p, *q, *r;

    if (D1.head == NULL && D2.head == NULL) {
        cout << "Both lists are empty" << endl;
        return;
    }

    if (D1.head == NULL) {
        head = D2.head;
        return;
    }

    if (D2.head == NULL) {
        head = D1.head;
        return;
    }

    p = D1.head;
    q = D2.head;

    // Start with the smaller of the first two elements
    if (p->marks <= q->marks) {
        head = p;
        p = p->next;
    } else {
        head = q;
        q = q->next;
    }

    r = head;

    while (p != NULL && q != NULL) {
        if (p->marks <= q->marks) {
            r->next = p;
            p->prev = r;
            p = p->next;
        } else {
            r->next = q;
            q->prev = r;
            q = q->next;
        }
        r = r->next;
    }

    if (p == NULL) {
        r->next = q;
        if (q != NULL) q->prev = r;
    } else {
        r->next = p;
        if (p != NULL) p->prev = r;
    }

    cout << "After Merging" << endl;
    display();
}

void DLL::sort() {
    if (head == NULL || head->next == NULL) {
        return;  // List is already sorted
    }

    node* i = head;
    node* j;
    node* temp;
    
    // Bubble Sort on the list
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->marks > j->marks) {
                // Swap marks and rno
                temp = i;
                i = j;
                j = temp;
                int temp_rno = i->rno;
                float temp_marks = i->marks;
                string temp_name = i->name;
                i->rno = j->rno;
                i->marks = j->marks;
                i->name = j->name;
                j->rno = temp_rno;
                j->marks = temp_marks;
                j->name = temp_name;
            }
            j = j->next;
        }
        i = i->next;
    }
    cout << "After Sorting" << endl;
    display();
}

int main() {
    DLL D1, D2, D3;
    int choice;
    do {
        cout << "\tMENU" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. SORT" << endl;
        cout << "4. MERGE" << endl;
        cout << "5. EXIT" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter details for first list: " << endl;
            D1.create();
            cout << "Enter details for second list: " << endl;
            D2.create();
            break;
        case 2:
            cout << "First list details: " << endl;
            D1.display();
            cout << "Second list details: " << endl;
            D2.display();
            break;
        case 3:
            cout << "Sorting first list: " << endl;
            D1.sort();
            cout << "Sorting second list: " << endl;
            D2.sort();
            break;
        case 4:
            cout << "Merging the lists: " << endl;
            D3.merge(D1, D2);
            break;
        case 5:
            break;
        default:
            cout << "INVALID CHOICE" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}


