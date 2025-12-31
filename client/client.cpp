#include <iostream>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <thread>
#include <string>

using namespace std;

#pragma comment(lib, "ws2_32.lib")

/*
	initialize the WinSock library

	create a socket
	connect to the server
	send/receive 
	close the socket
*/

bool Initialization() {

	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void SendMsg(SOCKET s) {
	cout << "Enter your chat name: " << endl;
	string name;
	getline(cin, name);
	string message;

	while (1) {
		getline(cin, message);
		string msg = name + " : " + message;
		int bytesend = send(s, msg.c_str(), msg.length(), 0);
		if (bytesend == SOCKET_ERROR) {
			cout << "Error sending message" << endl;
			break;
		}

		if (message == "quit") {
			cout << "Stopping Application" << endl;
			break;
		}
	}
	closesocket(s);
	WSACleanup();
}

void ReceiveMsg(SOCKET s) {
	char buffer[4096];
	int recvlength;
	string msg = "";
	while (1) {
		recvlength = recv(s, buffer, sizeof(buffer), 0);
		if (recvlength <= 0) {
			cout << "disconneted from the server" << endl;
			break;
		}
		else {
			msg = string(buffer, recvlength);
			cout << msg << endl;
		}
	}
}

int main() {

	if(!Initialization()) {
		cout << "initialize winsock failed " << endl;
		return 1;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET) {
		cout << "invalid socket created " << endl;
		return 1;
	}

	int port = 12345;
	string serveraddress = "127.0.0.1";
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	inet_pton(AF_INET, serveraddress.c_str(), &(serveraddr.sin_addr));

	if(connect(s, reinterpret_cast<sockaddr*>(&serveraddr), sizeof(serveraddr)) == SOCKET_ERROR) {
		cout << "not able to connect to server " << endl;
		cout << ": " << WSAGetLastError();
		closesocket(s);
		WSACleanup();
		return 1;
	}

	cout << "successfully connect to server" << endl;

	thread senderThread(SendMsg, s);
	thread receiver(ReceiveMsg, s);

	senderThread.join();
	receiver.join();

	return 0;
}