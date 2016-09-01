#pragma comment(lib, "WS2_32.lib")
#include <queue>
#include <windows.h>
using namespace std;

#include "SocketClient.h"

queue<char*> messageQueue;
  
SOCKET sockClient;
bool looping = false;
  
DWORD WINAPI receiverThread (LPVOID lpParameter);
DWORD WINAPI senderThread (LPVOID lpParameter);

void (*SC_onReceive)(char*) = NULL;

void SC_beginThreads () {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD (1, 1);

	err = WSAStartup (wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}

	if (LOBYTE (wsaData.wVersion) != 1 ||
		HIBYTE (wsaData.wVersion) != 1) {
		WSACleanup ();
		return;
	}
	sockClient = socket (AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr (SERVER_IP);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons (SERVER_PORT);
	connect (sockClient, (SOCKADDR*)&addrSrv, sizeof (SOCKADDR));

	HANDLE sendThread = CreateThread (NULL, 0, senderThread, NULL, 0, NULL);
	CloseHandle (sendThread);

	HANDLE recvThread = CreateThread (NULL, 0, receiverThread, NULL, 0, NULL);
	CloseHandle (recvThread);
}

void SC_endThreads () {
	closesocket (sockClient);
	WSACleanup ();
}

void SC_sendMessage (char* message) {
	messageQueue.push (message);
}

DWORD WINAPI receiverThread (LPVOID lpParameter) {
	while (1) {
		char content[BUFFER_LEN];
		*content = 0;
		recv (sockClient, content, BUFFER_LEN, 0);
		if (*content && SC_onReceive) {
			(*SC_onReceive) (content);
		}
	}
}

DWORD WINAPI senderThread (LPVOID lpParameter) {
	while (1) {
		if (messageQueue.size () > 0) {
			send (sockClient, messageQueue.front (), strlen (messageQueue.front ()), 0);
			send (sockClient, "\n", 1, 0);
			messageQueue.pop ();
		}
	}
}