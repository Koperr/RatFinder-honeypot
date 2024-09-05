#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
// nmap -p 1-65535 192.168.0.97

int main()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0){
        std::cerr << "Error opening socket\n";
        return 1;
    }


    sockaddr_in serverAddr;
    std::memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);


    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        std::cerr << "Error on binding\n";
        close(serverSocket);
        return 1;
    }
    listen(serverSocket, 5);
    std::cout << "Server listening on port 8080...\n";
    sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientLen);
    while(true)
    {
        if (clientSocket < 0) {
            std::cout << "1\n";
            std::cerr << "Error on accept\n";
            close(serverSocket);
            return 1;
        }

        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIP, INET_ADDRSTRLEN);
        std::cout << "Client connected! IP: " << clientIP;

        //std::string command = "curl http://ip-api.com/json/" + (std::string)clientIP;
        //std::cout << (system(command.c_str()));
        //std::cout << "gdfgdfgf\n";
    }

    // Zamknięcie socketów
    //close(clientSocket);
    close(clientSocket);
    close(serverSocket);
}