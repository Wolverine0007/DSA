#include <bits/stdc++.h>
using namespace std;

class Node{                         // class node has 4 data and 1 node
    public:                         // singly linked list logic
    int rollno;
    string name;
    string branch;
    char div;
    Node* next;
};

class SLL{                          //SLL = singly linked list
    public:
    Node* head;

    SLL(){                          // by default its head will be null so we use it to add the further node and move the next address here
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

void SLL :: create(){
    char continu;
    Node* newNode;
    Node* current;

    do{
        newNode = new Node();
        cout << "Enter roll no: ";
        cin >> newNode->rollno;

        cout << "Enter name: ";
        cin >> newNode->name;

        cout << "Enter branch: ";
        cin >> newNode->branch;

        cout << "Enter division: ";
        cin >> newNode->div;

        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }

        cout << "Do you want to add another node?(y/n): ";
        cin >> continu;

    }while(continu != 'n');
}

void SLL :: display(){
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else{
    Node* temp = head;

    while(temp != NULL){
        cout << "\nRoll no: " << temp->rollno;
        cout << "\nName: " << temp->name;
        cout << "\nBranch: " << temp->branch;
        cout << "\nDivision: " << temp->div << endl;

        temp = temp->next;
    }
    }
}

void SLL :: search(){
    int rno, flag = 0, loc=1;       // flag is just for understanding if there is no record flag will be 0 or else 1
    // loc is the location at which we find the data
    Node* ptr = NULL;

    if(head == NULL){
        cout << "Linked List is empty.\n";
    }
    else{
        cout << "Enter roll no to be searched: ";
        cin >> rno;
        ptr = head;

        while(ptr != NULL){
            if(ptr->rollno == rno){
                flag = 1;
                break;
            }
            else{
                ptr = ptr->next;
                loc++;
            }
        }

        if(flag == 1){
            cout << "Record found at location " << loc << endl;
        }
        else{
            cout << "Record not found!\n";
        }
    }
}

void SLL :: update(){
    int rno, flag = 0, loc=1, choice;

    Node* ptr = NULL;

    if(head == NULL){
        cout << "Linked List is empty.\n";
    }
    else{
        cout << "Enter roll no to be updated: ";
        cin >> rno;
        ptr = head;

        while(ptr != NULL){
            if(ptr->rollno == rno){
                flag = 1;
                break;
            }
            else{
                ptr = ptr->next;
                loc++;
            }
        }

        if(flag == 1){
            cout << "Record found at location " << loc << endl;

            int ch;
            do{
                cout << "What do you want to update?" << endl;
                cout << "1. Roll no" << endl; 
                cout << "2. Name" << endl;
                cout << "3. Branch" << endl;
                cout << "4. Division" << endl;
                cout << "5. Exit" << endl;
                cin >> ch;

                switch(ch){
                    case 1:
                        cout << "Enter new roll no: ";
                        cin >> ptr->rollno;
                        break;

                    case 2:
                        cout << "Enter new name: ";
                        cin >> ptr->name;
                        break;
                    
                    case 3:
                        cout << "Enter new branch: ";
                        cin >> ptr->branch;
                        break;
                    
                    case 4:
                        cout << "Enter new Division: ";
                        cin >> ptr->div;
                        break;

                    case 5: 
                        break;

                    default: 
                        cout << "Invalid choice!\n";
                        break;
                }
            }while(ch != 5);
        }
        else{
            cout << "Record not found!, Update not possible.\n";
        }
    }
    cout << "Updated Records:\n";
    display();
}

void SLL :: sort(){
    Node* ptr = NULL;
    Node* ptr1 = NULL;
    int r;
    char d;
    string n;
    string b;

    ptr1=head;

    while(ptr1 != NULL){
        ptr = ptr1->next;
        while(ptr != NULL){
            if(ptr1->rollno > ptr->rollno){
                r = ptr1->rollno;
                ptr1->rollno = ptr->rollno;
                ptr->rollno = r;

                d = ptr1->div;
                ptr1->div = ptr->div;
                ptr->div = d;

                n = ptr->name;
                ptr1->name = ptr->name;
                ptr->name = n;

                b = ptr1->branch;
                ptr1->branch = ptr->branch;
                ptr->branch = b;

                ptr = ptr->next;
            }
            else{
                ptr = ptr->next;
            }
        }
        ptr1 = ptr1->next;
    }

    cout << "Sorted list is: " << endl;
    display(); 
}

void SLL::insert() {
    int choice;
    do {
        cout << "Select insertion scenario" << endl;
        cout << "1. At beginning" << endl;
        cout << "2. At end" << endl;
        cout << "3. At specific location" << endl;
        cout << "4. After specific data node (roll number)" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Insert at the beginning
                Node* firstNode = new Node();
                cout << "Enter roll no: ";
                cin >> firstNode->rollno;

                cout << "Enter name: ";
                cin >> firstNode->name;

                cout << "Enter Branch: ";
                cin >> firstNode->branch;

                cout << "Enter Division: ";
                cin >> firstNode->div;

                firstNode->next = head;
                head = firstNode;

                cout << "Linked list after insertion: " << endl;
                display();
                break;
            }
            case 2: {
                // Insert at the end
                Node* ptr = head;
                if (ptr == NULL) {
                    // List is empty, so just create a new head node
                    head = new Node();
                    cout << "Enter roll no: ";
                    cin >> head->rollno;

                    cout << "Enter name: ";
                    cin >> head->name;

                    cout << "Enter Branch: ";
                    cin >> head->branch;

                    cout << "Enter Division: ";
                    cin >> head->div;

                    head->next = NULL;
                } else {
                    // Traverse to the end
                    while (ptr->next != NULL) {
                        ptr = ptr->next;
                    }
                    Node* lastNode = new Node();
                    cout << "Enter roll no: ";
                    cin >> lastNode->rollno;

                    cout << "Enter name: ";
                    cin >> lastNode->name;

                    cout << "Enter Branch: ";
                    cin >> lastNode->branch;

                    cout << "Enter Division: ";
                    cin >> lastNode->div;

                    lastNode->next = NULL;
                    ptr->next = lastNode;
                }

                cout << "Linked list after insertion: " << endl;
                display();
                break;
            }
            case 3: {
                // Insert at a specific location
                int loc;
                Node* temp = new Node();
                cout << "Enter roll no: ";
                cin >> temp->rollno;

                cout << "Enter name: ";
                cin >> temp->name;

                cout << "Enter Branch: ";
                cin >> temp->branch;

                cout << "Enter Division: ";
                cin >> temp->div;

                cout << "Enter location: ";
                cin >> loc;

                Node* ptr = head;
                for (int i = 1; i < loc - 1 && ptr != NULL; i++) {
                    ptr = ptr->next;
                }

                if (ptr != NULL) {
                    temp->next = ptr->next;
                    ptr->next = temp;
                } else {
                    cout << "Invalid location" << endl;
                }

                cout << "Linked list after insertion: " << endl;
                display();
                break;
            }
            case 4: {
                // Insert after a specific data node (roll number)
                int rollno;
                cout << "Enter the roll number after which you want to insert: ";
                cin >> rollno;

                Node* ptr = head;
                while (ptr != NULL && ptr->rollno != rollno) {
                    ptr = ptr->next;
                }

                if (ptr != NULL) {
                    Node* temp = new Node();
                    cout << "Enter roll no: ";
                    cin >> temp->rollno;

                    cout << "Enter name: ";
                    cin >> temp->name;

                    cout << "Enter Branch: ";
                    cin >> temp->branch;

                    cout << "Enter Division: ";
                    cin >> temp->div;

                    temp->next = ptr->next;
                    ptr->next = temp;

                    cout << "Linked list after insertion: " << endl;
                    display();
                } else {
                    cout << "Roll number not found" << endl;
                }
                break;
            }
            case 5: {
                cout << "Exiting insertion menu" << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }

    } while (choice != 5);
}

void SLL::deleteNode() {
    int choice;
    do {
        cout << "Select Deletion scenario" << endl;
        cout << "1. At beginning" << endl;
        cout << "2. At end" << endl;
        cout << "3. At specific location" << endl;
        cout << "4. Delete specific data node (roll number)" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        Node* p = NULL;
        Node* prev = NULL;

        switch (choice) {
            case 1:
                // Delete at the beginning
                if (head == NULL) {
                    cout << "List is empty!" << endl;
                } else {
                    p = head;
                    head = head->next;
                    delete p;
                    cout << "Node deleted at the beginning." << endl;
                    display();
                }
                break;

            case 2:
                // Delete at the end
                if (head == NULL) {
                    cout << "List is empty!" << endl;
                } else if (head->next == NULL) {
                    // If only one node exists
                    delete head;
                    head = NULL;
                } else {
                    p = head;
                    while (p->next != NULL) {
                        prev = p;
                        p = p->next;
                    }
                    prev->next = NULL;
                    delete p;
                }
                cout << "Node deleted at the end." << endl;
                display();
                break;

            case 3: {
                // Delete at a specific location
                int pos;
                cout << "Enter the location at which node is to be deleted: ";
                cin >> pos;
                p = head;

                if (pos == 1) {
                    head = head->next;
                    delete p;
                } else {
                    for (int i = 1; i < pos && p != NULL; i++) {
                        prev = p;
                        p = p->next;
                    }

                    if (p == NULL) {
                        cout << "Invalid location!" << endl;
                    } else {
                        prev->next = p->next;
                        delete p;
                    }
                }
                cout << "Node deleted at position " << pos << endl;
                display();
                break;
            }

            case 4: {
                // Delete specific node by roll number
                int rollno, flag = 0;
                cout << "Enter the roll number of the node to delete: ";
                cin >> rollno;

                p = head;
                while (p != NULL) {
                    if (p->rollno == rollno) {
                        flag = 1;
                        break;
                    }
                    prev = p;
                    p = p->next;
                }

                if (flag == 1) {
                    if (p == head) {
                        head = p->next;
                    } else if (p->next == NULL) {
                        prev->next = NULL;
                    } else {
                        prev->next = p->next;
                    }
                    delete p;
                    cout << "Node with roll number " << rollno << " deleted." << endl;
                } else {
                    cout << "Node not found!" << endl;
                }
                display();
                break;
            }

            case 5:
                cout << "Exiting deletion menu" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 5);
}

int main(){

    SLL list;
    int choice;

    
    do{
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Sort"<<endl;
        cout<<"5. Insert"<<endl;
        cout<<"6. Update"<<endl;
        cout<<"7. Delete"<<endl;
        cout<<"8. Exit"<<endl;
        cin>>choice;

        switch (choice)
		    {
		    case 1:
		        list.create();
		        break;
		    case 2:
		        list.display();
		        break;
		    case 3:
		        list.search();
		        break;
		    case 4:
		        list.sort();
		        break;
		    case 5:
		        list.insert();
		        break;
		    case 6:
		        list.update();
		        break;
		    case 7:
		        list.deleteNode();
		        break;
		    case 8:
		        exit(0);
		        break;
		    default:
		        break;
		    }
    }while (choice != 8);
}
