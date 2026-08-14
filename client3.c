#include <stdio.h> 

#include <winsock2.h> 

 

#pragma comment(lib,"ws2_32.lib") 

 

#define PORT 8080 

 

int main() 

{ 

    WSADATA wsa; 

    SOCKET clientSocket; 

 

    struct sockaddr_in server; 

 

    char buffer[1024]; 

 

    WSAStartup(MAKEWORD(2,2), &wsa); 

 

    clientSocket = socket(AF_INET, SOCK_STREAM, 0); 

 

    server.sin_family = AF_INET; 

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    server.sin_port = htons(PORT); 

 

    connect(clientSocket, (struct sockaddr*)&server, sizeof(server)); 

 

    printf("Connected to server.\n"); 

 

    while (1) 

    { 

        printf("Client : "); 

        fgets(buffer, sizeof(buffer), stdin); 

        buffer[strcspn(buffer, "\n")] = '\0'; 

 

        send(clientSocket, buffer, strlen(buffer), 0); 

 

        if (strcmp(buffer, "exit") == 0) 

            break; 

 

        int bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0); 

 

        if (bytes <= 0) 

            break; 

 

        buffer[bytes] = '\0'; 

 

        printf("Server : %s\n", buffer); 

 

        if (strcmp(buffer, "exit") == 0) 

            break; 

    } 

 

    closesocket(clientSocket); 

 

    WSACleanup(); 

 

    return 0; 

} 

 

 

 

 

 

 
