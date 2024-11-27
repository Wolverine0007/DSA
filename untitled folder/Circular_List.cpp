#include<iostream>
using namespace std;

class Node {
public:
    int token_no;
    Node *next;
};

class PizzaParlor {
private:
    Node *head;
public:
    PizzaParlor() {
        head = NULL;
    }
    void inputToken(Node *temp);
    void createOrder();
    void serveOrder();
    void addOrder();
    void showOrders();
};

void PizzaParlor::inputToken(Node *temp) {
    cout << "Enter token number: ";
    cin >> temp->token_no;
}

void PizzaParlor::createOrder() {
    Node *temp, *p;
    int cont = 1;
    do {
        temp = new Node;
        inputToken(temp);
        temp->next = temp;

        if (head == NULL) {
            head = temp;
            temp->next=head;
            
        } else {
            p=head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
        }
        cout << "Enter 1 to continue adding orders: ";
        cin >> cont;
    } while (cont == 1);
}

void PizzaParlor::showOrders() {
    if (head == NULL) {
        cout << "No ongoing orders." << endl;
        return;
    }
    Node *p = head;
    while (p->next != head) {
        cout << p->token_no << " - ";
        p = p->next;
    }
    cout << p->token_no << endl;
}

void PizzaParlor::addOrder() {
    Node *temp, *p;
    temp = new Node;
    inputToken(temp);
    
    
    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        p = head;
        while (p->next != head) {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
    cout << "Order added successfully." << endl;
}

void PizzaParlor::serveOrder() {
    if (head == NULL) {
        cout << "No orders to serve." << endl;
        return;
    }
    
    Node *p = head;
    Node *q = head;
    while (q->next != head) {
        q = q->next;
    }
    if (head == head->next) {
        head = NULL;
    } else {
        head = head->next;
        q->next = head;
    }
    delete p;
    cout << "Order served successfully." << endl;
}

int main() {
    PizzaParlor parlor;
    int choice = 1;
    do {
        int ch = 0;
        cout << "Enter 1 to create orders" << endl;
        cout << "Enter 2 to display orders" << endl;
        cout << "Enter 3 to serve the next order" << endl;
        cout << "Enter 4 to add a new order" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            parlor.createOrder();
            parlor.showOrders();
            break;
        case 2:
            parlor.showOrders();
            break;
        case 3:
            parlor.serveOrder();
            parlor.showOrders();
            break;
        case 4:
            parlor.addOrder();
            parlor.showOrders();
            break;
        default:
            cout << "Invalid choice." << endl;
        }
        cout << "Enter 1 to continue: ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
