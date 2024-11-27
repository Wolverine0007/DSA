#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

class DoublyEndedQueue_Array
{
public:
    int arr[SIZE];
    int front;
    int rear;
    DoublyEndedQueue_Array()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty();
    void enqueue_at_front(int x);
    void enqueue_at_rear(int x);
    int dequeue_at_front();
    int dequeue_at_rear();
    void display_queue();
};

bool DoublyEndedQueue_Array ::isEmpty()
{
    return (front == -1 && rear == -1);
}

void DoublyEndedQueue_Array ::enqueue_at_front(int x)
{
    if (rear == SIZE - 1 && front == 0)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        front--;
    }
    arr[front] = x;
}

void DoublyEndedQueue_Array ::enqueue_at_rear(int x)
{
    if (rear == SIZE - 1 && front == 0)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = x;
}

int DoublyEndedQueue_Array ::dequeue_at_front()
{
    int x = arr[front];
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return x;
}

int DoublyEndedQueue_Array ::dequeue_at_rear()
{
    int x = arr[rear];
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return 0;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear--;
    }
    return x;
}

void DoublyEndedQueue_Array ::display_queue()
{
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    DoublyEndedQueue_Array Q1;
    DoublyEndedQueue_Array Q2;
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
