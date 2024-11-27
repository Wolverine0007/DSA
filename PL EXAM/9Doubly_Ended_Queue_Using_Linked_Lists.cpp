#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyEndedQueue_DoublyLL
{
public:
    Node *front;
    Node *rear;
    DoublyEndedQueue_DoublyLL()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty();
    void enqueue_at_front(int data);
    void enqueue_at_rear(int data);
    void dequeue_at_front();
    void dequeue_at_rear();
    void display_queue();
};

bool DoublyEndedQueue_DoublyLL ::isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    return false;
}

void DoublyEndedQueue_DoublyLL ::enqueue_at_front(int data)
{
    Node *temp = new Node(data);
    if (isEmpty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}
void DoublyEndedQueue_DoublyLL ::enqueue_at_rear(int data)
{
    Node *temp = new Node(data);
    if (isEmpty())
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        temp->prev = rear;
        rear = rear->next;
    }
}
void DoublyEndedQueue_DoublyLL ::dequeue_at_front()
{
    Node *temp = front;
    if (isEmpty())
    {
        cout << "Queue is Already Empty!" << endl;
        return;
    }
    else if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
        temp->next = NULL;
    }
    delete temp;
}
void DoublyEndedQueue_DoublyLL ::dequeue_at_rear()
{
    Node *temp = rear;
    if (isEmpty())
    {
        cout << "Queue is Already Empty!" << endl;
        return;
    }
    else if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
        temp->prev = NULL;
    }
    delete temp;
}

void DoublyEndedQueue_DoublyLL ::display_queue()
{
    Node *ptr = front;
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    DoublyEndedQueue_DoublyLL Q1;
    DoublyEndedQueue_DoublyLL Q2;
    int choice = 0;

    do
    {
        cout << "1. Input Restricted Queue" << endl;
        cout << "2. Output Restricted Queue" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            int choice1;
            do
            {
                cout << "1. Enqueue at Rear" << endl;
                cout << "2. Dequeue at Front" << endl;
                cout << "3. Dequeue at Rear" << endl;
                cout << "4. Display Queue" << endl;
                cout << "5. Back Menu" << endl;
                cout << "Enter your choice : ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    int x;
                    cout << "Enter value : ";
                    cin >> x;
                    Q1.enqueue_at_rear(x);
                    break;
                case 2:
                    Q1.dequeue_at_front();
                    break;
                case 3:
                    Q1.dequeue_at_rear();
                    break;
                case 4:
                    Q1.display_queue();
                    break;
                case 5:
                    break;
                }
            } while (choice1 != 5);
            break;
        case 2:

            int choice2;
            do
            {
                cout << "1. Enqueue at Front" << endl;
                cout << "2. Enqueue at Rear" << endl;
                cout << "3. Dequeue at Front" << endl;
                cout << "4. Display Queue" << endl;
                cout << "5. Back Menu" << endl;
                cout << "Enter your choice : ";
                cin >> choice2;
                int x;
                switch (choice2)
                {
                case 1:
                    cout << "Enter value : ";
                    cin >> x;
                    Q2.enqueue_at_front(x);
                    break;
                case 2:
                    cout << "Enter value : ";
                    cin >> x;
                    Q2.enqueue_at_rear(x);
                    break;
                case 3:
                    Q2.dequeue_at_front();
                    break;
                case 4:
                    Q2.display_queue();
                    break;
                case 5:
                    break;
                }
            } while (choice2 != 5);
            break;
        }
    } while (choice != 10);
}
