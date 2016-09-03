#include "stdafx.h"
#include "SocketContext.h"
#include "SocketClient.h"


SocketContext::SocketContext () {
	SC_registerContext (this);
}

SocketContext::~SocketContext () {
	SC_unregisterContext (this);
}
