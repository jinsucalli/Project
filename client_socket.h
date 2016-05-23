#ifndef __TAEHO_CLIENT_SOCKET_H__
#define __TAEHO_CLIENT_SOCKET_H__

/**
  *@author Kim TaeHo
  *@brief Client Class for Server-Client Socket Programming.
		In Server-Client Socket Programming, Client Process is made up of
		5 processes. Create, Connect, Send(Write), Receive(Read), Close.
*/
class ClientSocket
{
	private:
		//! Parameters for Socket Programming
		struct sockaddr_in aServerAddr;
		int aClientSocket;
		//! Port Number for sokcet. user can revise Port num
		int aServerPort;
		//! ServerIP for Socket. user can revise IP through SetServerIP();
		string aServerIP;
		//! In Send process, Client send message in aSendbuf.
		string aSendBuf;
		//! After ReceiveBuf, Recieved message saved in aReceiveBuf.
		string aReceiveBuf;
		
	public:
		ClientSocket();
		~ClientSocket();
		bool Create();
		bool Connect();
		bool Send();
		bool Receive();
		bool Close();
		/** 
		  *@breif For sending message which user wants, user use
		  		SetSendBuf() funtion for setting SendBuf, then Send().
		*/
		void SetSendBuf(const char* Message);
		void SetSendBuf(string Message);
		//! User can get received message use GetReceiveBuf().
		string GetReceiveBuf();
		void SetServerIP(const char* IP);
		void SetServerPort(int Port);
		string GetServerIP();
		int GetServerPort();
};
#endif
