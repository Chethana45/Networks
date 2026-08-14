#include <stdio.h> 

#include <winsock2.h> 

 

#pragma comment(lib,"ws2_32.lib") 

 

#define PORT 8080 

#define BUFFER_SIZE 1024 

 

int main() 

{ 

    WSADATA wsa; 

    SOCKET serverSocket; 

    struct sockaddr_in serverAddr, clientAddr; 

    int clientLen = sizeof(clientAddr); 

    char buffer[BUFFER_SIZE]; 

 

    WSAStartup(MAKEWORD(2,2), &wsa); 

 

    serverSocket = socket(AF_INET, SOCK_DGRAM, 0); 

 

    serverAddr.sin_family = AF_INET; 

    serverAddr.sin_addr.s_addr = INADDR_ANY; 

    serverAddr.sin_port = htons(PORT); 

 

    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)); 

 

    printf("UDP Server is running on port %d...\n", PORT); 

 

    while(1) 

    { 

        int bytesReceived = recvfrom(serverSocket, buffer, BUFFER_SIZE, 0, 

                                     (struct sockaddr *)&clientAddr, &clientLen); 

 

        buffer[bytesReceived] = '\0'; 

 

        printf("\nClient: %s", buffer); 

 

        sendto(serverSocket, buffer, strlen(buffer), 0, 

               (struct sockaddr *)&clientAddr, clientLen); 

    } 

 

    closesocket(serverSocket); 

    WSACleanup(); 

 

    return 0; 

} 

 
