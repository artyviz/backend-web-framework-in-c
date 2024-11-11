# Web Backend Framework

This is a simple web backend framework that sets up a server, handles client connections, and supports network communication using sockets. The framework is designed to be lightweight and efficient for learning and development purposes.

## Features

- **Socket-based server setup**: Configures a server to accept client connections.
- **Network communication**: Handles data transmission between client and server using buffers.
- **Cross-platform**: Works on both Windows (using WinSock) and Linux (using POSIX sockets).
- **Simple Logging**: Logs server events and errors.
- **Modular design**: Easy to extend for more advanced features such as multi-threading and database integration.

## Prerequisites

Before you begin, make sure you have the following installed:

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

**Usage**
*To run the server:*
./webdev <port> [host]

<port>: The port number the server will listen on (e.g., 8080).
[host]: The optional host address (defaults to 0.0.0.0 if not provided). If you want to bind to a specific IP, pass it as a second argument.


**Example:**
Start the server on port 8080, binding to 127.0.0.1: ./webdev 8080 127.0.0.1

/web-backend-framework
│
├── /src
│   ├── webdev.c            # Main server application
│   ├── webdev.h            # Header file with function declarations
│   └── birchutils.h        # Utility functions
│
├── /Makefile               # Makefile for building the project
└── README.md               # Project documentation


License
This project is licensed under the MIT License - see the LICENSE file for details.

Contributing
Fork the repository.
Create a new branch (git checkout -b feature-name).
Make your changes.
Commit your changes (git commit -am 'Add new feature').
Push to the branch (git push origin feature-name).
Open a pull request.
Acknowledgments
This project is built using standard C and socket programming techniques.
Inspired by the need to understand low-level server implementation and networking in C.
For any additional questions or suggestions, feel free to create an issue or contact me directly!
