#include <stdio.h> 

#include <winsock2.h> 

 

#pragma comment(lib,"ws2_32.lib") 

 

#define PORT 8080 

 

int main() 

{ 

    WSADATA wsa; 

    SOCKET serverSocket, clientSocket; 

    struct sockaddr_in server, client; 

    int c; 

 

    char buffer[1024]; 

 

    WSAStartup(MAKEWORD(2,2), &wsa); 

 

    serverSocket = socket(AF_INET, SOCK_STREAM, 0); 

 

    server.sin_family = AF_INET; 

    server.sin_addr.s_addr = INADDR_ANY; 

    server.sin_port = htons(PORT); 

 

    bind(serverSocket, (struct sockaddr*)&server, sizeof(server)); 

 

    listen(serverSocket, 1); 

 

    printf("Waiting for client...\n"); 

 

    c = sizeof(struct sockaddr_in); 

    clientSocket = accept(serverSocket, (struct sockaddr*)&client, &c); 

 

    printf("Client connected.\n"); 

 

    while (1) 

    { 

        int bytes = recv(clientSocket, buffer, sizeof(buffer) - 1, 0); 

 

        if (bytes <= 0) 

            break; 

 

        buffer[bytes] = '\0'; 

 

        printf("Client : %s\n", buffer); 

 

        if (strcmp(buffer, "exit") == 0) 

            break; 

 

        printf("Server : "); 

        fgets(buffer, sizeof(buffer), stdin); 

        buffer[strcspn(buffer, "\n")] = '\0'; 

 

        send(clientSocket, buffer, strlen(buffer), 0); 

 

        if (strcmp(buffer, "exit") == 0) 

            break; 

    } 

 

    closesocket(clientSocket); 

    closesocket(serverSocket); 

    WSACleanup(); 

 

    return 0; 

} 
