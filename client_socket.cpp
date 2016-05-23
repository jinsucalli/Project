#include "client.h"
#include "client_socket.h"

ClientSocket::ClientSocket()
{
	aClientSocket = FALSE;
	aServerPort = 8000;
	aServerIP = "127.0.0.1";
}

ClientSocket::~ClientSocket()
{
}

/**
  *@brief Making socket. In this function, we use TCP protocol.
  *@return if making socket is success, return true.
*/
bool ClientSocket::Create()
{
	aClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(aClientSocket == FALSE){
		cout<<"Client Create Error!"<<endl;
		return false;
	}
	return true;
}

/**
  *@brief Setting structure sockaddr_in using saved ServerIP and
  		  Port number. And then Connect opend server.
  *@reurn if connect is success, return true.
*/
bool ClientSocket::Connect()
{
	ASSERT(aClientSocket != FALSE);

	int ConnectResult;

	memset(&aServerAddr,0,sizeof(aServerAddr));
	aServerAddr.sin_family = AF_INET;
	aServerAddr.sin_addr.s_addr = inet_addr(aServerIP.c_str());
	aServerAddr.sin_port = htons(aServerPort);
	
	ConnectResult = connect(aClientSocket,
					(struct sockaddr *)&aServerAddr,
					sizeof(aServerAddr));
	if(ConnectResult != SUCCESS){
		cout<<"Client Connect Error! : "<<ConnectResult<<endl;
		return false;
	}
	return true;
}

/**
  *@brief Send Message in aSendBuf.
  *@return if write is success, return true.
*/
bool ClientSocket::Send()
{
	ASSERT(aClientSocket != FALSE);
	write(aClientSocket, aSendBuf.c_str(), aSendBuf.size());
	return true;
}

/**
  *@brief Receive Message, and save that in aReceiveBuf.
  		  For handling huge size message, we read message with
		  1000 char unit until read all message.
  *@return if read is success, return true.
*/
bool ClientSocket::Receive()
{
	ASSERT(aClientSocket != FALSE);
	int len;
	string str_buf;
	aReceiveBuf.clear();

	while(1)
	{
	char response[1000];
	len = read(aClientSocket,response,sizeof(response)-1);
	if(len == FALSE){
		cout<<"Client Recieve Error2!"<<endl;
		return false;
	}
	if(len == 0){
		break;
	}
	response[len]=0;
	str_buf = response;
	aReceiveBuf+=str_buf;
	}

	return true;
}

/**
  *@brief Close socket.
*/
bool ClientSocket::Close()
{
	ASSERT(aClientSocket != FALSE);
	close(aClientSocket);
	return true;
}

void ClientSocket::SetSendBuf(const char* Message)
{
	aSendBuf = Message;
}

void ClientSocket::SetSendBuf(string Message)
{
	aSendBuf = Message;
}

string ClientSocket::GetReceiveBuf()
{
	return aReceiveBuf;
}

void ClientSocket::SetServerIP(const char* IP)
{
	aServerIP = IP;
}

void ClientSocket::SetServerPort(int Port)
{
	aServerPort = Port;
}

string ClientSocket::GetServerIP()
{
	return aServerIP;
}

int ClientSocket::GetServerPort()
{
	return aServerPort;
}

	


