
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <conio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{

	int iResult;
	WSADATA wsaData;

	SOCKET SenderSocket = INVALID_SOCKET;
	sockaddr_in ReceiverAddress;

	unsigned short Port = 27015;

	char SendBuf[1024];
	int BufLen = 1024;

	//----------------------
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR) {
		wprintf(L"WSAStartup failed with error: %d\n", iResult);
		return 1;

		
	}

	//---------------------------------------------
	// Create a socket for sending data
	SenderSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (SenderSocket == INVALID_SOCKET) {
		wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	//---------------------------------------------
	// Set up the ReceiverAddress structure with the IP address of
	// the receiver (in this example case "192.168.1.1")
	// and the specified port number.
	ReceiverAddress.sin_family = AF_INET;
	ReceiverAddress.sin_port = htons(Port);
	ReceiverAddress.sin_addr.s_addr = inet_addr("192.168.1.1");

	//---------------------------------------------
	// Send a datagram to the receiver
	wprintf(L"Sending a datagram to the receiver...\n");
	iResult = sendto(SenderSocket,
		SendBuf, BufLen, 0, (SOCKADDR *)& ReceiverAddress, sizeof(ReceiverAddress));
	if (iResult == SOCKET_ERROR) {
		wprintf(L"sendto failed with error: %d\n", WSAGetLastError());
		closesocket(SenderSocket);
		WSACleanup();
		return 1;
	}
	//---------------------------------------------
	// When the application is finished sending, close the socket.
	wprintf(L"Finished sending. Closing socket.\n");
	iResult = closesocket(SenderSocket);
	if (iResult == SOCKET_ERROR) {
		wprintf(L"closesocket failed with error: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	//---------------------------------------------
	// Clean up and quit.
	wprintf(L"Exiting.\n");
	WSACleanup();

	getch();
	return 0;
}

