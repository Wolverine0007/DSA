#include <iostream>
using namespace std;

// Function to calculate number of parity bits (no cmath)
int calculateParityBits(int m) {
    int r = 0;
    while ((1 << r) < (m + r + 1)) {  // (2^r)
        r++;
    }
    return r;
}
int main() {
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;

    int data[50];
    cout << "Enter data bits: ";
    for (int i = 0; i < m; i++) {
        cin >> data[i];
    }
    int r = calculateParityBits(m);
    int n = m + r;

    int code[100];  // sender's code
    int recv[100];  // receiver's input

    // Initialize sender code
    for (int i = 1; i <= n; i++) code[i] = 0;

    // Step 1: Place data bits in non-parity positions
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            code[i] = 0; // parity bit placeholder
        } else {
            code[i] = data[j++];
        }
    }
    // Step 2: Calculate parity bits (even parity)
    for (int p = 0; p < r; p++) {
        int pos = (1 << p);
        int parity = 0;

        for (int i = 1; i <= n; i++) {
            if (i & pos) {
                parity ^= code[i];
            }
        }
        code[pos] = parity;
    }
    // Display generated Hamming code
    cout << "\nGenerated Hamming Code (Sender): ";
    for (int i = 1; i <= n; i++) cout << code[i];
    cout << endl;

    // ---------- NEW PART: RECEIVER INPUT ----------
    cout << "\nEnter received Hamming code bits (" << n << " bits): ";
    for (int i = 1; i <= n; i++) {
        cin >> recv[i];
    }
    // ------------------------------------------------
    // Step 3: Receiver side error checking using recv[]
    int c = 0;
    for (int p = 0; p < r; p++) {
        int pos = (1 << p);
        int parity = 0;

        for (int i = 1; i <= n; i++) {
            if (i & pos) {
                parity ^= recv[i];
            }
        }
        if (parity != 0) {
            c += pos;
        }
    }

    if (c == 0) {
        cout << "No error detected in received code.\n";
    } else {
        cout << "Error detected at position: " << c << endl;
        recv[c] ^= 1;  // correct error
        cout << "Corrected Hamming Code: ";
        for (int i = 1; i <= n; i++) cout << recv[i];
        cout << endl;
    }
    // Step 4: Extract original data bits from corrected recv[]
    cout << "Extracted Data bits: ";
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) { // non-parity
            cout << recv[i] << " ";
        }
    }
    cout << endl;
    return 0;
}