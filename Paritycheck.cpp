#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to count the number of 1s in a binary string
int countOnes(const string &data) {
    int count = 0;
    for (char bit : data) {
        if (bit == '1') count++;  // Increment count if bit is '1'
    }
    return count;
}

// Function to simulate transmission errors by randomly flipping bits
string randomize(string data) {
    srand(time(0));  // Seed random number generator with current time
    for (int i = 0; i < data.size(); i++) {
        // Randomly flip bit (1/3 chance for each bit)
        if (rand() % 3 == 0) { 
            data[i] = (data[i] == '0') ? '1' : '0';  // Flip 0 ↔ 1
        }
    }
    return data;
}

int main() {
    string data;
    cout << "Enter binary data: ";
    cin >> data;  // Input original binary data (e.g., 101100)

    // Count number of 1s in original data
    int count = countOnes(data);

    // Determine even parity bit
    // If count of 1s is even → parity bit = 0
    // If count of 1s is odd  → parity bit = 1
    char pb = (count % 2 == 0) ? '0' : '1';

    // Append parity bit to original data for transmission
    string transmitData = data + pb;
    cout << "Transmitted Data (with parity): " << transmitData << endl;

    // Simulate data corruption during transmission
    string receivedData = randomize(transmitData);
    cout << "Received Data: " << receivedData << endl;

    // Count number of 1s in received data
    int recvCount = countOnes(receivedData);

    // Check parity at receiver side
    // If total number of 1s is still even → No error detected
    // If total number of 1s is odd → Error detected
    if (recvCount % 2 == 0)
        cout << "No error detected " << endl;
    else
        cout << "Error detected " << endl;

    return 0;
}
