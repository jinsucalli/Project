#include<iostream>
#include<sqlite3.h>
#include<cstdlib>
#include<assert.h>
#include <string.h>

using namespace std;

class DBinterface
{
	private:
		sqlite3 *aDB;
		sqlite3_stmt *aStmt;
		char aStr[100];
		int aColumns;
		string aOutput;
		int aMemberNextId;
	public:
		DBinterface();
		int InputBuffer(string);
		int Open(const char *);
		int Select_all();

		int InsertBook(string);
		int InsertReview(string);
		int InsertMember(string);
		
		int SearchBook(string);
		int SearchReview(string);
		int SearchMember(string);

		int GetAvgReview(string);

		int DeleteBook(string);
		int DeleteMember(string);

		int GetRank();
		
		string GetOutput();
		void SetStr(const char *);
		void SetColumns(int);

};

