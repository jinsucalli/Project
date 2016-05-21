#include "client.h"
#include "client_socket.h"

int main(void)
{

	ClientSocket clientsocket;
	clientsocket.SetServerIP("127.0.0.1");
	clientsocket.SetServerPort(8000);
	clientsocket.Create();
	clientsocket.Connect();
	
	string buf = "ohohoh";
	clientsocket.SetSendBuf(buf);
	clientsocket.Send();
	clientsocket.Receive();
	cout<<clientsocket.GetReceiveBuf()<<endl;
	clientsocket.Close();

}

