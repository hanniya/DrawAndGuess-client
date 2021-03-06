#ifndef _SOCKET_CLIENT_H_
#define _SOCKET_CLIENT_H_
#pragma comment(lib, "WS2_32.lib")

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

#include <queue>
using namespace std;

#include "SocketContext.h"

extern queue<char*> messageQueue;
extern vector<SocketContext*> contexts;

// 消息最大长度设置
#define BUFFER_LEN 1024

// 服务器地址和端口设置
#define SERVER_IP "139.129.4.219"
#define SERVER_PORT 8082

extern SOCKET sockClient;
extern bool looping;

struct Callback {
	char* message;
	SocketContext* context;
};

extern queue<Callback> callbackQueue;

extern DWORD WINAPI receiverThread (LPVOID lpParameter);
extern DWORD WINAPI senderThread (LPVOID lpParameter);
extern DWORD WINAPI dynamicCallbackThread (LPVOID lpParameter);

extern void SC_registerContext (SocketContext*);
extern void SC_unregisterContext (SocketContext*);

extern void SC_beginThreads ();
extern void SC_endThreads ();
extern void SC_sendMessage (char* message);

#endif