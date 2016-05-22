#ifndef __TAEHO_CLIENT_SOCKET_H__
#define __TAEHO_CLIENT_SOCKET_H__

class ClientSocket
{
	private:
		struct sockaddr_in aServerAddr;
		int aClientSocket;
		int aServerPort;
		string aServerIP;
		string aSendBuf;
		string aReceiveBuf;
		
	public:
		ClientSocket();
		~ClientSocket();
		bool Create();
		bool Connect();
		bool Send();
		bool Receive();
		bool Close();
		void SetSendBuf(const char* Message);
		void SetSendBuf(string Message);
		string GetReceiveBuf();
		void SetServerIP(const char* IP);
		void SetServerPort(int Port);
		string GetServerIP();
		int GetServerPort();
};
#endif
