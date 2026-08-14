#include <stdio.h> 

#include <stdlib.h> 

#include <string.h> 

#include <winsock2.h> 

#include <ws2tcpip.h> 

 

#define PORT 8080 

 

int main() 

{ 

    WSADATA wsa; 

    SOCKET server_fd, new_socket; 

    struct sockaddr_in address; 

    int addrlen = sizeof(address); 

    char buffer[1024]; 

 

    // Initialize Winsock 

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 

    { 

        printf("WSAStartup failed!\n"); 

        return 1; 

    } 

 

    // Create socket 

    server_fd = socket(AF_INET, SOCK_STREAM, 0); 

 

    if (server_fd == INVALID_SOCKET) 

    { 

        printf("Socket creation failed!\n"); 

        WSACleanup(); 

        return 1; 

    } 

 

    // Configure server 

    address.sin_family = AF_INET; 

    address.sin_addr.s_addr = INADDR_ANY; 

    address.sin_port = htons(PORT); 

 

    // Bind socket 

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) 

    { 

        printf("Bind failed!\n"); 

        closesocket(server_fd); 

        WSACleanup(); 

        return 1; 

    } 

 

    // Listen for connections 

    if (listen(server_fd, 3) == SOCKET_ERROR) 

    { 

        printf("Listen failed!\n"); 

        closesocket(server_fd); 

        WSACleanup(); 

        return 1; 

    } 

 

    printf("Server listening on port %d...\n", PORT); 

 

    // Accept client 

    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen); 

 

    if (new_socket == INVALID_SOCKET) 

    { 

        printf("Accept failed!\n"); 

        closesocket(server_fd); 

        WSACleanup(); 

        return 1; 

    } 

 

    printf("Client connected!\n"); 

 

    // Receive message 

    int bytes = recv(new_socket, buffer, sizeof(buffer) - 1, 0); 

 

    if (bytes > 0) 

    { 

        buffer[bytes] = '\0'; 

        printf("Client: %s", buffer); 

 

        // Echo back to client 

        send(new_socket, buffer, strlen(buffer), 0); 

    } 

 

    // Close sockets 

    closesocket(new_socket); 

    closesocket(server_fd); 

    WSACleanup(); 

 

    return 0; 

} 
