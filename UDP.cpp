//-lws2_32-lws2_32
server
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET serverSock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverAddr{}, clientAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    bind(serverSock, (sockaddr*)&serverAddr, sizeof(serverAddr));

    cout << "UDP Server running...\n";

    int clientLen = sizeof(clientAddr);
    char buffer[1024];

    while (true) {
        int len = recvfrom(serverSock, buffer, 1024, 0,
                           (sockaddr*)&clientAddr, &clientLen);

        buffer[len] = '\0';
        cout << "Client: " << buffer << endl;

        sendto(serverSock, buffer, len, 0,
               (sockaddr*)&clientAddr, clientLen);
    }

    closesocket(serverSock);
    WSACleanup();
    return 0;
}

// udp_client_loop.cpp
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        cerr << "WSAStartup failed\n";
        return 1;
    }

    SOCKET clientSock = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSock == INVALID_SOCKET) {
        cerr << "socket() failed: " << WSAGetLastError() << endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);

    int serverLen = sizeof(serverAddr);
    char recvBuf[1024];

    cout << "Type messages to send to server. Type 'exit' to quit.\n";

    while (true) {
        string msg;
        cout << "Enter message: ";
        getline(cin, msg);

        if (msg.empty()) continue;

        int sent = sendto(clientSock, msg.c_str(), (int)msg.size(), 0,
                          (sockaddr*)&serverAddr, serverLen);
        if (sent == SOCKET_ERROR) {
            cerr << "sendto() failed: " << WSAGetLastError() << endl;
            break;
        }

        if (msg == "exit") {
            cout << "Exiting client.\n";
            break;
        }

        int recvLen = recvfrom(clientSock, recvBuf, sizeof(recvBuf)-1, 0,
                               (sockaddr*)&serverAddr, &serverLen);
        if (recvLen == SOCKET_ERROR) {
            cerr << "recvfrom() failed: " << WSAGetLastError() << endl;
            break;
        }
        recvBuf[recvLen] = '\0';
        cout << "Server: " << recvBuf << endl;
    }

    closesocket(clientSock);
    WSACleanup();
    return 0;
}
