 

#include <stdio.h> 

#include <stdlib.h> 

#include <string.h> 

#include <winsock2.h> 

#include <ws2tcpip.h> 

 

#pragma comment(lib, "ws2_32.lib") 

 

#define PORT 8080 

 

int main() 

{ 

    WSADATA wsa; 

    SOCKET sock; 

    char buffer[1024]; 

    struct sockaddr_in server_address; 

 

    // Initialize Winsock 

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 

    { 

        printf("WSAStartup failed!\n"); 

        return 1; 

    } 

 

    // Create socket 

    sock = socket(AF_INET, SOCK_STREAM, 0); 

 

    if (sock == INVALID_SOCKET) 

    { 

        printf("Socket creation failed!\n"); 

        WSACleanup(); 

        return 1; 

    } 

 

    // Configure server address 

    server_address.sin_family = AF_INET; 

    server_address.sin_port = htons(PORT); 

    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); 

 

    // Connect to server 

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) 

    { 

        printf("Connection Failed!\n"); 

        closesocket(sock); 

        WSACleanup(); 

        return 1; 

    } 

 

    printf("Connected to server!\n"); 

 

    printf("Enter message: "); 

    fgets(buffer, sizeof(buffer), stdin); 

 

    // Send message 

    send(sock, buffer, strlen(buffer), 0); 

 

    // Receive echoed message 

    int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0); 

 

    if (bytes > 0) 

    { 

        buffer[bytes] = '\0'; 

        printf("Echo from Server: %s", buffer); 

    } 

 

    // Close socket 

    closesocket(sock); 

    WSACleanup(); 

 

    return 0; 

} 
