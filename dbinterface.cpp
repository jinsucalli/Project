#include "dbinterface.h"

/*
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
*/


/*
int main()
{
	DBinterface LibraryDB;
	LibraryDB.open("library.db");
	LibraryDB.select_all();
}
*/

DBinterface:: DBinterface()
{
	db = 0;
	stmt = 0;
	strcpy(str, " ");
}

int DBinterface::open(const char* DBname)
{
	
	if(sqlite3_open(DBname, &db) != SQLITE_OK)
	{
		cout << "fail" << endl;
		return 1;
	}
	else cout << "success!" << endl;
	return 0;

}


int DBinterface::select_all()
{

int ret;

	ret = sqlite3_prepare_v2(db, "select * from review", -1, &stmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    return 0;
	  }

  cols = sqlite3_column_count(stmt);


  for (int col = 0; col < cols; col++) {
    cout << " / " << sqlite3_column_name(stmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(stmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < cols; col++) {
        switch (sqlite3_column_type(stmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(stmt, col) << " ";
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(stmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(stmt, col) << " ";
            break;
          case SQLITE_NULL:
            cout << " / " << "NULL" << " ";
            break;
        }
      }
      cout << endl;
    } else if (ret == SQLITE_DONE) {
      //cout << "done" << endl;
      break;
    } else {
      //cout << "ret:" << ret << endl;
      break;
    }
  }

}

