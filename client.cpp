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

/**
  *@brief Function about MainMenu
  *@return if user want exit program, return false.
*/
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
	cout<<"5: Help"<<endl;
	cout<<"6: Exit Program"<<endl;

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
				cout<<"============================================="<<endl;
				cout<<"This Program make for libraian."<<endl;
				cout<<"1. Library Main"<<endl;
				cout<<" - Can almost libraian's work."<<endl;
				cout<<" - Return, Rental, Insert, Delete, Search..."<<endl;
				cout<<"2. File I/O"<<endl;
				cout<<" - Can load data from extern file."<<endl;
				cout<<" - extern file must obey format."<<endl;
				cout<<" - otherwise, this can cause problem."<<endl;
				cout<<"3. NetWork Configuration"<<endl;
				cout<<" - Can view current Server IP and Port,"<<endl;
				cout<<" - and you can change that."<<endl;
				cout<<"============================================="<<endl;
				return true;
			}
			break;
		case 6:
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
	cout<<"- L i b r a r y  M a i n  -"<<endl;
	cout<<"---------------------------"<<endl;


	cout<<"1: Rental"<<endl;
	cout<<"2: Return"<<endl;
	cout<<"3: Book"<<endl;
	cout<<"4: MultiMedia"<<endl;
	cout<<"5: Paper"<<endl;
	cout<<"6: Member"<<endl;
	cout<<"7: Review"<<endl;
	cout<<"8: Help"<<endl;
	cout<<"9: Return Main Menu"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=9){
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
				while(MediaQuery()==true);
				return true;
			}
			break;
		case 5:
			{
				while(PaperQuery()==true);
				return true;
			}
			break;
		case 6:
			{
				while(MemberQuery()==true);
				return true;
			}
			break;
		case 7:
			{
				while(ReviewQuery()==true);
				return true;
			}
			break;
		case 8:
			{
				cout<<"============================================="<<endl;
				cout<<"1. Rental"<<endl;
				cout<<" - Rental work about book."<<endl;
				cout<<" - Need Two component, userID, BookID."<<endl;
				cout<<"2. Return"<<endl;
				cout<<" - Return work about book."<<endl;
				cout<<" - Need Two component, userID, BookID."<<endl;
				cout<<"3. Book"<<endl;
				cout<<" - work about book."<<endl;
				cout<<" - Insert, Delete, Search, List Top 10 Rank."<<endl;
				cout<<"4. MultiMedia"<<endl;
				cout<<" - work about Multi-Media."<<endl;
				cout<<" - Insert, Delete, Search."<<endl;
				cout<<"5. Paper"<<endl;
				cout<<" - work about Paper."<<endl;
				cout<<" - Insert, Delete, Search."<<endl;
				cout<<"6. Member"<<endl;
				cout<<" - work about member."<<endl;
				cout<<" - Insert, Delete, Search, Update."<<endl;
				cout<<"7. Review"<<endl;
				cout<<" - work about review."<<endl;
				cout<<" - Insert, View Review and Average."<<endl;
				cout<<"============================================="<<endl;
				return true;
			}
			break;
		case 9:
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
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"-     F i l e   I / O      -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert Book from File"<<endl;
	cout<<"2: Insert MultiMedia from File"<<endl;
	cout<<"3: Insert Paper from File"<<endl;
	cout<<"4: Insert Member from File"<<endl;
	cout<<"5: Insert Review from File"<<endl;
	cout<<"6: Help"<<endl;
	cout<<"7: Return Main Menu"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=7){
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
				InsertBookFromFile();
				return true;
			}
			break;
		case 2:
			{
				InsertMediaFromFile();
				return true;
			}
			break;
		case 3:
			{
				InsertPaperFromFile();
				return true;
			}
			break;
		case 4:
			{
				InsertMemberFromFile();
				return true;
			}
			break;
		case 5:
			{
				InsertReviewFromFile();
				return true;
			}
			break;
		case 6:
			{
				cout<<"============================================="<<endl;
				cout<<"1. Insert Book from File"<<endl;
				cout<<" - Insert Book Data from extern file."<<endl;
				cout<<" - extern file must obey form."<<endl;
				cout<<" - <ID> <Name> <Writer> <Publisher> <PublicationDate> "
					<<"<Category> <Page> <ISBN>"<<endl;
				cout<<" - ID  : Unique Integer represent book"<<endl;
				cout<<" - Name: BookName. cannot exceed 100 characters."<<endl;
				cout<<" - Writer: Cannot exceed 50 characters."<<endl;
				cout<<" - Publisher: Also cannot exceed 50 characters."<<endl;
				cout<<" - PublicationDate: ex) 20120609"<<endl;
				cout<<" - Category: Keyword represent book. ex)Essay"<<endl;
				cout<<"             Cannot exceed 50 characters."<<endl;
				cout<<" - Page : Number of Page"<<endl;
				cout<<" - ISBN : International Standard Book Number"<<endl;
				cout<<" - Each Book obey upper form, and take one line."<<endl;
				cout<<" - Each Dataform cannot contain space."<<endl<<endl;

				cout<<"2. Insert Multi-Media from File"<<endl;
				cout<<" - Insert Media Data from extern file."<<endl;
				cout<<" - extern file must obey form."<<endl;
				cout<<" - <ID> <Name> <Writer> <Publisher> <PublicationDate> "
					<<"<Category>"<<endl;
				cout<<" - ID  : Unique Integer represent media"<<endl;
				cout<<" - Name: cannot exceed 100 characters."<<endl;
				cout<<" - Writer: Cannot exceed 50 characters."<<endl;
				cout<<" - Publisher: Also cannot exceed 50 characters."<<endl;
				cout<<" - PublicationDate: ex) 20120609"<<endl;
				cout<<" - Category: Keyword represent book. ex)Essay"<<endl;
				cout<<"             Cannot exceed 50 characters."<<endl;
				cout<<" - Each Media obey upper form, and take one line."<<endl;
				cout<<" - Each Dataform cannot contain space."<<endl<<endl;

				cout<<"3. Insert Paper from File"<<endl;
				cout<<" - Insert Paper Data from extern file."<<endl;
				cout<<" - extern file must obey form."<<endl;
				cout<<" - <ID> <Name> <Writer> <PublicationDate> <Keyword>"<<endl;
				cout<<" - ID  : Unique Integer represent Paper"<<endl;
				cout<<" - Name: cannot exceed 100 characters."<<endl;
				cout<<" - Writer: Cannot exceed 50 characters."<<endl;
				cout<<" - PublicationDate: ex) 20120609"<<endl;
				cout<<" - Keyword: Cannot exceed 50 characters."<<endl;
				cout<<" - Each Paper obey upper form, and take one line."<<endl;
				cout<<" - Each Dataform cannot contain space."<<endl<<endl;

				cout<<"4. Insert Member from File"<<endl;
				cout<<" - Insert Member data from extern file."<<endl;
				cout<<" - extern file must obey form."<<endl;
				cout<<" - <Name> <Phone> <Email> <Address> <Grade>"<<endl;
				cout<<" - Name : cannot exceed 50 characters."<<endl;
				cout<<" - Phone: Without Hyphen. ex) 01012345678"<<endl;
				cout<<" - Email: cannot exceed 50 characters."<<endl;
				cout<<" - Address: cannot exceed 100 characters."<<endl;
				cout<<" - Grade: Integer between 1~5."<<endl;
				cout<<"          1 : Can rental 2 books for 5 days."<<endl;
				cout<<"          2 : Can rental 3 books for 7 days."<<endl;
				cout<<"          3 : Can rental 5 books for 7 days."<<endl;
				cout<<"          4 : Can rental 10 books for 10 days."<<endl;
				cout<<"          5 : Can rental 15 books for 15 days."<<endl;
				cout<<" - Each Member obey form, and take one line."<<endl;
				cout<<" - Each Dataform cannot contain space."<<endl<<endl;;
				cout<<"5. Insert Review from File"<<endl;
				cout<<" - Insert Review from extern file."<<endl;
				cout<<" - extern file must obey form."<<endl;
				cout<<" - <BookName> <Grade> <Review> "<<endl;
				cout<<" - Grade: Integer between 1~5."<<endl;
				cout<<" - Review: Cannot exceed 100 characters."<<endl;
				cout<<" - Each Review obey form, and take one line."<<endl;
				cout<<" - Each Dataform cannot contain space."<<endl;
				cout<<"============================================="<<endl;
				return true;
			}
			break;
		case 7:
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
	cout<<"5: Help"<<endl;
	cout<<"6: Return Library Main"<<endl;

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
				cout<<"============================================="<<endl;
				cout<<"1. Insert"<<endl;
				cout<<" - Insert New Book."<<endl;
				cout<<" - Next 8 components need,"<<endl;
				cout<<" - ID  : Unique Integer represent book"<<endl;
				cout<<" - Name: BookName. cannot exceed 100 characters."<<endl;
				cout<<" - Writer: Cannot exceed 50 characters."<<endl;
				cout<<" - Publisher: Also cannot exceed 50 characters."<<endl;
				cout<<" - PublicationDate: ex) 20120609"<<endl;
				cout<<" - Category: Keyword represent book. ex)Essay"<<endl;
				cout<<"             Cannot exceed 50 characters."<<endl;
				cout<<" - Page : Number of Page"<<endl;
				cout<<" - ISBN : International Standard Book Number"<<endl;
				cout<<" - Each Components cannot contain space."<<endl;
				cout<<"2. Delete"<<endl;
				cout<<" - Delete a book from database."<<endl;
				cout<<" - Need a component, BookID."<<endl;
				cout<<"3. Search"<<endl;
				cout<<" - Search proper books with some condition."<<endl;
				cout<<" - Condition like this. Page=200"<<endl;
				cout<<"4. Top 10 Rank"<<endl;
				cout<<" - Print Top 10 list for rental number"<<endl;
				cout<<"============================================="<<endl;
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

bool Client::MediaQuery()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"-   Multi-Media  Query    -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert"<<endl;
	cout<<"2: Delete"<<endl;
	cout<<"3: Search"<<endl;
	cout<<"4: Help"<<endl;
	cout<<"5: Return Library Main"<<endl;

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
				InsertMedia();
				Networking();
				return true;
			}
			break;
		case 2:
			{
				DeleteMedia();
				Networking();
				return true;
			}
			break;
		case 3:
			{
				SearchMedia();
				Networking();
				return true;
			}
			break;
		case 4:
			{
				cout<<"============================================="<<endl;
				cout<<"1. Insert"<<endl;
				cout<<" - Insert New Multi-Media."<<endl;
				cout<<" - Next 6 components need,"<<endl;
				
				cout<<" - ID  : Unique Integer represent media"<<endl;
				cout<<" - Name: cannot exceed 100 characters."<<endl;
				cout<<" - Writer: Cannot exceed 50 characters."<<endl;
				cout<<" - Publisher: Also cannot exceed 50 characters."<<endl;
				cout<<" - PublicationDate: ex) 20120609"<<endl;
				cout<<" - Category: Keyword represent book. ex)Essay"<<endl;
				cout<<"             Cannot exceed 50 characters."<<endl;
				cout<<" - Each Components cannot contain space."<<endl;
				cout<<"2. Delete"<<endl;
				cout<<" - Delete a Media from database."<<endl;
				cout<<" - Need a component, MediaID."<<endl;
				cout<<"3. Search"<<endl;
				cout<<" - Search proper Multi-Medias with some condition."<<endl;
				cout<<" - Condition like this. ID=5"<<endl;
				cout<<"============================================="<<endl;
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

bool Client::PaperQuery()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"-   P a p e r  Q u e r y  -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert"<<endl;
	cout<<"2: Delete"<<endl;
	cout<<"3: Search"<<endl;
	cout<<"4: Help"<<endl;
	cout<<"5: Return Library Main"<<endl;

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
				InsertPaper();
				Networking();
				return true;
			}
			break;
		case 2:
			{
				DeletePaper();
				Networking();
				return true;
			}
			break;
		case 3:
			{
				SearchPaper();
				Networking();
				return true;
			}
			break;
		case 4:
			{
				cout<<"============================================="<<endl;
				cout<<"1. Insert"<<endl;
				cout<<" - Insert New Paper."<<endl;
				cout<<" - Next 5 components need,"<<endl;
				cout<<" - ID  : Unique Integer represent Paper"<<endl;
				cout<<" - Name: cannot exceed 100 characters."<<endl;
				cout<<" - Writer: Cannot exceed 50 characters."<<endl;
				cout<<" - PublicationDate: ex) 20120609"<<endl;
				cout<<" - Keyword: Cannot exceed 50 characters."<<endl;
				cout<<" - Each Components cannot contain space."<<endl;
				cout<<"2. Delete"<<endl;
				cout<<" - Delete a Paper from database."<<endl;
				cout<<" - Need a component, PaperID."<<endl;
				cout<<"3. Search"<<endl;
				cout<<" - Search proper Paperrs with some condition."<<endl;
				cout<<" - Condition like this. ID=5"<<endl;
				cout<<"============================================="<<endl;
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
	cout<<"5: Help"<<endl;
	cout<<"6: Return Library Main"<<endl;

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
				cout<<"============================================="<<endl;
				cout<<"1. Insert"<<endl;
				cout<<" - Insert New Member."<<endl;
				cout<<" - Next 5 components need,"<<endl;
				cout<<" - Name : cannot exceed 50 characters."<<endl;
				cout<<" - Phone: Without Hyphen. ex) 01012345678"<<endl;
				cout<<" - Email: cannot exceed 50 characters."<<endl;
				cout<<" - Address: cannot exceed 100 characters."<<endl;
				cout<<" - Grade: Integer between 1~5."<<endl;
				cout<<"          1 : Can rental 2 books for 5 days."<<endl;
				cout<<"          2 : Can rental 3 books for 7 days."<<endl;
				cout<<"          3 : Can rental 5 books for 7 days."<<endl;
				cout<<"          4 : Can rental 10 books for 10 days."<<endl;
				cout<<"          5 : Can rental 15 books for 15 days."<<endl;
				cout<<" - Each Components cannot contain space."<<endl;
				cout<<" - Return User ID."<<endl;
				cout<<"2. Delete"<<endl;
				cout<<" - Delete a Member from database."<<endl;
				cout<<" - Need a component, UserID."<<endl;
				cout<<"3. Search"<<endl;
				cout<<" - Search proper members with some condition."<<endl;
				cout<<" - Condition like this. Grade=5"<<endl;
				cout<<"4. Update"<<endl;
				cout<<" - Update members."<<endl;
				cout<<"============================================="<<endl;
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

bool Client::ReviewQuery()
{
	int menu=0;
	cout<<"---------------------------"<<endl;
	cout<<"- R e v i e w  Q u e r y  -"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"1: Insert"<<endl;
	cout<<"2: View Review"<<endl;
	cout<<"3: View Average"<<endl;
	cout<<"4: Help"<<endl;
	cout<<"5: Return Library Main"<<endl;

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
				cout<<"============================================="<<endl;
				cout<<"1. Insert"<<endl;
				cout<<" - Insert New Review."<<endl;
				cout<<" - Next 3 components need,"<<endl;
				cout<<" - BookName: BookName."<<endl;
				cout<<" - Grade: Integer between 1~5."<<endl;
				cout<<" - Review: Cannot exceed 100 characters."<<endl;
				cout<<" - Each Components cannot contain space."<<endl;
				cout<<"2. View Review"<<endl;
				cout<<" - Print all review for some bookname."<<endl;
				cout<<"3. View Average"<<endl;			
				cout<<" - Print average of grade for some bookname."<<endl;
				cout<<"============================================="<<endl;
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
void Client::InsertMedia()
{
	string buf;
	aQueryBuf="InsertD:";
	cout<<"ID: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="|'";

	cout<<"Name: ";
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
	aQueryBuf+="'";
}

void Client::DeleteMedia()
{
	string buf;
	aQueryBuf="DeleteD:";
	cout<<"ID: ";
	cin>>buf;
	aQueryBuf+=buf;
}

void Client::SearchMedia()
{
	string buf;
	char buf_char[300];
	aQueryBuf="SearchD:";
	cout<<"Query: ";
	cin.clear();
	cin.ignore(1,'\n');
	cin.getline(buf_char,300);
	buf=buf_char;
	aQueryBuf+=buf;
}

void Client::InsertPaper()
{
	string buf;
	aQueryBuf="InsertP:";
	cout<<"ID: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="|'";

	cout<<"Name: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'|'";

	cout<<"Writer: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'|";
	cout<<"Publication Date: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="|'";
	cout<<"Keyword: ";
	cin>>buf;
	aQueryBuf+=buf;
	aQueryBuf+="'";
}

void Client::DeletePaper()
{
	string buf;
	aQueryBuf="DeleteP:";
	cout<<"ID: ";
	cin>>buf;
	aQueryBuf+=buf;
}

void Client::SearchPaper()
{
	string buf;
	char buf_char[300];
	aQueryBuf="SearchP:";
	cout<<"Query: ";
	cin.clear();
	cin.ignore(1,'\n');
	cin.getline(buf_char,300);
	buf=buf_char;
	aQueryBuf+=buf;
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
	aQueryBuf="SearchD:";
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
	cout<<"6: Help"<<endl;
	cout<<"7: Return Member Menu"<<endl;

	while(1){
		cout<<"Select Menu: ";
		cin>>menu;
		 
		if(1<=menu&&menu<=7){
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
				cout<<"============================================="<<endl;
				cout<<"5. Upgrade"<<endl;			
				cout<<" - Upgrade for some user membership."<<endl;
				cout<<"============================================="<<endl;
				return true;
			}
			break;
		case 7:
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

void Client::InsertBookFromFile()
{
	string FileName;
	ifstream fin;
	while(1)
	{
		cout<<"Type File Name :";
		cin>>FileName;
		if(FileName=="exit"){
			return;
		}
		fin.open(FileName.c_str());
		if(fin.is_open()){
			break;
		}
		cout<<"Invalid File Name! if you want to exit, type 'exit'!"<<endl;
		cin.clear();
	}
	int baton=0;
	string buf;
	cout<<"======================================"<<endl;
	while(fin>>buf)
	{
		switch(baton)
		{
			case 0:
				{
					baton++;		
					aQueryBuf="InsertB:";
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 1:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 2:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 3:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|";
				}
				break;
			case 4:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 5:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|";
				}
				break;
			case 6:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 7:
				{
					baton=0;
					aQueryBuf+=buf;
					aQueryBuf+="'";
					Networking();
				}
				break;
			default:
				{
				}
				break;
		}
	}
	cout<<"======================================"<<endl;
	fin.close();
}

void Client::InsertMediaFromFile()
{
	string FileName;
	ifstream fin;
	while(1)
	{
		cout<<"Type File Name :";
		cin>>FileName;
		if(FileName=="exit"){
			return;
		}
		fin.open(FileName.c_str());
		if(fin.is_open()){
			break;
		}
		cout<<"Invalid File Name! if you want to exit, type 'exit'!"<<endl;
		cin.clear();
	}
	int baton=0;
	string buf;
	cout<<"======================================"<<endl;
	while(fin>>buf)
	{
		switch(baton)
		{
			case 0:
				{
					baton++;		
					aQueryBuf="InsertD:";
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 1:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 2:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 3:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|";
				}
				break;
			case 4:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 5:
				{
					baton=0;
					aQueryBuf+=buf;
					aQueryBuf+="'";
					Networking();
				}
				break;
			default:
				{
				}
				break;
		}
	}
	cout<<"======================================"<<endl;
	fin.close();
}

void Client::InsertPaperFromFile()
{
	string FileName;
	ifstream fin;
	while(1)
	{
		cout<<"Type File Name :";
		cin>>FileName;
		if(FileName=="exit"){
			return;
		}
		fin.open(FileName.c_str());
		if(fin.is_open()){
			break;
		}
		cout<<"Invalid File Name! if you want to exit, type 'exit'!"<<endl;
		cin.clear();
	}
	int baton=0;
	string buf;
	cout<<"======================================"<<endl;
	while(fin>>buf)
	{
		switch(baton)
		{
			case 0:
				{
					baton++;		
					aQueryBuf="InsertP:";
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 1:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 2:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|";
				}
				break;
			case 3:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 4:
				{
					baton=0;
					aQueryBuf+=buf;
					aQueryBuf+="'";
					Networking();
				}
				break;
			default:
				{
				}
				break;
		}
	}
	cout<<"======================================"<<endl;
	fin.close();
}

void Client::InsertMemberFromFile()
{
	string FileName;
	ifstream fin;
	while(1)
	{
		cout<<"Type File Name :";
		cin>>FileName;
		if(FileName=="exit"){
			return;
		}
		fin.open(FileName.c_str());
		if(fin.is_open()){
			break;
		}
		cout<<"Invalid File Name! if you want to exit, type 'exit'!"<<endl;
		cin.clear();
	}
	int baton=0;
	string buf;
	cout<<"======================================"<<endl;
	while(fin>>buf)
	{
		switch(baton)
		{
			case 0:
				{
					baton++;		
					aQueryBuf="InsertM:'";
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 1:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 2:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|'";
				}
				break;
			case 3:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="'|";
				}
				break;
			case 4:
				{
					baton=0;
					aQueryBuf+=buf;
					Networking();
				}
				break;
			default:
				{
				}
				break;
		}
	}
	cout<<"======================================"<<endl;
	fin.close();
}

void Client::InsertReviewFromFile()
{
	string FileName;
	ifstream fin;
	while(1)
	{
		cout<<"Type File Name :";
		cin>>FileName;
		if(FileName=="exit"){
			return;
		}
		fin.open(FileName.c_str());
		if(fin.is_open()){
			break;
		}
		cout<<"Invalid File Name! if you want to exit, type 'exit'!"<<endl;
		cin.clear();
	}
	int baton=0;
	string buf;
	cout<<"======================================"<<endl;
	while(fin>>buf)
	{
		switch(baton)
		{
			case 0:
				{
					baton++;		
					aQueryBuf="InsertR:'";
					aQueryBuf+=buf;
					aQueryBuf+="'|";
				}
				break;
			case 1:
				{
					baton++;
					aQueryBuf+=buf;
					aQueryBuf+="|'";
				}
				break;
			case 2:
				{
					baton=0;
					aQueryBuf+=buf;
					aQueryBuf+="'";
					Networking();
				}
				break;
			default:
				{
				}
				break;
		}
	}
	cout<<"======================================"<<endl;
	fin.close();
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


