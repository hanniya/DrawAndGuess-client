/**
 * SocketClient | Socket 双工长连接
 * 使用两个单独的线程分别监听消息发送队列和查收服务器消息，以便
 * 同时处理消息发送和接收。
 *
 * 使用说明：
 *
 * 0、引入此头文件；
 *
 * 1、绑定消息处理函数：将一个参数为(char*)、返回值为void的
 *    消息处理函数赋值给 SC_onReceive 函数指针，并在消息处理
 *    函数中实现收到消息的处理操作；
 *
 * 2、启动长连接：执行 SC_beginThreads() 函数以建立长连接；
 * 
 * 3、必要时发送消息：需要发送消息时，调用 SC_sendMessage
 *    (char*)函数向服务器发送消息。
 **/

#pragma comment(lib, "WS2_32.lib")
#include <windows.h>
#include <queue>
using namespace std;

queue<char*> messageQueue;

// 消息最大长度设置
#define BUFFER_LEN 1024

// 服务器地址和端口设置
#define SERVER_IP "139.129.4.219"
#define SERVER_PORT 8082

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