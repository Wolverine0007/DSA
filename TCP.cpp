//-lws2_32-lws2_32
client
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;

int main() {
    WSADATA wsa;
    SOCKET sock;
    sockaddr_in server;
    char buffer[1024];

    WSAStartup(MAKEWORD(2,2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");  // Localhost

    if (connect(sock, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cout << "? Connection failed.\n";
        return 1;
    }

    cout << "? Connected to server.\n";

    while (true) {
        string msg;
        cout << "Enter message: ";
        getline(cin, msg);
        send(sock, msg.c_str(), msg.size(), 0);

        if (msg == "exit") break;

        int recvSize = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (recvSize <= 0) break;

        buffer[recvSize] = '\0';
        cout << "Server: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}



server
#include <iostream>
#include <winsock2.h>
#include <windows.h>
using namespace std;

DWORD WINAPI handleClient(LPVOID clientSocket) {
    SOCKET sock = (SOCKET)clientSocket;
    char buffer[1024];
    int recvSize;

    while ((recvSize = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[recvSize] = '\0';
        cout << "Client: " << buffer << endl;
        send(sock, buffer, recvSize, 0);  // Echo back message

        if (strcmp(buffer, "exit") == 0) {
            cout << "Client disconnected.\n";
            break;
        }
    }

    closesocket(sock);
    return 0;
}

int main() {
    WSADATA wsa;
    SOCKET serverSock, clientSock;
    sockaddr_in serverAddr, clientAddr;
    int c;

    WSAStartup(MAKEWORD(2,2), &wsa);
    serverSock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);

    bind(serverSock, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSock, 5);

    cout << "?? Multi-client TCP Server started on port 8888...\n";

    c = sizeof(sockaddr_in);
    while (true) {
        clientSock = accept(serverSock, (sockaddr*)&clientAddr, &c);
        if (clientSock == INVALID_SOCKET) continue;

        cout << "? New client connected.\n";
        CreateThread(NULL, 0, handleClient, (LPVOID)&clientSock, 0, NULL);
    }

    closesocket(serverSock);
    WSACleanup();
    return 0;
}
