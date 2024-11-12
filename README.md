# Web Backend Framework

This is a simple web backend framework designed to set up a server, handle client connections, and support network communication using sockets. It's lightweight and efficient, primarily aimed at learning and development purposes.

## Features

- **Socket-based server setup**: Configures a server to accept and manage client connections.
- **Network communication**: Efficient data transmission between client and server using buffers.
- **Cross-platform compatibility**: Works on both Windows (using WinSock) and Linux (using POSIX sockets).
- **Simple Logging**: Logs server events and errors for debugging and monitoring purposes.
- **Modular design**: Easily extendable for additional features like multi-threading and database integration.

## Prerequisites

Ensure you have the following installed:

- **C Compiler**: GCC or MinGW on Windows.
- **Make**: For building the project.
- **WinSock (Windows only)**: The project uses `WinSock2.h` for socket programming on Windows. On Linux, it uses POSIX sockets.
  
### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/artyviz/backend-web-framework-in-c
   cd web-backend-framework
Install dependencies (if any). This project does not require any external dependencies.

Compile the project using make: make

Usage
To run the server, execute the following command:
./webdev <port> [host]

<port>: The port number the server will listen on (e.g., 8080).
[host]: Optional. The host address (defaults to 0.0.0.0 if not provided). If you want to bind to a specific IP address, pass it as a second argument.
Example:
To start the server on port 8080, binding to 127.0.0.1, use: ./webdev 8080 127.0.0.1

Project Structure
The project directory looks as follows:
/web-backend-framework
│
├── /src
│   ├── webdev.c            # Main server application
│   ├── webdev.h            # Header file with function declarations
│   └── birchutils.h        # Utility functions
│
├── /Makefile               # Makefile for building the project
└── README.md               # Project documentation
icense
This project is licensed under the MIT License - see the LICENSE file for details.

Contributing
If you'd like to contribute:

Fork the repository.
Create a new branch (git checkout -b feature-name).
Make your changes.
Commit your changes (git commit -am 'Add new feature').
Push to your branch (git push origin feature-name).
Open a pull request.
Acknowledgments
This project is built using standard C and socket programming techniques.
Inspired by the need to understand low-level server implementation and networking in C.
For additional questions or suggestions, feel free to create an issue or contact me directly!
