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
};
#endif
