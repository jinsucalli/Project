#include <iostream>
//#include "sqlite3.lib"
#include "sqlite3.h"
#include <string.h>
//#include "CppSQLite3U.h"

using namespace std;

int main()
{
	int temp1, temp3;
	char *temp2;
	//	CppSQLite3DB m_db;
	sqlite3 *db = NULL;
	sqlite3_stmt *stmt = NULL;
	char str[100] = "select * from test";

	if(sqlite3_open("test2.db", &db) != SQLITE_OK)
	{
		cout << "fail" << endl;
	}
	else cout << "success!" << endl;


	if(sqlite3_prepare(db, str, strlen(str), &stmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		return 0;
	}

	cout << "count: " << sqlite3_column_count(stmt) << endl;

	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
		temp1 = (int)sqlite3_column_int(stmt, 0);
		temp2 = (char*)sqlite3_column_text(stmt, 1);
		cout << temp1 << "---" << temp2 << endl;
	}




	strcpy(str, "insert into test values(5,'song')");

	if(sqlite3_prepare(db, str, strlen(str), &stmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		return 0;
	}

	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
//		temp1 = (int)sqlite3_column_int(stmt, 0);
//		temp2 = (int)sqlite3_column_int(stmt, 1);
//		cout << temp1 << "---" << temp2 << endl;
		cout << "times" << endl;
	}




	strcpy(str, "delete from test where id = 5");

	if(sqlite3_prepare(db, str, strlen(str), &stmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		return 0;
	}

	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
//		temp1 = (int)sqlite3_column_int(stmt, 0);
//		temp2 = (int)sqlite3_column_int(stmt, 1);
//		cout << temp1 << "---" << temp2 << endl;
		cout << "times" << endl;
	}


	strcpy(str, "update test set name = 'SONG' where id = 3");

	if(sqlite3_prepare(db, str, strlen(str), &stmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		return 0;
	}

	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
//		temp1 = (int)sqlite3_column_int(stmt, 0);
//		temp2 = (int)sqlite3_column_int(stmt, 1);
//		cout << temp1 << "---" << temp2 << endl;
		cout << "times" << endl;
	}



	strcpy(str, "select * from test");
	if(sqlite3_prepare(db, str, strlen(str), &stmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		return 0;
	}

	cout << "count: " << sqlite3_column_count(stmt) << endl;

	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
		temp1 = (int)sqlite3_column_int(stmt, 0);
		temp2 = (char*)sqlite3_column_text(stmt, 1);
		cout << temp1 << "---" << temp2 << endl;
	}

}
