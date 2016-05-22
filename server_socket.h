#ifndef __TAEHO_SERVER_SOCKET_H__
#define __TAEHO_SERVER_SOCKET_H__

#define __OPTION_ENABLE_ASSERT__	1
#define FALSE -1
#define SUCCESS 0

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;

#if __OPTION_ENABLE_ASSERT__
	#define ASSERT(X)				\
	{								\
		if(!(X)){					\
			cout<<"ASSERT : FILE "<<__FILE__<<", LINE "<<__LINE__<<endl;							   \
		while(1){}					\
		}							\
	}								
#else
	#define ASSERT(X) ((void)0)		\

#endif

class ServerSocket
{
	private:
		struct sockaddr_in aServerAddr;
		struct sockaddr_in aClientAddr;
		int aClientSocket;
		int aServerSocket;
		int aPort;
		string aServerIP;
		string aSendBuf;
		string aReceiveBuf;
		
	public:
		ServerSocket();
		~ServerSocket();
		bool Create();
		bool Bind();
		bool Listen();
		bool Accept();
		bool Send();
		bool Receive();
		bool Close();
		void SetSendBuf(const char* Message);
		void SetSendBuf(string Message);
		string GetReceiveBuf();
		void SetServerIP(const char* IP);
		void SetPort(int Port);
};
#endif
