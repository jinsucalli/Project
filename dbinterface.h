#include<iostream>
#include<sqlite3.h>
#include<cstdlib>
#include<assert.h>
#include <string.h>
#include <fstream>
using namespace std;

class DBinterface
{
	private:
		sqlite3 *aDB;
		sqlite3_stmt *aStmt;
		string aOutput;
		int aMemberNextId;
		int aToday;
	public:
		DBinterface();
		int InputBuffer(string);
		int Open(const char *);
		//int Select_all();

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
		int Upgrade(string);
	
		int Rental(string);
		int Return(string);

		int UpdateMember(string);

		string GetOutput();
		void SetToday(int);

};

int CalculateDate (int CurrentDate, int period);
