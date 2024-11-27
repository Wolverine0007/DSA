#include <iostream>
using namespace std;

class node {
public:
    int prn;
    char name[50];
    char branch[30];
    float cgpa;
    node* next;
};

class linkedlist {
public:
    node* head;

public:
    linkedlist() {
        head = NULL;
    }
    void make_list();
    void display_list();
    void insert_at_start();
    void insert_at_last();
    void insert_bet_pos();
    void insert_bet_val();
    void deletefirst();
    void deletelast();
    void deleteval();
    void deletepos();
    void sort();
    void search();
};

void linkedlist::make_list() {
    node* p;
    node* temp = NULL;
    int choice = 1;
    while (choice == 1) {
        if (head == NULL) {
            head = new node;
            cout << "Enter the PRN, Name, Branch, and CGPA for the first node:" << endl;
            cin >> head->prn >> head->name >> head->branch >> head->cgpa;
            head->next = NULL;
            p = head;
        } else {
            temp = new node;
            cout << "Enter PRN, Name, Branch, and CGPA for the next node:" << endl;
            cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
            temp->next = NULL;
            p->next = temp;
            p = p->next;
        }
        cout << "Enter 1 to insert another node, or 0 to stop: ";
        cin >> choice;
    }
}

void linkedlist::display_list() {
    node* p = head;
    while (p != NULL) {
        cout << p->prn << endl;
        cout << p->name << endl;
        cout << p->branch << endl;
        cout << p->cgpa << endl;
        cout << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void linkedlist::insert_at_start() {
    node* temp = new node;
    cout << "Enter the information:" << endl;
    cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
    temp->next = head;
    head = temp;
}

void linkedlist::insert_at_last() {
    node* p = head;
    node* temp = new node;
    cout << "Enter the information:" << endl;
    cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void linkedlist::insert_bet_pos() {
    int pos;
    cout << "Enter the position to insert at:" << endl;
    cin >> pos;

    node* temp = new node;
    cout << "Enter the information:" << endl;
    cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
    temp->next = NULL;

    if (pos == 1) {
        insert_at_start();
        return;
    }

    node* p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p != NULL) {
        temp->next = p->next;
        p->next = temp;
    } else {
        cout << "Position out of range" << endl;
    }
}

void linkedlist::insert_bet_val() {
    int p_val;
    cout << "Enter prn to insert after:" << endl;
    cin >> p_val;

    node* temp = new node;
    cout << "Enter the information:" << endl;
    cin >> temp->prn >> temp->name >> temp->branch >> temp->cgpa;
    temp->next = NULL;

    node* p = head;
    while (p != NULL && p->prn != p_val) {
        p = p->next;
    }

    if (p != NULL) {
        temp->next = p->next;
        p->next = temp;
    } else {
        cout << "PRN not found" << endl;
    }
}

void linkedlist::deletefirst() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* p = head;
    head = p->next;
    delete p;
}

void linkedlist::deletelast() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node* p = head;
    node* q = NULL;

    while (p->next != NULL) {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    delete p;
}

void linkedlist::deleteval() {
    int p_val;
    cout << "Enter the prn:" << endl;
    cin >> p_val;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* p = head;
    node* q = NULL;

    if (head->prn == p_val) {
        head = head->next;
        delete p;
        return;
    }

    while (p != NULL && p->prn != p_val) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;

    if (p == NULL) {
        cout << "PRN not found" << endl;
        return;
    }

    
}

void linkedlist::deletepos() {
    int pos;
    cout << "Enter the pos to delete:" << endl;
    cin >> pos;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (pos == 1) {
        deletefirst();
        return;
    }

    node* p = head;
    node* q = NULL;

    for (int i = 1; i < pos && p != NULL; i++) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    q->next = p->next;
    delete p;
}

void linkedlist::search() {
    int prno;
    node* p = head;
    cout << "Enter the PRN no: ";
    cin >> prno;

    while (p != NULL) {
        if (p->prn == prno) {
            cout << "Found in the list: " << endl;
            cout << "PRN: " << p->prn << endl;
            cout << "Name: " << p->name << endl;
            cout << "Branch: " << p->branch << endl;
            cout << "CGPA: " << p->cgpa << endl;

       
            char update_choice;
            cout << "Do you want to update this record? (y/n): ";
            cin >> update_choice;

            if (update_choice == 'y' || update_choice == 'Y') {
                cout << "Enter new details:" << endl;
                cout << "Enter PRN: ";
                cin >> p->prn;
                cout << "Enter Name: ";
                cin >> p->name;
                cout << "Enter Branch: ";
                cin >> p->branch;
                cout << "Enter CGPA: ";
                cin >> p->cgpa;
                cout << "Record updated successfully!" << endl;
            }
            return;
        }
        p = p->next;
    }

    cout << "PRN not found" << endl;
}


void linkedlist::sort(){

    bool exch;
    do{
        exch = false;
        node *p = head;
        node *q = head->next;

        while(q!=NULL){

            if(p->prn>q->prn){
                swap(p->prn,q->prn);
                exch = true;
            }
        }
    }while(exch);

    
    // node *p,*q;
    // int r; 
    // p=head;

    // while(p!=NULL){
    //     q=p->next;
    //     while(q!=NULL){ 
    //         if(p->prn>q->prn){
    //             r=p->prn;
    //             p->prn=q->prn;
    //             q->prn=r;
    //         }
    //         q = q->next;
    //     }
    //     p=p->next;
    // }
}



int main() {
    linkedlist l1;
    int choice, ch;

    do {
        cout << "Menu:" << endl;
        cout << "1. Create List" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Insert at Start" << endl;
        cout << "4. Insert at Last" << endl;
        cout << "5. Insert at Position" << endl;
        cout << "6. Insert after Value" << endl;
        cout << "7. Delete First Node" << endl;
        cout << "8. Delete Last Node" << endl;
        cout << "9. Delete by Value" << endl;
        cout << "10. Delete by Position" << endl;
        cout << "11. Sort List" << endl;
        cout << "12. Search and Update" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l1.make_list();
                break;
            case 2:
                l1.display_list();
                break;
            case 3:
                l1.insert_at_start();
                break;
            case 4:
                l1.insert_at_last();
                break;
            case 5:
                l1.insert_bet_pos();
                break;
            case 6:
                l1.insert_bet_val();
                break;
            case 7:
                l1.deletefirst();
                break;
            case 8:
                l1.deletelast();
                break;
            case 9:
                l1.deleteval();
                break;
            case 10:
                l1.deletepos();
                break;
            case 11:
                l1.sort();
                break;
            case 12:
                l1.search();
                break;
            case 0:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

       
        cout << "\nDo you want to continue? (1 for Menu, 0 to Exit): ";
        cin >> ch;

    } while (ch == 1);

    cout << "Program terminated." << endl;
    return 0;
}
