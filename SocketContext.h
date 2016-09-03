#pragma once
class SocketContext {
public:
	SocketContext ();
	virtual void handleMessage (char* message) = 0;
	~SocketContext ();
};

