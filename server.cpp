#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <WinSock2.h>
#include <string>

int main() {
    std::cout << "Attempting to create a server\n";

    SOCKET wsocket;
    SOCKET new_wsocket;
    WSADATA wsaData;
    struct sockaddr_in server;
    int server_len;
    const int BUFFER_SIZE = 30720;
    const std::string username = "admin";
    const std::string password = "password";

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "Couldn't initialize.\n";
        return -1;
    }

    wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (wsocket == INVALID_SOCKET) {
        std::cout << "Couldn't create a socket.\n";
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);
    server_len = sizeof(server);

    if (bind(wsocket, (SOCKADDR*)&server, server_len) != 0) {
        std::cout << "Unable to bind the socket.\n";
        return -1;
    }

    if (listen(wsocket, 20) != 0) {
        std::cout << "Couldn't start listening.\n";
        return -1;
    }

    std::cout << "Listening on 127.0.0.1:8080\n";

    while (true) {
        new_wsocket = accept(wsocket, (SOCKADDR*)&server, &server_len);
        if (new_wsocket == INVALID_SOCKET) {
            std::cout << "Couldn't accept connection.\n";
            continue;
        }

        char buff[BUFFER_SIZE] = { 0 };
        int bytes = recv(new_wsocket, buff, BUFFER_SIZE, 0);
        if (bytes <= 0) {
            std::cout << "Couldn't read client request.\n";
            closesocket(new_wsocket);
            continue;
        }

        std::string request(buff);
        std::string response;

        // Simple login form HTML
        if (request.find("GET / ") != std::string::npos) {
            response = "<html><body><h1>Login Portal</h1>"
                "<form method='POST' action='/login'>"
                "Username: <input type='text' name='username'><br>"
                "Password: <input type='password' name='password'><br>"
                "<input type='submit' value='Login'>"
                "</form></body></html>";
        }
        // Handle POST request to /login
        else if (request.find("POST /login") != std::string::npos) {
            // Parse credentials from the request body
            std::size_t user_pos = request.find("username=");
            std::size_t pass_pos = request.find("password=");

            if (user_pos != std::string::npos && pass_pos != std::string::npos) {
                std::string entered_username = request.substr(user_pos + 9, pass_pos - user_pos - 10);
                std::string entered_password = request.substr(pass_pos + 9, request.find(" ", pass_pos) - pass_pos - 9);

                // Check credentials
                if (entered_username == username && entered_password == password) {
                    response = "<html><body><h1>Login Successful!</h1></body></html>";
                }
                else {
                    response = "<html><body><h1>Invalid Credentials. Try Again.</h1></body></html>";
                }
            }
        }
        else {
            response = "<html><body><h1>404 Not Found</h1></body></html>";
        }

        // Prepare HTTP response
        std::string serverMessage = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
        serverMessage.append(std::to_string(response.size())).append("\n\n").append(response);

        // Send the response
        int bytesSent = send(new_wsocket, serverMessage.c_str(), serverMessage.size(), 0);
        if (bytesSent < 0) {
            std::cout << "Couldn't send response.\n";
        }
        else {
            std::cout << "Sent response to client.\n";
        }

        closesocket(new_wsocket);
    }

    closesocket(wsocket);
    WSACleanup();
    return 0;
}
