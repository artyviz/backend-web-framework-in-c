#include "webdev.h"
#include "birchutils.h"
#include <WinSock2.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handle_client(SOCKET client_socket) {
	char buffer[BUFFER_SIZE];
	int bytes_received;

	
	bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
	if (bytes_received > 0) {
		
		buffer[bytes_received] = '\0';


		printf("Received: %s\n", buffer);

		
		send(client_socket, "Message received", 17, 0);
	}
	else {
		printf("Error receiving data\n");
	}

	closesocket(client_socket);
}

void usage() {
	printf("Usage: program <port> [host]\n");
}

void fail(int code) {
	exit(code);
}

int32 setupserver(int8* host, int16 port)
{
	struct sockaddr_in sock;
	int32 s;

	s = $2 socket(AF_INET, SOCK_STREAM, 0);
	assert(s > 0);
}


int32 setupserver(const char* host, int16 port)
{
	WSADATA wsaData;
	struct sockaddr_in sock;
	int16 n;
	int32 s;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		fprintf(stderr, "WSAStartup failed.\n");
		return -1;
	}

	s = socket(AF_INET, SOCK_STREAM, 0);
	assert(s != INVALID_SOCKET);

	sock.sin_family = AF_INET;
	sock.sin_port = htons($i port);
	sock.sin_addr.s_addr = inet_addr($c host);

	n = $6 bind(s, (struct sockaddr*)&sock, sizeof(sock));
	assert(!n);
	
	n = listen(s, 50);
	assert(n == 0);

	return s;
}


int main(int argc, char* argv[]) {
	const char* host;
	int16 port;

	if (argc < 2) {
		usage();
		fail(1);
	}
	else if (argc == 2) {
		port = atoi(argv[1]);
		host = "0.0.0.0";
	}
	else {
		port = atoi(argv[1]);
		host = argv[2];
	}

	printf("SERVER STARTING\n");

	int32 server_socket = setupserver(host, port);
	if (server_socket == -1) {
		fprintf(stderr, "Failed to set up server.\n");
		return 1;
	}


	closesocket(server_socket);
	WSACleanup();

	return 0;
}
