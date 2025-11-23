#include <iostream>
#include <cstdint>
using namespace std;

char findClass(int firstOctet) {
    if (firstOctet >= 1 && firstOctet <= 126) return 'A';
    if (firstOctet >= 128 && firstOctet <= 191) return 'B';
    if (firstOctet >= 192 && firstOctet <= 223) return 'C';
    if (firstOctet >= 224 && firstOctet <= 239) return 'D';
    return 'E';
}

int getDefaultPrefix(char ipClass) {
    if (ipClass == 'A') return 8;
    if (ipClass == 'B') return 16;
    if (ipClass == 'C') return 24;
    return -1; // for D, E
}

void intToIp(unsigned int ip) {
    cout << ((ip >> 24) & 0xFF) << "."
         << ((ip >> 16) & 0xFF) << "."
         << ((ip >> 8) & 0xFF) << "."
         << (ip & 0xFF);
}
int main() {
    int ipArr[4];
    cout << "Enter IP address (e.g., 192.168.1.0): ";
    char dot;
    if (!(cin >> ipArr[0] >> dot >> ipArr[1] >> dot >> ipArr[2] >> dot >> ipArr[3])) return 0;

    char ipClass = findClass(ipArr[0]);
    cout << "\nIP Class: " << ipClass << endl;

    int prefix = getDefaultPrefix(ipClass);
    if (prefix == -1) {
        cout << "Subnetting not applicable for Class " << ipClass << " IPs.\n";
        return 0;
    }

    cout << "Default Prefix: /" << prefix << endl;

    unsigned int defaultMask = 0xFFFFFFFFu << (32 - prefix);
    cout << "Default Subnet Mask: ";
    intToIp(defaultMask);
    cout << endl;


    int numSubnets;
    cout << "\nEnter number of subnets to create: ";
    cin >> numSubnets;
    if (numSubnets <= 0) { cout << "Invalid number\n"; return 0; }

    // compute bitsNeeded using integer loop (smallest b with 2^b >= numSubnets)
    int bitsNeeded = 0;
    while ((1 << bitsNeeded) < numSubnets) ++bitsNeeded;

    int newPrefix = prefix + bitsNeeded;
    if (newPrefix > 30) {
        cout << "Too many subnets requested!\n";
        return 0;
    }

    // pack IP into 32-bit unsigned
    //stores a numeric integr number
    unsigned int ip = ( (unsigned int)ipArr[0] << 24 )
                    | ( (unsigned int)ipArr[1] << 16 )
                    | ( (unsigned int)ipArr[2] << 8 )
                    | (unsigned int)ipArr[3];

    unsigned int mask = 0xFFFFFFFFu << (32 - newPrefix);   
    unsigned int subnetSize = 1u << (32 - newPrefix);     // 2^(32-newPrefix)
    int totalSubnets = 1 << bitsNeeded;                  // 2^bitsNeeded

    cout << "\nNew Subnet Mask: ";
    intToIp(mask);
    cout << " (/" << newPrefix << ")\n";
    cout << "Total Subnets: " << totalSubnets << endl;
    cout << "Hosts per Subnet: " << (subnetSize > 2 ? subnetSize - 2 : 0) << endl;
    
    cout << "\n===== Subnet Details =====\n";
    for (int i = 0; i < totalSubnets; i++) {
        unsigned int subnet = (ip & mask) + ( (unsigned int)i * subnetSize );
        unsigned int broadcasst = subnet + subnetSize - 1;

        cout << "\nSubnet " << i + 1 << ":\n";
        cout << "  Network: ";
        intToIp(subnet);
        cout << "\n  Broadcast: ";
        intToIp(broadcast);
        cout << "\n  First Host: ";
        intToIp(subnet + 1);
        cout << "\n  Last Host: ";
        intToIp(broadcast - 1);
        cout << "\n";
    }
    return 0;
}
