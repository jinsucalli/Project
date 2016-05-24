#include "server_socket.h"
#include "dbinterface.h"

int main(void)
{
	char buf[20000];
	ServerSocket serversocket;
	serversocket.SetPort(8000);

	serversocket.Create();
	serversocket.Bind();
	serversocket.Listen();

	DBinterface LibraryDB;
	if (LibraryDB.Open("library.db")) {
		cout << "Fail to Open library.db" << endl;
		return 0;
	}
	
	while(1)
	{

	serversocket.Accept();
	serversocket.Receive();


	cout<<"From Client: "<<serversocket.GetReceiveBuf()<<endl;
	LibraryDB.InputBuffer(serversocket.GetReceiveBuf());

	cout <<"Server Return: "<<LibraryDB.GetOutput()<<endl;
	//strcpy(buf,"Proper Response");
	serversocket.SetSendBuf( LibraryDB.GetOutput() );
	serversocket.Send();
	serversocket.Close();

	}
}

ServerSocket::ServerSocket()
{
	aClientSocket = FALSE;
	aServerSocket = FALSE;
	aPort = 8000;
	aServerIP = "127.0.0.1";
}

ServerSocket::~ServerSocket()
{
}

bool ServerSocket::Create()
{
	aServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(aServerSocket == FALSE){
		cout<<"Server Create Error!"<<endl;
		return false;
	}
	return true;
}

bool ServerSocket::Bind()
{
	ASSERT(aServerSocket != FALSE);	
	memset(&aServerAddr,0,sizeof(aServerAddr));
	aServerAddr.sin_family = AF_INET;
	aServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	aServerAddr.sin_port = htons(aPort);

	if(bind(aServerSocket, (struct sockaddr *) &aServerAddr, sizeof(aServerAddr)) == FALSE){
		cout<<"Server Bind Error!"<<endl;
		return false;
	}
	return true;
}

bool ServerSocket::Listen()
{
	ASSERT(aServerSocket != FALSE);
	if(listen(aServerSocket, 20)==FALSE){
		cout<<"Server listen Error!"<<endl;
		return false;
	}
	return true;
}

bool ServerSocket::Accept()
{
	ASSERT(aServerSocket != FALSE);
	unsigned int clientaddr_size = sizeof(aClientAddr);
	aClientSocket = accept (aServerSocket, (struct sockaddr *)&aClientAddr, &clientaddr_size);
	if(aClientSocket == FALSE)
	{
		cout<<"Server Accept Error!"<<endl;
		return false;
	}
	return true;
}

bool ServerSocket::Send()
{
	ASSERT(aClientSocket != FALSE);	
	write(aClientSocket, aSendBuf.c_str(), aSendBuf.size());

	return true;
}

bool ServerSocket::Receive()
{
	ASSERT(aClientSocket != FALSE);
	int len;
	char response[3000];
	len = read(aClientSocket,response,sizeof(response)-1);
	if(len == FALSE){
		cout<<"Server Recieve Error!"<<endl;
		return false;
	}
	response[len]=0;
	aReceiveBuf = response;
	return true;
}

bool ServerSocket::Close()
{
	ASSERT(aClientSocket != FALSE);
	close(aClientSocket);
	return true;
}

void ServerSocket::SetSendBuf(const char* Message)
{
	aSendBuf = Message;
}

void ServerSocket::SetSendBuf(string Message)
{
	aSendBuf = Message;
}


string ServerSocket::GetReceiveBuf()
{
	return aReceiveBuf;
}

void ServerSocket::SetServerIP(const char* IP)
{
	aServerIP = IP;
}

void ServerSocket::SetPort(int Port)
{
	aPort = Port;
}


	


