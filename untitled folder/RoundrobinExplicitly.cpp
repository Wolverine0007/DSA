#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear;
    int arr[5]; 
public:
    CircularQueue() {
        front = rear = -1;
    }
    bool isempty();
    bool isfull();
    void enque(int value);
    int deque();
    void roundscheduling(int process[], int n, int bursttime[], int timequantum);
};

bool CircularQueue::isempty() {
    return front == -1 && rear == -1;
}

bool CircularQueue::isfull() {
    return (rear + 1) % 5 == front;
}

void CircularQueue::enque(int value) {
    if (isfull()) {
        cout << "Queue is full" << endl;
    } else {
        rear = (rear + 1) % 5;
        arr[rear] = value;
        if (front == -1) {
            front = 0;
        }
    }
}
int CircularQueue::deque() {
    if (isempty()) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        int value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 5;
        }
        return value;
    }
}

void CircularQueue::roundscheduling(int process[], int n, int bursttime[], int timequantum) {
    int remaining_bursttime[n];
    for (int i = 0; i < n; i++) {
        remaining_bursttime[i] = bursttime[i];
        enque(process[i]); 
    }
    int currenttime = 0;
    while (!isempty()) {
        int proc = deque(); 
                                                 
        if (remaining_bursttime[proc - 1] > 0) {
           
            if (remaining_bursttime[proc - 1] > timequantum) {
                currenttime += timequantum;
                remaining_bursttime[proc - 1] -= timequantum;
                cout << "Process " << proc << " executed for " << timequantum << " units; remaining burst time: " << remaining_bursttime[proc - 1] << endl;
                enque(proc); 
            } else {
               
                currenttime += remaining_bursttime[proc - 1];
                cout << "Process " << proc << " completed at time " << currenttime << endl;
                remaining_bursttime[proc - 1] = 0;
            }
        }
    }
}
int main() {
    CircularQueue cq;
    int n, timequantum;

    cout << "Enter number of processes: ";
    cin >> n;

    int process[n];
    int bursttime[n];

    cout << "Enter process ID and burst time:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> process[i] >> bursttime[i];
    }

    cout << "Enter quantum time: ";
    cin >> timequantum;

    cq.roundscheduling(process, n, bursttime, timequantum);

    return 0;
}
