#include "client.h"
#include "client_socket.h"

int main(void)
{
	Client client;
	client.InitClient();
	while(client.MainMenu()==true);
}

void Client::InitClient()
{
	cout<<"********************************************************"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*          L I B R A R Y   M A N A G E M E N T         *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*                                        Ver 1.0       *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"********************************************************"<<endl;
}

bool Client::MainMenu()
{
	int menu=0;

	cout<<"---------------------------"<<endl;
	cout<<"-    M a i n   M e n u    -"<<endl;
	cout<<"---------------------------"<<endl;

	cout<<"1: Library Main"<<endl;
	cout<<"2: File I/O"<<endl;
	cout<<"3: Network Configuration"<<endl;
	cout<<"4: CopyRight"<<endl;
	cout<<"5: Exit Program"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		if(1<=menu&&menu<=5){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{
				while(LibraryMain()==true);
				return true;
			}
			break;
		case 2:
			{
				while(FileIO()==true);
				return true;
			}
			break;
		case 3:
			{
				while(NetworkConfig()==true);
				return true;
			}
			break;
		case 4:
			{
				PrintCopyright();
				return true;
			}
			break;
		case 5:
			{
				cout<<"See you Again!"<<endl;
				return false;
			}
			break;
		default:
			{
			}
			break;
	}
}

bool Client::LibraryMain()
{
	int menu=0;

	cout<<"---------------------------"<<endl;
	cout<<"-     Library M a i n     -"<<endl;
	cout<<"---------------------------"<<endl;


	cout<<"1: Rental"<<endl;
	cout<<"2: Return"<<endl;
	cout<<"3: Book"<<endl;
	cout<<"4: Member"<<endl;
	cout<<"5: Review"<<endl;
	cout<<"6: Return Main Menu"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=6){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{
				Rental();
				Networking();
				return true;
			}
			break;
		case 2:
			{
				Return();
				Networking();
				return true;
			}
			break;
		case 3:
			{
				while(BookQuery()==true);
				return true;
			}
			break;
		case 4:
			{
				while(MemberQuery()==true);
				return true;
			}
			break;
		case 5:
			{
				while(ReviewQuery()==true);
				return true;
			}
			break;
		case 6:
			{
				return false;
			}
			break;

		default:
			{
			}
			break;
	}
}

bool Client::FileIO()
{
	return false;
}

bool Client::NetworkConfig()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"-  Network Configuration  -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Setting Port Number"<<endl;
	cout<<"2: Setting Server IP"<<endl;
	cout<<"3: Print Current IP & Port"<<endl;
	cout<<"4: Return Main Menu"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=4){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{
				int buf;
				cout<<"Press Port Number:";
				cin>>buf;
				 
				aClientSocket.SetServerPort(buf);
				return true;
			}
			break;
		case 2:
			{
				string buf;
				cout<<"Press IP Address:";
				cin>>buf;
				 
				aClientSocket.SetServerIP(buf.c_str());
				return true;
			}
			break;
		case 3:
			{
				cout<<"Server Port : "<<aClientSocket.GetServerPort()<<endl;
				cout<<"Server IP   : "<<aClientSocket.GetServerIP()<<endl;
				return true;
			}
			break;
		case 4:
			{
				return false;
			}
			break;

		default:
			{
			}
			break;
	}
}

void Client::PrintCopyright()
{
	cout<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*  SoftWare Experiment 3 - Project 3                   *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*  Code by : 2011311541 Kim Taeho                      *"<<endl;
	cout<<"*            2011312409 Jeong JinSu                    *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"*  Last Reform Date : 2016. 05. 24.                    *"<<endl;
	cout<<"*                                                      *"<<endl;
	cout<<"********************************************************"<<endl;
	cout<<endl;
}

void Client::Rental()
{
	string buf;
	aQueryBuf="Rental_:";
	cout<<"UserID: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="|";
	cout<<"BookID: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
}

void Client::Return()
{
	string buf;
	aQueryBuf="Return_:";
	cout<<"UserID: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="|";
	cout<<"BookID: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
}

bool Client::BookQuery()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"-   B o o k   Q u e r y   -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert"<<endl;
	cout<<"2: Delete"<<endl;
	cout<<"3: Search"<<endl;
	cout<<"4: Top 10 Rank"<<endl;
	cout<<"5: Retrun Library Main"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=5){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{	
				InsertBook();
				Networking();
				return true;
			}
			break;
		case 2:
			{
				DeleteBook();
				Networking();
				return true;
			}
			break;
		case 3:
			{
				SearchBook();
				Networking();
				return true;
			}
			break;
		case 4:
			{
				TopRank();
				Networking();
				return true;
			}
			break;
		case 5:
			{
				return false;
			}
			break;
		default:
			{
			}
			break;
	}

}

bool Client::MemberQuery()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"- M e m b e r  Q u e r y  -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert"<<endl;
	cout<<"2: Delete"<<endl;
	cout<<"3: Search"<<endl;
	cout<<"4: Update"<<endl;
	cout<<"5: Retrun Library Main"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=5){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{
				InsertMember();
				Networking();
				return true;
			}
			break;
		case 2:
			{
				DeleteMember();
				Networking();
				return true;
			}
			break;
		case 3:
			{
				SearchMember();
				Networking();
				return true;
			}
			break;
		case 4:
			{
				while(UpdateMember()==true);
				return true;
			}
			break;
		case 5:
			{
				return false;
			}
			break;
		default:
			{
			}
			break;
	}


}

bool Client::ReviewQuery()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"- R e v i e w  Q u e r y  -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert"<<endl;
	cout<<"2: View Review"<<endl;
	cout<<"3: View Average"<<endl;
	cout<<"4: Retrun Library Main"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=4){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{
				InsertReview();
				Networking();
				return true;
			}
			break;
		case 2:
			{
				GetReviewBook();
				Networking();
				return true;
			}
			break;
		case 3:
			{
				GetAverageBook();
				Networking();
				return true;
			}
			break;
		case 4:
			{
				return false;
			}
			break;
		default:
			{
			}
			break;
	}
}

void Client::InsertBook()
{
	string buf;
	aQueryBuf="InsertB:";
	cout<<"BookID: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="|'";
	cout<<"BookName: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="'|'";
	cout<<"Writer: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="'|'";
	cout<<"Publisher: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="'|";
	cout<<"Publication Date: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="|'";
	cout<<"Category: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="'|";
	cout<<"Page: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
	aQueryBuf+="|'";
	cout<<"ISBN: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'";
}

void Client::DeleteBook()
{
	string buf;
	aQueryBuf="DeleteB:";
	cout<<"BookID: ";
	cin>>buf;
	 
	aQueryBuf+=buf;
}

void Client::SearchBook()
{
	string buf;
	char buf_char[300];
	aQueryBuf="SearchB:";
	cout<<"Query: ";
	cin.clear();
	cin.ignore(1,'\n');
	cin.getline(buf_char,300);
	buf=buf_char;
	aQueryBuf+=buf;
}
	

void Client::TopRank()
{
	aQueryBuf="GetRank:NULL";
}

void Client::InsertMember()
{
	string buf;
	aQueryBuf="InsertM:'";
	cout<<"Name: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'|'";

	cout<<"Phone: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'|'";

	cout<<"Email: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'|'";

	cout<<"Address: ";
	cin>>buf; 
	aQueryBuf+=buf;
	aQueryBuf+="'|";
	cout<<"Grade(1~5): ";
	cin>>buf;
	aQueryBuf+=buf;
}

void Client::DeleteMember()
{
	string buf;
	aQueryBuf="DeleteM:";
	cout<<"ID: ";
	cin>>buf;
	aQueryBuf+=buf;
}

void Client::SearchMember()
{
	string buf;
	char buf_char[300];
	aQueryBuf="SearchM:";
	cout<<"Query: ";
	cin.clear();
	cin.ignore(1,'\n');
	cin.getline(buf_char,300);
	buf=buf_char;
	aQueryBuf+=buf;
}
	

bool Client::UpdateMember()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"-     Update  Member      -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Name"<<endl;
	cout<<"2: Phone"<<endl;
	cout<<"3: Email"<<endl;
	cout<<"4: Address"<<endl;
	cout<<"5: Upgrade"<<endl;
	cout<<"6: Return Member Menu"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=6){
			break;
		}
		cout<<"Invalid Input!"<<endl;
		return true;
	}
	cout<<endl;

	switch(menu)
	{
		case 1:
			{
				string buf;
				aQueryBuf="UpdateM:N|";
				cout<<"ID: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="|'";	
				cout<<"New Name: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="'";	
				Networking();
				return true;
			}
			break;
		case 2:
			{
				string buf;
				aQueryBuf="UpdateM:P|";
				cout<<"ID: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="|'";	
				cout<<"New Phone: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="'";	
				Networking();
				return true;
			}
			break;
		case 3:
			{
				string buf;
				aQueryBuf="UpdateM:E|";
				cout<<"ID: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="|'";	
				cout<<"New Email: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="'";	
				Networking();
				return true;
			}
			break;
		case 4:
			{
				string buf;
				aQueryBuf="UpdateM:A|";
				cout<<"ID: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="|'";	
				cout<<"New Address: ";
				cin>>buf;
				aQueryBuf+=buf;
				aQueryBuf+="'";	
				Networking();
				return true;
			}
			break;
		case 5:
			{
				string buf;
				aQueryBuf="UpGrade:";
				cout<<"ID: ";
				cin>>buf;
				aQueryBuf+=buf;
				Networking();
				return true;
			}
			break;
		case 6:
			{
				return false;
			}
			break;
		default:
			{
			}
			break;
	}
}

void Client::InsertReview()
{
	string buf;
	aQueryBuf="InsertR:'";
	cout<<"BookName: ";
	cin>>buf;	 
	aQueryBuf+=buf;
	aQueryBuf+="'|";
	cout<<"Grade: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="|'";
	cout<<"Review: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'";
}

void Client::GetReviewBook()
{
	string buf;
	aQueryBuf="GetRevB:'";
	cout<<"BookName: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'";	
}

void Client::GetAverageBook()
{
	string buf;
	aQueryBuf="GetArgB:'";
	cout<<"BookName: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'";	
}

void Client::Networking()
{
	aClientSocket.Create();
	aClientSocket.Connect();
	
	aClientSocket.SetSendBuf(aQueryBuf);
	aClientSocket.Send();
	aClientSocket.Receive();
	cout<<"======================================"<<endl;
	cout<<aClientSocket.GetReceiveBuf()<<endl;
	cout<<"======================================"<<endl;
	aClientSocket.Close();
}


