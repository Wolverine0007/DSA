#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>  // for sleep()

using namespace std;

int main() {
    srand(time(0)); // Seed random number generator

    int totalFrames, windowSize;

    cout << "Enter total number of frames to send: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    bool ack[100] = {false}; // To track which frames are acknowledged
    int sent = 0;            // Count of frames sent

    cout << "\n--- Selective Repeat ARQ Simulation ---\n";

    while (sent < totalFrames) {
        cout << "\n--- Sending Window ---" << endl;

        // Send frames within the window
        for (int i = sent; i < sent + windowSize && i < totalFrames; i++) {
            if (!ack[i]) { // Only send unacknowledged frames
                cout << "Sender: Sending Frame " << i + 1 << endl;
                sleep(1);
            }
        }
        cout << "\n--- Receiver Side ---" << endl;

        // Simulate receiving and random frame loss
        for (int i = sent; i < sent + windowSize && i < totalFrames; i++) {
            if (!ack[i]) {
                bool frameLost = (rand() % 10 < 2); // 20% chance of loss

                if (frameLost) {
                    cout << "Receiver: ❌ Frame " << i + 1 << " lost!" << endl;
                 } else {
                    cout << "Receiver: ✅ Frame " << i + 1 << " received, sending ACK." << endl;
                    ack[i] = true;
                }
                sleep(1);
            }
        }

        cout << "\n--- ACK Processing at Sender ---" << endl;
        // Simulate random ACK loss (20% chance)
        for (int i = sent; i < sent + windowSize && i < totalFrames; i++) {
            if (ack[i]) {
                bool ackLost = (rand() % 10 < 2);
                if (ackLost) {
                    cout << "Sender: ⚠️ ACK for Frame " << i + 1 << " lost!" << endl;
                    ack[i] = false; // Will resend this frame next round
                } else {
                    cout << "Sender: ✅ ACK for Frame " << i + 1 << " received." << endl;
                }
            }
            sleep(1);
        }

        // Slide window forward — skip already acknowledged frames
        while (sent < totalFrames && ack[sent]) {
            sent++;
        }
    }
    cout << "\n✅ All frames have been successfully sent and acknowledged.\n";
    return 0;
}
