#include <bits/stdc++.h>
using namespace std;
#define N 5
#define Quantum 2

class Process {
    public:
        int PID;
        int BT; // Burst Time
        int AT; // Arrival Time
        int remainingBT; // Remaining Burst Time

        Process(int id, int arrival_time, int burst_time) {
            PID = id;
            AT = arrival_time;
            BT = burst_time;
            remainingBT = burst_time;
        }
};

class Queue {
    public:
        Process* ready[10];
        int front, rear;
        
        Queue() {
            front = rear = -1;
        }

        bool isEmpty() {
            return front == -1;
        }

        bool isFull() {
            return (rear + 1) % 10 == front;
        }

        void Enqueue(Process* p) {
            if (isFull()) {
                cout << "Queue is full. Insertion not possible." << endl;
            } else {
                if (front == -1) front = 0;
                rear = (rear + 1) % 10;
                ready[rear] = p;
            }
        }

        Process* Dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Deletion not possible." << endl;
                return NULL;
            } else {
                Process* temp = ready[front];
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % 10;
                }
                return temp;
            }
        }
};

// Function to simulate Round Robin Scheduling
void roundRobin(Process processes[], int n) {
    Queue q;
    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        // Add processes that have arrived to the queue
        for (int i = 0; i < n; i++) {
            if (processes[i].AT <= currentTime && processes[i].remainingBT > 0) {
                q.Enqueue(&processes[i]);
            }
        }

        if (!q.isEmpty()) {
            // Get the next process from the queue
            Process* currentProcess = q.Dequeue();

            // Execute the process for a time quantum
            int timeSlice = min(currentProcess->remainingBT, Quantum);
            currentProcess->remainingBT -= timeSlice;
            currentTime += timeSlice;

            cout << "Process P" << currentProcess->PID << " executed for " << timeSlice << " units, Remaining Burst Time: " << currentProcess->remainingBT << endl;

            // If the process is not yet finished, put it back in the queue
            if (currentProcess->remainingBT > 0) {
                q.Enqueue(currentProcess);
            } else {
                completed++;
                cout << "Process P" << currentProcess->PID << " completed at time " << currentTime << endl;
            }
        } else {
            currentTime++; // No process is ready to run, so just increment time
        }
    }

    cout << "All processes completed at time " << currentTime << endl;
}

int main() {
    // Creating 5 processes with Arrival Times and Burst Times
    Process processes[] = {
        Process(1, 0, 5),
        Process(2, 1, 3),
        Process(3, 2, 1),
        Process(4, 3, 2),
        Process(5, 4, 3)
    };

    // Execute the Round Robin Scheduling
    roundRobin(processes, N);

    return 0;
}


