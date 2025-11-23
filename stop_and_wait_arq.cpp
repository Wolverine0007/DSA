#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <unistd.h>  // for sleep() function
using namespace std;

int main() {

    int tf;  // total number of frames to send
    cout << "Enter the total frames: ";
    cin >> tf;

    int frame = 1;  // start sending from frame number 1

    // Loop until all frames are successfully sent and acknowledged
    while (frame <= tf) {
        cout << "\nSending the frame " << frame << endl;

        // ---------------------------
        // Simulate random frame loss
        // ---------------------------
        // rand() % 10 generates a random number between 0 and 9.
        // If the number is < 2 (i.e., 0 or 1), we assume the frame is lost.
        // This gives about a 20% chance of frame loss.
        bool framelost = (rand() % 10 < 2);

        if (framelost) {
            cout << "❌ Frame " << frame << " is lost." << endl;
            cout << "🔁 Resending the frame " << frame << endl;            
            continue;
        }
        // If the frame is not lost, we assume it reached the receiver.
        cout << "✅ Frame " << frame << " is received successfully." << endl;

        // -----------------------------
        // Simulate random ACK loss
        // -----------------------------
        // Same logic: 20% chance the acknowledgment is lost.
        bool acklost = (rand() % 10 < 2);

        if (acklost) {
            cout << "⚠️  Acknowledgement for frame " << frame << " is lost." << endl;
            cout << "🔁 Resending the frame " << frame << endl;

            // Again, no increment — resend same frame next time.
            continue;
        }
        // If ACK is received, the sender moves on to the next frame.
        cout << "📩 Acknowledgement for frame " << frame << " is received." << endl;

        // Increment frame number to send the next one.
        frame++;

        // sleep(1) pauses for 1 second to simulate transmission delay.
        sleep(1);
    }

    // When all frames are sent and acknowledged
    cout << "\n✅ All frames are received correctly.\n";

    return 0;
}
