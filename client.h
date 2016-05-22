#ifndef __TAEHO_CLIENT_H__
#define __TAEHO_CLIENT_H__

#define __OPTION_ENABLE_ASSERT__	1
#define FALSE -1
#define SUCCESS 0

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
using namespace std;

#include "client_socket.h"
#if __OPTION_ENABLE_ASSERT__
	#define ASSERT(X)				\
	{								\
		if(!(X)){					\
			cout<<"ASSERT : FILE "<<__FILE__<<", LINE "<<__LINE__<<endl;							   \
		while(1){}					\
		}							\
	}								
#else
	#define ASSERT(X) ((void)0)		
#endif

class Client
{
	private:
		string aQueryBuf;
		ClientSocket aClientSocket;
	public: 
		void InitClient();
		bool MainMenu();
		bool LibraryMain();
		bool FileIO();
		bool NetworkConfig();
		void PrintCopyright();
		
		void Rental();
		void Return();
		bool BookQuery();
		bool MemberQuery();
		bool ReviewQuery();
		
		void InsertBook();
		void DeleteBook();
		void SearchBook();
		void TopRank();

		void InsertReview();
		void GetReviewBook();
		void GetAverageBook();

		void InsertMember();
		void DeleteMember();
		void SearchMember();
		bool UpdateMember();
			
		void Networking();

};
#endif
