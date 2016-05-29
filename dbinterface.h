#ifndef __JINSU_DB_H__
#define __JINSU_DB_H__

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
		//int InputBuffer(string);
		int Open(const char *);

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

		int InsertMedia(string);
		int SearchMedia(string);
		int DeleteMedia(string);

		int InsertPaper(string);
		int SearchPaper(string);
		int DeletePaper(string);

		string GetOutput();
		void SetOutput(string);
		void SetToday(int);

};

int CalculateDate (int CurrentDate, int period);

#endif
