#include<iostream>
#include<sqlite3.h>
#include<cstdlib>
#include<assert.h>
#include <string.h>

using namespace std;

class DBinterface
{
	private:
		sqlite3 *db;
		sqlite3_stmt *stmt;
		char str[100];
		int cols;
	public:
		DBinterface();
		int open(const char *);
		int select_all();

};

