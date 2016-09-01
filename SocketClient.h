#ifndef _SOCKET_CLIENT_H_
#define _SOCKET_CLIENT_H_
#pragma comment(lib, "WS2_32.lib")

/**
 * SocketClient | Socket ˫��������
 * ʹ�������������̷ֱ߳������Ϣ���Ͷ��кͲ��շ�������Ϣ���Ա�
 * ͬʱ������Ϣ���ͺͽ��ա�
 *
 * ʹ��˵����
 *
 * 0�������ͷ�ļ���
 *
 * 1������Ϣ����������һ������Ϊ(char*)������ֵΪvoid��
 *    ��Ϣ��������ֵ�� SC_onReceive ����ָ�룬������Ϣ����
 *    ������ʵ���յ���Ϣ�Ĵ��������
 *
 * 2�����������ӣ�ִ�� SC_beginThreads() �����Խ��������ӣ�
 * 
 * 3����Ҫʱ������Ϣ����Ҫ������Ϣʱ������ SC_sendMessage
 *    (char*)�����������������Ϣ��
 **/

#include <queue>
using namespace std;

extern queue<char*> messageQueue;

// ��Ϣ��󳤶�����
#define BUFFER_LEN 1024

// ��������ַ�Ͷ˿�����
#define SERVER_IP "139.129.4.219"
#define SERVER_PORT 8082

extern SOCKET sockClient;
extern bool looping;

extern DWORD WINAPI receiverThread (LPVOID lpParameter);
extern DWORD WINAPI senderThread (LPVOID lpParameter);

extern void (*SC_onReceive)(char*);//ÿ���Ի���ʼʱ���躯��������ǰ����NULL
extern void SC_beginThreads ();
extern void SC_endThreads ();
extern void SC_sendMessage (char* message);

#endif