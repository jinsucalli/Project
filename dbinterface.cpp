#include "dbinterface.h"

DBinterface:: DBinterface()
{
	aDB = 0;
	aStmt = 0;
	strcpy(aStr, " ");
    /*
  aColumns = sqlite3_column_count(aStmt);


  for (int col = 0; col < aColumns; col++) {
    cout << " / " << sqlite3_column_name(aStmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
	    aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
	    aOutput.append(" | ");
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
	    aOutput.append((const char *)sqlite3_column_text(aStmt, col));
	    aOutput.append(" | ");
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
	    aOutput.append("\n");
  }
*/

}

int DBinterface:: InputBuffer(string buffer)
{
	char temp[10];

	buffer.copy(temp, 7);
	temp[7] = '\0';

	buffer.erase(0,8);

	if(!strcmp(temp, "InsertB")){
		InsertBook(buffer);
	}
	else if(!strcmp(temp, "SearchB")){
		SearchBook(buffer);
	}
	else if(!strcmp(temp, "InsertR")){
		InsertReview(buffer);
	}
	else if(!strcmp(temp, "InsertM")){
		InsertMember(buffer);
	}
	else if(!strcmp(temp, "SearchM")){
		SearchMember(buffer);
	}
	else if(!strcmp(temp, "GetRevB")){
		SearchReview(buffer);
	}
	else if(!strcmp(temp, "GetArgB")){
		GetAvgReview(buffer);
	}
	else if(!strcmp(temp, "DeleteB")){
		DeleteBook(buffer);
	}
	else if(!strcmp(temp, "DeleteM")){
		DeleteMember(buffer);
	}
	else if(!strcmp(temp, "GetRank")){
		GetRank();
	}
	else{
		//InsertReview(buffer);
		aOutput = "Error: Wrong Protocol!";
	}
	cout << temp << endl;
	return 0;
}

int DBinterface::Open(const char* DBname)
{
	int ret;
	
	if(sqlite3_open(DBname, &aDB) != SQLITE_OK)
	{
		cout << "Open Fail" << endl;
		return 1;
	}
	else cout << "Open Success!" << endl;



	string temp("select count(*) from member");
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "Server has Error in Member data\n";
	  }
	else {
		ret = sqlite3_step(aStmt);
		aMemberNextId = (int)sqlite3_column_int(aStmt, 0) + 1;
		cout << "total Member number: " << aMemberNextId-1 << endl;
	}

	temp = "select id from member order by id desc limit 1";
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "Server has Error in Member data\n";
	  }
	else {
		ret = sqlite3_step(aStmt);
		aMemberNextId = (int)sqlite3_column_int(aStmt, 0) + 1;
		cout << "Biggest Member id: " << aMemberNextId-1 << endl;
	}

	return 0;
}


int DBinterface::Select_all()
{

int ret;

	ret = sqlite3_prepare_v2(aDB, "select * from review", -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    return 0;
	  }

  aColumns = sqlite3_column_count(aStmt);


  for (int col = 0; col < aColumns; col++) {
    cout << " / " << sqlite3_column_name(aStmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
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

int DBinterface:: InsertBook(string buffer)
{
	int pos;
	string temp("insert into book(id, name, writer, publisher, publicationdate, category, page, isbn) values(");
	temp.append(buffer);
	temp.append(")");

	while(1)
	{
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}


	if(sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		aOutput = "Fail to Insert!";
		return 0;
	}

	while(sqlite3_step(aStmt) == SQLITE_ROW)
	{
		aOutput = "Fail to Insert!";
		cout << "Error" << endl;
		return 0;
	}

	aOutput = "Success to Insert!";
	return 0;
}


int DBinterface:: InsertMember(string buffer)
{
	int pos;
	int findgradecount = 0;
	string gradevalue;
	int grade=0;

	string temp("insert into member(id, name, phone, email, address, grade, bookrentalperiod, bookrentallimit, bookrentalcurrent) values(");
	temp.append(to_string(aMemberNextId));
	temp.append(", ");
	temp.append(buffer);
	//temp.append(")");


	while(1)
	{
		findgradecount++;
		pos = temp.find('|');
		if(pos == string::npos) break;
		else if(findgradecount==4){
			gradevalue = temp.substr(pos+1,string::npos);
		}
		temp.replace(pos,1,",");
	}

	grade = stoi(gradevalue);

	if(grade < 1 || grade > 5){
		cout << "Error in grade value" << endl;
		aOutput = "Fail to Insert --- Wrong grade Number (1< grade <5)";
		return 0;
	}
	else if(grade == 1){
		temp.append(",1,1,1)");
	}
	else if(grade == 2){
		temp.append(",2,2,2)");
	}
	else if(grade == 3){
		temp.append(",3,3,3)");
	}
	else if(grade == 4){
		temp.append(",4,4,4)");
	}
	else if(grade == 5){
		temp.append(",5,5,5)");
	}

	cout << "query : " << temp << endl; 
	
	if(sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		aOutput = "Fail to Insert!";
		return 0;
	}

	while(sqlite3_step(aStmt) == SQLITE_ROW)
	{
		cout << "Error" << endl;
		aOutput = "Fail to Insert!";
		return 0;
	}

	aOutput = "Success! Your ID is ";
	aOutput.append(to_string(aMemberNextId));
	aMemberNextId++;
	return 0;
}

int DBinterface::InsertReview(string buffer)
{
	aOutput.clear();
	int pos;
	string temp("insert into review(bookname, grade, review) values(");
	temp.append(buffer);
	temp.append(")");

	while(1)
	{
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}


	//strcpy(str, "insert into test values(5,'song')");
	//aStr = temp.c_str();

	if(sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		aOutput = "Fail to Insert!";
		return 0;
	}

	while(sqlite3_step(aStmt) == SQLITE_ROW)
	{
		cout << "Error" << endl;
		aOutput = "Fail to Insert!";
		return 0;
	}

	aOutput = "Success to Insert!";
	return 0;
}


int DBinterface::SearchBook(string buffer)
{
	aOutput.clear();

	int ret;
	int pos;
	string temp("select * from book where ");
	temp.append(buffer);

	while(1)
	{
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    aOutput = "Error: No such Data!";
	    return 0;
	  }

  aColumns = sqlite3_column_count(aStmt);


  for (int col = 0; col < aColumns; col++) {
    cout << " / " << sqlite3_column_name(aStmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
	    aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
	    aOutput.append(" | ");
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
	    aOutput.append((const char *)sqlite3_column_text(aStmt, col));
	    aOutput.append(" | ");
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
	    aOutput.append("\n");
  }



	return 0;
}


int DBinterface::SearchReview(string buffer)
{

	aOutput.clear();

	int ret;
	int pos;
	string temp("select * from review where bookname = ");
	temp.append(buffer);

	while(1)
	{
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    return 0;
	  }

  aColumns = sqlite3_column_count(aStmt);


  for (int col = 0; col < aColumns; col++) {
    cout << " / " << sqlite3_column_name(aStmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
	    aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
	    aOutput.append(" | ");
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
	    aOutput.append((const char *)sqlite3_column_text(aStmt, col));
	    aOutput.append(" | ");
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
	    aOutput.append("\n");
  }

	return 0;
}


int DBinterface::SearchMember(string buffer)
{

	aOutput.clear();

	int ret;
	int pos;
	string temp("select * from member where ");
	temp.append(buffer);

	while(1)
	{
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    return 0;
	  }

  aColumns = sqlite3_column_count(aStmt);


  for (int col = 0; col < aColumns; col++) {
    cout << " / " << sqlite3_column_name(aStmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
	    aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
	    aOutput.append(" | ");
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
	    aOutput.append((const char *)sqlite3_column_text(aStmt, col));
	    aOutput.append(" | ");
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
	    aOutput.append("\n");
  }

	return 0;
}


int DBinterface::GetAvgReview(string buffer)
{

	aOutput.clear();

	int ret;
	int pos;
	double total=0;
	int number=0;
	double ans;

	string temp("select grade from review where bookname = ");
	temp.append(buffer);

	while(1)
	{
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    return 0;
	  }

  aColumns = sqlite3_column_count(aStmt);


  for (int col = 0; col < aColumns; col++) {
    cout << " / " << sqlite3_column_name(aStmt, col);
  }
  cout << endl;

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
	    total += sqlite3_column_int(aStmt, col);
	    number++;
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
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
  	ans = total / number;
	aOutput.append(	to_string(ans) );

	return 0;
}

int DBinterface:: DeleteBook(string buffer)
{
	string temp("delete from book where id=");
	temp.append(buffer);

	if(sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		aOutput = "Fail to Delete!";
		return 0;
	}

	while(sqlite3_step(aStmt) == SQLITE_ROW)
	{
		aOutput = "Fail to Delete!";
		cout << "Error" << endl;
		return 0;
	}

	aOutput = "Success to Delete!";
	return 0;
}

int DBinterface:: DeleteMember(string buffer)
{
	string temp("delete from member where id=");
	temp.append(buffer);

	if(sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK)
	{
		cout << "fail prepare" << endl;
		aOutput = "Fail to Delete!";
		return 0;
	}

	while(sqlite3_step(aStmt) == SQLITE_ROW)
	{
		aOutput = "Fail to Delete!";
		cout << "Error" << endl;
		return 0;
	}

	aOutput = "Success to Delete!";
	return 0;
}

int DBinterface:: GetRank()
{
	aOutput.clear();
	int ret;
	string temp("select name from book order by rentalnumber desc limit 10");

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	  if (ret != SQLITE_OK) {
	    cout << "We did not get any data\n";
	    return 0;
	  }

  aColumns = sqlite3_column_count(aStmt);

  while (true) {
    ret = sqlite3_step(aStmt);
    if (ret == SQLITE_ROW) {
      for (int col = 0; col < aColumns; col++) {
        switch (sqlite3_column_type(aStmt, col)) {
          case SQLITE_INTEGER:
            cout << " / " << sqlite3_column_int(aStmt, col) << " ";
            break;
          case SQLITE_FLOAT:
            cout << " / " << sqlite3_column_double(aStmt, col) << " ";
            break;
          case SQLITE_TEXT:
            cout << " / " << sqlite3_column_text(aStmt, col) << " ";
	    aOutput.append((const char *)sqlite3_column_text(aStmt, col));
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
	    aOutput.append("\n");
  }

	return 0;
}


void DBinterface:: SetStr(const char* newstr)
{
	strcpy(aStr,newstr);
}

void DBinterface:: SetColumns(int newcol)
{
	aColumns = newcol;
}

string DBinterface:: GetOutput()
{
	return aOutput;
}
