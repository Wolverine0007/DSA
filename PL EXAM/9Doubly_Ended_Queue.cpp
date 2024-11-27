#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class DeQueue {
    public:
        int front;
        int rear;
        int queue[MAX];
        
        DeQueue() {
            front = rear = -1;
        }

        // Functions
        void insert_begin(int ele);
        void insert_end(int ele);
        void delete_begin();
        void delete_end();
        void display();
};

void DeQueue::insert_begin(int ele) {
    if (front == 0) {
        cout << "Insertion NOT Possible (Queue is full)" << endl;
    } else if (front == -1) {
        front = rear = 0;
        queue[front] = ele;
    } else {
        front = front - 1;
        queue[front] = ele;
    }
}

void DeQueue::insert_end(int ele) {
    if (rear == MAX - 1) {
        cout << "Insertion NOT Possible (Queue is full)" << endl;
    } else if (rear == -1) {
        front = rear = 0;
        queue[rear] = ele;
    } else {
        rear = rear + 1;
        queue[rear] = ele;
    }
}

void DeQueue::delete_begin() {
    if (front == -1) {
        cout << "Deletion NOT Possible (Queue is empty)" << endl;
    } else if (front == rear) {
        cout << "Data to be deleted: " << queue[front] << endl;
        front = rear = -1;
    } else {
        cout << "Data to be deleted: " << queue[front] << endl;
        front = front + 1;
    }
}

void DeQueue::delete_end() {
    if (rear == -1) {
        cout << "Deletion NOT Possible (Queue is empty)" << endl;
    } else if (front == rear) {
        cout << "Data to be deleted: " << queue[rear] << endl;
        front = rear = -1;
    } else {
        cout << "Data to be deleted: " << queue[rear] << endl;
        rear = rear - 1;
    }
}

void DeQueue::display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    DeQueue p, q;
    int val, ch, ch1;
    
    do {
        cout << "Select the scenario" << endl;
        cout << "1. I/P restricted" << endl;
        cout << "2. O/P restricted" << endl;
        cout << "3. Exit" << endl;
        cin >> ch;

        switch(ch) {
            case 1:
                do {
                    cout << "Select option" << endl;
                    cout << "1. Insertion End\n2. Deletion Beginning" << endl;
                    cout << "3. Deletion End" << endl;
                    cout << "4. Display\n5. EXIT" << endl;
                    cin >> ch1;
                    switch(ch1) {
                        case 1:
                            cout << "Enter value to insert at the end: ";
                            cin >> val;
                            p.insert_end(val);
                            break;
                        case 2:
                            p.delete_begin();
                            break;
                        case 3:
                            p.delete_end();
                            break;
                        case 4:
                            p.display();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Invalid Choice" << endl;
                            break;
                    }
                } while (ch1 != 5);
                break;
            
            case 2:
                do {
                    cout << "Select option" << endl;
                    cout << "1. Deletion Beginning\n2. Insertion Beginning" << endl;
                    cout << "3. Insertion End" << endl;
                    cout << "4. Display\n5. EXIT" << endl;
                    cin >> ch1;
                    switch(ch1) {
                        case 1:
                            q.delete_begin();
                            break;
                        case 2:
                            cout << "Enter value to insert at the beginning: ";
                            cin >> val;
                            q.insert_begin(val);
                            break;
                        case 3:
                            cout << "Enter value to insert at the end: ";
                            cin >> val;
                            q.insert_end(val);
                            break;
                        case 4:
                            q.display();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Invalid Choice" << endl;
                            break;
                    }
                } while (ch1 != 5);
                break;
            
            case 3:
                break;
            
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    } while (ch != 3);
    
    return 0;
}


