#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <unistd.h> // for sleep()

using namespace std;

int main() {
    srand(time(0));  // Seed random number generator

    int totalFrames, windowSize;
    cout << "Enter total number of frames to send: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;

    int sendFrame = 1;     // Next frame number to send
    int expectedAck = 1;   // The next ACK we are waiting for

     // Continue until all frames are acknowledged
     while (expectedAck <= totalFrames) {                

        // 1️⃣ Sender sends frames (window size)
        cout << "\n--- Sending Window ---" << endl;
        for (int i = sendFrame; i < expectedAck + windowSize && i <= totalFrames; i++) {  //The window slides forward as ACKs arrive
            cout << "Sender: Sending Frame " << i << endl;
        }

        // After sending, assume we’ve sent frames up to (expectedAck + windowSize - 1)
           sendFrame = expectedAck + windowSize;
      
        // 2️⃣ Receiver side simulation
        for (int i = expectedAck; i < sendFrame && i <= totalFrames; i++) {

            // Randomly decide if frame is lost (20% chance)
            bool frameLost = (rand() % 10 < 2);

            if (frameLost) {
                cout << "⚠️  Frame " << i << " lost!" << endl;
                cout << "⏳ Timeout... Resending from Frame " << i << endl;

                // Go-Back-N: resend from the lost frame
                sendFrame = i;
                break;
            } 
            else {
                cout << "✅ Receiver: Frame " << i << " received successfully." << endl;

                // ---- NEW: simulate ACK loss (20% chance) ----
                bool ackLost = (rand() % 10 < 2);
                if (ackLost) {
                    cout << "❌ ACK " << i << " lost on the way back to sender!" << endl;
                    cout << "⏳ Sender will timeout... Resending from Frame " << i << endl;
                    // Sender never receives ACK -> go back and resend from this frame
                    sendFrame = i;
                    break;
                }
                // ---- end NEW ----

                cout << "📩 Receiver: Sending ACK " << i << endl;

                // Move window forward
                expectedAck = i + 1;
            }

            sleep(1); // Pause for readability
        }
    }

      cout << "\n✅ All frames sent and acknowledged successfully using Go-Back-N ARQ.\n";
      return 0;
    }
