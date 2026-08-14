#include <stdio.h> 

#include <string.h> 

#include <winsock2.h> 

 

#pragma comment(lib,"ws2_32.lib") 

 

#define PORT 8080 

#define BUFFER_SIZE 1024 

 

int main() 

{ 

    WSADATA wsa; 

    SOCKET clientSocket; 

    struct sockaddr_in serverAddr; 

    char buffer[BUFFER_SIZE]; 

 

    WSAStartup(MAKEWORD(2,2), &wsa); 

 

    clientSocket = socket(AF_INET, SOCK_DGRAM, 0); 

 

    serverAddr.sin_family = AF_INET; 

    serverAddr.sin_port = htons(PORT); 

    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 

 

    printf("Enter message: "); 

    fgets(buffer, BUFFER_SIZE, stdin); 

 

    sendto(clientSocket, buffer, strlen(buffer), 0, 

           (struct sockaddr *)&serverAddr, sizeof(serverAddr)); 

 

    int serverLen = sizeof(serverAddr); 

 

    int bytesReceived = recvfrom(clientSocket, buffer, BUFFER_SIZE, 0, 

                                 (struct sockaddr *)&serverAddr, &serverLen); 

 

    buffer[bytesReceived] = '\0'; 

 

    printf("Server: %s", buffer); 

 

    closesocket(clientSocket); 

    WSACleanup(); 

 

    return 0; 

} 
