#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Compute CRC remainder
string computeCRC(const string &data, const string &divisor) {
    int n = data.size();
    int m = divisor.size();
    string buf = data + string(m - 1, '0'); // append zeros

    for (int i = 0; i < n; ++i) {
        if (buf[i] == '1') {
            for (int j = 0; j < m; ++j)
                buf[i + j] = (buf[i + j] == divisor[j]) ? '0' : '1';
        }
    }
    return buf.substr(n, m - 1); // remainder
}
int main() {
    srand(time(0));
    string data, divisor;
    cout << "Enter data bits: ";
    cin >> data;
    cout << "Enter divisor (generator polynomial): ";
    cin >> divisor;

    if (divisor.size() < 2) {
        cerr << "Divisor must have at least 2 bits.\n";
        return 1;
    }
    // compute remainder
    string remainder = computeCRC(data, divisor);
    cout << "Remainder: " << remainder << "\n";

    // transmitted frame
    string transmitted = data + remainder;
    cout << "Transmitted Frame: " << transmitted << "\n";

    // ask whether to flip a bit
    char choice;
    cout << "\nDo you want to inject an error? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int pos = rand() % transmitted.size(); // random bit position
        cout << "Flipping bit at position " << pos << "\n";

        // flip bit: 0->1, 1->0
        transmitted[pos] = (transmitted[pos] == '0') ? '1' : '0';

        cout << "Corrupted Frame: " << transmitted << "\n";
    }

    // check CRC on transmitted (possibly corrupted) frame
    string check = computeCRC(transmitted, divisor);
    if (check.find('1') == string::npos) //“Not found in the string”
        cout << "\nNo error detected at receiver side.\n";
    else
        cout << "\n❌ Error detected at receiver side!\n";

    return 0;
}
