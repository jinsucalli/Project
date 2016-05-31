#include "dbinterface.h"

DBinterface:: DBinterface()
{
	aDB 	= 0;
	aStmt 	= 0;
}

/*
	@param : raw data of String from client
	@brief : it is first control about input
			call proper function at each cases.
*/
/*
int DBinterface:: InputBuffer(string buffer)
{
	char 	temp[8];

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
	else if(!strcmp(temp, "UpGrade")){
		Upgrade(buffer);
	}
	else if(!strcmp(temp, "Rental_")){
		Rental(buffer);
	}
	else if(!strcmp(temp, "Return_")){
		Return(buffer);
	}
	else if(!strcmp(temp, "UpdateM")){
		UpdateMember(buffer);
	}
	else{
		aOutput = "Error: Wrong Protocol!";
	}
	return 0;
}
*/
/*
	@brief : when DBinterface is started, it must do first
		open DB, initialize, setting Today.
	@return : if fail return 1
			, success 0
*/
int DBinterface::Open(const char* DBname)
{
	int 		ret;
	string 		temp;
	ifstream	fin;
	string		day_buffer;
	
	if(sqlite3_open(DBname, &aDB) != SQLITE_OK)
	{
		cout << "No That Name of DB" << endl;
		return 1;
	}
	else cout << "Open Success!" << endl;

	temp = "select count(*) from member";
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		cout << "Server has No Member data\n";
	}
	else {
		ret = sqlite3_step(aStmt);
		cout << "total Member number: " << (int)sqlite3_column_int(aStmt, 0) << endl;
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

	fin.open("today.txt");
	if (fin.is_open()) {
		if (fin >> day_buffer) {
			aToday = stoi(day_buffer);
			fin.close();
			cout << "Today : " << aToday << endl;
		}
		else {
			cout << "No Data in 'today.txt'" << endl;
			return 1;
		}
	}
	else {
		cout << "There is No 'today.txt'" << endl;
		return 1;
	}
	return 0;
}

/*
	@brief : insert book
			it check duplication of 'book ID'
	@param : <id>|<name>|<writer>|<publisher>|<publicationdate>
			|<category>|<page>|<isbn>
*/
int DBinterface:: InsertBook(string buffer)
{
	int 	pos;
	string 	temp;
	string 	book_id;
	int 	ret;

	pos = buffer.find('|');
	book_id = buffer.substr(0, pos);

	temp = "select id from book where id =";
	temp.append(book_id);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	
	if (ret != SQLITE_OK) {
		aOutput = "Fail to Insert --- ID is Wrong Format";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if ((int)sqlite3_column_int(aStmt, 0) != 0) {
			aOutput = "Fail to Insert --- ID is already exist";
			return 0;
		}
	}

	temp = "insert into book(rentalid, rentalnumber, id, name, writer, "
		"publisher, publicationdate, category, page, isbn) values(0, 0, ";
	temp.append(buffer);
	temp.append(")");

	while (1) {
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Insert --- Wrong Input";
		return 0;
	}

	sqlite3_step(aStmt);
	aOutput = "Success to Insert!";
	return 0;
}

/*
	@brief : insert member
			it check duplication of 'phone number'
	@param : <id>|<name>|<writer>|<publisher>|<publicationdate>
			|<category>|<page>|<isbn>
*/
int DBinterface:: InsertMember(string buffer)
{
	int 	pos;
	int 	ret;
	int 	findgrade_count;
	int 	find_phone_pos;
	string 	gradevalue;
	string 	phone_number;
	int 	grade;
	string 	temp; 

	findgrade_count	= 0;
	grade		= 0;

	while (1)
	{
		findgrade_count++;
		pos = buffer.find('|');
		if (pos == string::npos) break;
		else if (findgrade_count == 1) {
			find_phone_pos = pos;
		}
		else if (findgrade_count == 2) {
			phone_number = buffer.substr(find_phone_pos+1, pos-find_phone_pos-1);
		}
		else if (findgrade_count == 4) {
			gradevalue = buffer.substr(pos+1,string::npos);
		}
		buffer.replace(pos,1,",");
	}

	temp = "select id from member where phone =";
	temp.append(phone_number);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	
	if (ret != SQLITE_OK) {
		aOutput = "Fail to Insert --- Phone is Wrong Format";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if ((int)sqlite3_column_int(aStmt, 0) != 0) {
			aOutput = "Fail to Insert --- Phone is already exist";
			return 0;
		}
	}

	temp = "insert into member(id, name, phone, email, address, grade, "
		"bookrentalperiod, bookrentallimit, bookrentalcurrent) values(";
	temp.append(to_string(aMemberNextId));
	temp.append(", ");
	temp.append(buffer);

	while (1)
	{
		pos = temp.find('|');
		if (pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	grade = stoi(gradevalue);

	if (grade < 1 || grade > 5) {
		aOutput = "Fail to Insert --- Wrong grade Number (1< grade <5)";
		return 0;
	}
	else if (grade == 1) {
		temp.append(",5,2,0)");
	}
	else if (grade == 2) {
		temp.append(",7,3,0)");
	}
	else if (grade == 3) {
		temp.append(",7,5,0)");
	}
	else if (grade == 4) {
		temp.append(",10,10,0)");
	}
	else if (grade == 5) {
		temp.append(",15,15,0)");
	}
	
	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Insert!";
		return 0;
	}
	
	sqlite3_step(aStmt);

	aOutput = "Success! Your ID is ";
	aOutput.append(to_string(aMemberNextId));
	aMemberNextId++;
	return 0;
}

/*
	@brief : insert review
	@param : <bookname>|<grade>|<review>
*/
int DBinterface::InsertReview(string buffer)
{
	int	pos;
	string	temp;

	aOutput.clear();
	temp = "insert into review(bookname, grade, review) values(";
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
		aOutput = "Fail to Insert --- Wrong Input";
		return 0;
	}

	sqlite3_step(aStmt);
	
	aOutput = "Success to Insert!";
	return 0;
}

/*
	@brief  : search book by condition
	@param  : <condition>	ex) name='Book_name'
	@return : all data set of book(s)
*/
int DBinterface::SearchBook(string buffer)
{
	int 	ret;
	int 	pos;
	int 	columns;
	int	count;
	string 	temp;

	count	= 0;

	temp = "select * from book where ";
	temp.append(buffer);
	aOutput.clear();

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Search --- Wrong Input";
	    	return 0;
	}

  	columns = sqlite3_column_count(aStmt);

  	for (int col = 0; col < columns; col++) {
    		aOutput.append(sqlite3_column_name(aStmt, col));
    		aOutput.append(" | ");
  	}
  	aOutput.append("\n");
  
  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
			count++;
			for (int col = 0; col < columns; col++) {
				switch (sqlite3_column_type(aStmt, col)) {
					case SQLITE_INTEGER:
						aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
						aOutput.append("  ");
						break;
					case SQLITE_TEXT:
						aOutput.append((const char *)sqlite3_column_text(aStmt, col));
						aOutput.append("  ");
						break;
				}
			}
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
	    	aOutput.append("\n");
  	}

	if (count == 0) {
		aOutput = "No Book in This Condition";
	}

	return 0;
}

/*
	@brief  : search review by bookname
	@param : <bookname>
*/
int DBinterface::SearchReview(string buffer)
{
	int 	ret;
	int 	pos;
	int	columns;
	int	count;
	string 	temp;

	count	= 0;

	aOutput.clear();
	temp = "select * from review where bookname = ";
	temp.append(buffer);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Search --- Wrong Input";
	    	return 0;
	}

  	columns = sqlite3_column_count(aStmt);

  	for (int col = 0; col < columns; col++) {
    		aOutput.append(sqlite3_column_name(aStmt, col));
    		aOutput.append(" | ");
  	}
  	aOutput.append("\n");
	 
  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
			count++;
			for (int col = 0; col < columns; col++) {
				switch (sqlite3_column_type(aStmt, col)) {
					case SQLITE_INTEGER:
						aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
						aOutput.append("  ");
						break;
					case SQLITE_TEXT:
						aOutput.append((const char *)sqlite3_column_text(aStmt, col));
						aOutput.append("  ");
						break;
				}
			}
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
	    	aOutput.append("\n");
  	}
	
	if (count == 0) {
		aOutput = "No Review in This Book";
	}

	return 0;
}

/*
	@brief  : search member by condition
	@param : <condition>
*/
int DBinterface::SearchMember(string buffer)
{
	int 	ret;
	int 	pos;
	int	columns;
	int 	count;
	string	temp;

	count	= 0;

	temp = "select * from member where ";
	temp.append(buffer);
	aOutput.clear();

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		cout << "Fail to Search --- Wrong Input\n";
	    	return 0;
	}

  	columns = sqlite3_column_count(aStmt);
	
  	for (int col = 0; col < columns; col++) {
    		aOutput.append(sqlite3_column_name(aStmt, col));
    		aOutput.append(" | ");
  	}
  	aOutput.append("\n");
  
  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
			count++;
			for (int col = 0; col < columns; col++) {
				switch (sqlite3_column_type(aStmt, col)) {
					case SQLITE_INTEGER:
						aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
						aOutput.append("  ");
						break;
					case SQLITE_TEXT:
						aOutput.append((const char *)sqlite3_column_text(aStmt, col));
						aOutput.append("  ");
						break;
				}
			}
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
	    	aOutput.append("\n");
  	}

	if (count == 0) {
		aOutput = "No Member in This Condition";
	}

	return 0;
}

/*
	@brief : get average grade of review at one book
	@param : <condition>
*/
int DBinterface::GetAvgReview(string buffer)
{
	int 	ret;
	int 	pos;
	double 	total;
	int 	number;
	double 	ans;
	string	temp;

	total	= 0;
	number	= 0;
	aOutput.clear();

	temp = "select grade from review where bookname = ";
	temp.append(buffer);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Wrong Input Data";
	    	return 0;
	}

  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
		    	total += sqlite3_column_int(aStmt, 0);
		    	number++;
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
  	}

  	if (number == 0) {
		aOutput = "No Review in Book";
	}
	else {
		ans = total / number;
		aOutput.append(to_string(ans));
	}
	return 0;
}

/*
	@brief : delete book
			it make release member's rental condition
	@param : <id>
*/
int DBinterface:: DeleteBook(string buffer)
{
	string 	temp;
	int 	ret;
	int	member_id;
	int	rental_current;

	temp = "select rentalid from book where id =";
	temp.append(buffer);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Delete --- Wrong Book Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret != SQLITE_ROW) {
			aOutput = "Fail to Delete --- No Book Id";
			return 0;
		}
		else {
		    	member_id = (int)sqlite3_column_int(aStmt, 0);
		}
	}

	if (member_id != 0) {
		temp = "select bookrentalcurrent from member where id =";
		temp.append(to_string(member_id));
		
		ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

		if (ret != SQLITE_OK) {
			aOutput = "Error in Delete --- Wrong Member Id";
			return 0;
		}
		else {
			ret = sqlite3_step(aStmt);
			if (ret == SQLITE_ROW) {
				rental_current = (int)sqlite3_column_int(aStmt, 0);
			}
			else {
				aOutput = "Error in Delete --- No Member Id";
				return 0;
			}
		}
	
		// write RentalCurrent in Member
		temp = "update member set bookrentalcurrent=";
		temp.append(to_string(rental_current-1));
		temp.append(" where id=");
		temp.append(to_string(member_id));
		ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
		if (ret != SQLITE_OK) {
			aOutput = "Error in Delete --- Unkowm Reason";
			return 0;
		}
		else {
			sqlite3_step(aStmt);
		}
	}

	temp = "delete from book where id=";
	temp.append(buffer);

	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Delete!";
		return 0;
	}

	sqlite3_step(aStmt);
	
	aOutput = "Success to Delete!";
	return 0;
}

/*
	@brief : delete member
			it make release book's rental condition
	@param : <id>
*/
int DBinterface:: DeleteMember(string buffer)
{
	string	temp;
	int 	ret;
	int	number_rental;
	int	rental_id[20];

	number_rental = 0;

	temp = "select id from member where id =";
	temp.append(buffer);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Delete --- Wrong Member Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret != SQLITE_ROW) {
			aOutput = "Fail to Delete --- No Member Id";
			return 0;
		}
	}

	temp = "update book set rentalid=0";
	temp.append(" where rentalid=");
	temp.append(buffer);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Error in Delete --- Wrong Input";
		return 0;
	}
	else {
		sqlite3_step(aStmt);
	}

	temp = "delete from member where id=";
	temp.append(buffer);

	if(sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK)
	{
		aOutput = "Fail to Delete!";
		return 0;
	}

	sqlite3_step(aStmt);
	
	aOutput = "Success to Delete!";
	return 0;
}

/*
	@brief  : get rank of book
	@Return : 10 Books' name of Most Rentaled
*/
int DBinterface:: GetRank()
{
	int 	count;
	int 	ret;
	string 	temp;

	count	= 1;
	temp	= "select name from book order by rentalnumber desc limit 10";
	aOutput.clear();

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
	 	aOutput = "No data";
		return 0;
	}

  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
			aOutput.append(to_string(count));
			aOutput.append(". ");
		    	aOutput.append((const char *)sqlite3_column_text(aStmt, 0));
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
	    	aOutput.append("\n");
		count++;
  	}

	return 0;
}

/*
	@brief  : upgrade 'grade' of member
			it change rental period, rental limit
			it check it's pre-grade(<5)
	@param : <id>
*/
int DBinterface:: Upgrade(string buffer)
{
	int 	ret;
	int 	before_grade;
	string 	temp;

	temp 	= "select grade from member where id = ";
	temp.append(buffer);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Upgrade -- Wrong ID";
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret == SQLITE_ROW) {
			before_grade = (int)sqlite3_column_int(aStmt, 0);
			if(before_grade > 0 && before_grade < 5){
				temp = "update member set grade=";
				temp.append(to_string(before_grade+1));
				if(before_grade == 1) {
					temp.append(",bookrentalperiod=7,bookrentallimit=3");
				}
				else if(before_grade == 2) {
					temp.append(",bookrentalperiod=7,bookrentallimit=5");
				}
				else if(before_grade == 3) {
					temp.append(",bookrentalperiod=10,bookrentallimit=10");
				}
				else if(before_grade == 4) {
					temp.append(",bookrentalperiod=15,bookrentallimit=15");
				}
				temp.append(" where id=");
				temp.append(buffer);
				ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

				if(ret != SQLITE_OK){
					aOutput = "Fail to Upgrade --- Unknown Reason";
				}
				else {
					sqlite3_step(aStmt);
					aOutput = "Success to Upgrade : ";
					aOutput.append(to_string(before_grade+1));
				}
			}
			else if (before_grade == 0) {
				aOutput = "Fail to Upgrade -- No Data";
			}
			else {
				aOutput = "Fail to Upgrade -- Max Grade";
			}
		}
		else {
			aOutput = "Fail to Upgrade -- No Data";
		}
	}
	
	return 0;
}

/*
	@brief : rental a book by a member
			it check book ID & member ID
			if member has late any books
				he cannot rental
			it setting rental date & return date
	@param : <id>|<bookid>
	@return : fail or success
			and return date
*/
int DBinterface:: Rental(string buffer)
{
	int 	pos;
	string 	member_id;
	string 	book_id;
	int 	rental_period;
	int 	rental_limit;
	int 	rental_current;
	string 	temp;
	int 	ret;
	int 	is_rental;
	int 	rental_number;

	pos = buffer.find('|');
	if(pos == string::npos) {
		aOutput = "Fail to Rental --- Wrong Input";
		return 0;
	}
	else {
		book_id = buffer.substr(pos+1, string::npos);
		member_id = buffer.substr(0, pos);
	}

	temp = "select bookrentalperiod, bookrentallimit, "
		"bookrentalcurrent from member where id =";
	temp.append(member_id);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Error in Rental --- Wrong Member Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret == SQLITE_ROW) {
			rental_period = (int)sqlite3_column_int(aStmt, 0);
			rental_limit = (int)sqlite3_column_int(aStmt, 1);
			rental_current = (int)sqlite3_column_int(aStmt, 2);
		}
		else {
			aOutput = "Error in Rental --- No Member Id";
			return 0;
		}
	}

	if(rental_limit <= rental_current) {
		aOutput = "Fail to Rental --- Current Rental > Limit";
		return 0;
	}

	temp = "select name from book where rentalid = ";
	temp.append(member_id);
	temp.append(" and returndate < ");
	temp.append(to_string(aToday));
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
cout << temp<<endl;
	if (ret != SQLITE_OK) {
		aOutput = "Error in Rental --- Wrong Input";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret == SQLITE_ROW) {
			aOutput = "Fail to Rental --- You need to return : ";
			aOutput.append((const char *)sqlite3_column_text(aStmt, 0));
			return 0;
		}
	}


	temp = "select rentalid, rentalnumber from book where id =";
	temp.append(book_id);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Error in Rental --- Wrong Book Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret == SQLITE_ROW) {
			is_rental = (int)sqlite3_column_int(aStmt, 0);
			rental_number = (int)sqlite3_column_int(aStmt, 1);
		}
		else {
			aOutput = "Error in Rental --- No Book Id";
			return 0;
		}
	}

	if(is_rental != 0) {
		aOutput = "Fail to Rental --- This Book is rentaled";
		return 0;
	}

	// write MemberID & RentalDate & ReturnDate & Rentalnumber in Book
	temp = "update book set rentalid=";
	temp.append(member_id);
	temp.append(", rentaldate=");
	temp.append(to_string(aToday));
	temp.append(", returndate=");
	temp.append(to_string(CalculateDate(aToday, rental_period)));
	temp.append(", rentalnumber=");
	temp.append(to_string(rental_number+1));
	temp.append(" where id=");
	temp.append(book_id);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Error in Rental --- Unkowm Reason";
		return 0;
	}
	else {
		sqlite3_step(aStmt);
	}

	// write RentalCurrent in Member
	temp = "update member set bookrentalcurrent=";
	temp.append( to_string(rental_current+1) );
	temp.append(" where id=");
	temp.append(member_id);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Error in Rental --- Unkowm Reason";
		return 0;
	}
	else {
		sqlite3_step(aStmt);
	}

	aOutput = "Success to Rental: return date is ";
	aOutput.append(to_string(CalculateDate(aToday, rental_period)));
	return 0;
}

/*
	@brief : return a book by a member
			it check book ID & member ID
				book is rentaled
				member has rentaled
	@param : <id>|<bookid>
*/
int DBinterface:: Return(string buffer)
{
	int 	pos;
	string 	member_id;
	string 	book_id;
	int 	rental_id;
	int 	rental_current;
	string 	temp;
	int 	ret;

	pos = buffer.find('|');
	if(pos == string::npos) {
		aOutput = "Fail to Return --- Wrong Input";
		return 0;
	}
	else {
		book_id = buffer.substr(pos+1, string::npos);
		member_id = buffer.substr(0, pos);
	}

	temp = "select rentalid from book where id =";
	temp.append(book_id);
	
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Error in Return --- Wrong Book Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret == SQLITE_ROW) {
			rental_id = (int)sqlite3_column_int(aStmt, 0);
		}
		else {
			aOutput = "Error in Rental --- No Book Id";
			return 0;
		}
	}

	if(rental_id == 0) {
		aOutput = "Fail to Return --- This book is not rentaled";
		return 0;
	}
	else if(rental_id != stoi(member_id)) {
		aOutput = "Fail to Return --- This book is rentaled by another";
		return 0;
	}

	temp = "select bookrentalcurrent from member where id =";
	temp.append(member_id);
	
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Error in Return --- Wrong Member Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret == SQLITE_ROW) {
			rental_current = (int)sqlite3_column_int(aStmt, 0);
		}
		else {
			aOutput = "Error in Return --- No Member Id";
			return 0;
		}
	}
	
	// reset is_Rental in Book
	temp = "update book set rentalid=0 where id=";
	temp.append(book_id);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Error in Return --- Unkowm Reason";
		return 0;
	}
	else {
		sqlite3_step(aStmt);
	}

	// write RentalCurrent in Member
	temp = "update member set bookrentalcurrent=";
	temp.append(to_string(rental_current-1));
	temp.append(" where id=");
	temp.append(member_id);
	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Error in Return --- Unkowm Reason";
		return 0;
	}
	else {
		sqlite3_step(aStmt);
	}

	aOutput = "Success to Return";
	return 0;
}
/*
	@brief : update a member's data
			name, phone, email, address
	@param : Q<id>|<newvalue>
			Q : (N)ame, (P)hone, (E)mail, (A)ddress
*/
int DBinterface:: UpdateMember(string buffer)
{
	char 	column[2];
	int 	pos;
	string 	member_id;
	string 	new_value;
	string 	temp;
	int 	ret;

	buffer.copy(column, 1);
	column[1] = '\0';

	buffer.erase(0,2);

	pos = buffer.find("|");
	member_id = buffer.substr(0, pos);
	new_value = buffer.substr(pos+1, string::npos);

	temp = "select id from member where id =";
	temp.append(member_id);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Update --- Wrong Member Id";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if (ret != SQLITE_ROW) {
			aOutput = "Fail to Update --- No Member Id";
			return 0;
		}
	}

	temp = "update member set ";
	if(!strcmp(column, "N")) {
		temp.append("name=");
	}
	else if(!strcmp(column, "P")) {
		temp.append("phone=");
	}
	else if(!strcmp(column, "E")) {
		temp.append("email=");
	}
	else if(!strcmp(column, "A")) {
		temp.append("address=");
	}
	else {
		aOutput = "Fail to Update --- Wrong category";
		return 0;
	}

	temp.append(new_value);
	temp.append(" where id=");
	temp.append(member_id);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	if (ret != SQLITE_OK) {
		aOutput = "Error in Update --- Wrong Input";
		return 0;
	}
	else {
		sqlite3_step(aStmt);
	}
	aOutput = "Success to Update";
	return 0;
}

int DBinterface:: InsertMedia(string buffer)
{
	int 	pos;
	string 	temp;
	string 	media_id;
	int 	ret;

	pos = buffer.find('|');
	media_id = buffer.substr(0, pos);

	temp = "select id from multimedia where id =";
	temp.append(media_id);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	
	if (ret != SQLITE_OK) {
		aOutput = "Fail to Insert --- ID is Wrong Format";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if ((int)sqlite3_column_int(aStmt, 0) != 0) {
			aOutput = "Fail to Insert --- ID is already exist";
			return 0;
		}
	}

	temp = "insert into multimedia(id, name, writer, "
		"publisher, publicationdate, category) values(";
	temp.append(buffer);
	temp.append(")");

	while (1) {
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Insert --- Wrong Input";
		return 0;
	}

	sqlite3_step(aStmt);
	aOutput = "Success to Insert!";
	return 0;
}

int DBinterface:: SearchMedia(string buffer)
{
	int 	ret;
	int 	pos;
	int 	columns;
	int	count;
	string 	temp;

	count	= 0;

	temp = "select * from multimedia where ";
	temp.append(buffer);
	aOutput.clear();

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Search --- Wrong Input";
	    	return 0;
	}

  	columns = sqlite3_column_count(aStmt);

  	for (int col = 0; col < columns; col++) {
    		aOutput.append(sqlite3_column_name(aStmt, col));
    		aOutput.append(" | ");
  	}
  	aOutput.append("\n");
   
  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
			count++;
			for (int col = 0; col < columns; col++) {
				switch (sqlite3_column_type(aStmt, col)) {
					case SQLITE_INTEGER:
						aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
						aOutput.append("  ");
						break;
					case SQLITE_TEXT:
						aOutput.append((const char *)sqlite3_column_text(aStmt, col));
						aOutput.append("  ");
						break;
				}
			}
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
	    	aOutput.append("\n");
  	}

	if (count == 0) {
		aOutput = "No Multimedia in This Condition";
	}

	return 0;
}

int DBinterface:: DeleteMedia(string buffer)
{
	string 	temp;
	int 	ret;

	temp = "delete from multimedia where id=";
	temp.append(buffer);

	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Delete!";
		return 0;
	}

	sqlite3_step(aStmt);
	
	aOutput = "Success to Delete!";
	return 0;
}

int DBinterface:: InsertPaper(string buffer)
{
	int 	pos;
	string 	temp;
	string 	paper_id;
	int 	ret;

	pos = buffer.find('|');
	paper_id = buffer.substr(0, pos);

	temp = "select id from paper where id =";
	temp.append(paper_id);

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);
	
	if (ret != SQLITE_OK) {
		aOutput = "Fail to Insert --- ID is Wrong Format";
		return 0;
	}
	else {
		ret = sqlite3_step(aStmt);
		if ((int)sqlite3_column_int(aStmt, 0) != 0) {
			aOutput = "Fail to Insert --- ID is already exist";
			return 0;
		}
	}

	temp = "insert into paper(id, name, writer, "
		"publicationdate, project) values(";
	temp.append(buffer);
	temp.append(")");

	while (1) {
		pos = temp.find('|');
		if(pos == string::npos) break;
		temp.replace(pos,1,",");
	}

	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Insert --- Wrong Input";
		return 0;
	}

	sqlite3_step(aStmt);
	aOutput = "Success to Insert!";
	return 0;
}

int DBinterface:: SearchPaper(string buffer)
{
	int 	ret;
	int 	pos;
	int 	columns;
	int	count;
	string 	temp;

	count	= 0;

	temp = "select * from paper where ";
	temp.append(buffer);
	aOutput.clear();

	ret = sqlite3_prepare_v2(aDB, temp.c_str(), -1, &aStmt, NULL);

	if (ret != SQLITE_OK) {
		aOutput = "Fail to Search --- Wrong Input";
	    	return 0;
	}

  	columns = sqlite3_column_count(aStmt);

  	for (int col = 0; col < columns; col++) {
    		aOutput.append(sqlite3_column_name(aStmt, col));
    		aOutput.append(" | ");
  	}
  	aOutput.append("\n");
   
  	while (true) {
	    	ret = sqlite3_step(aStmt);
	    	if (ret == SQLITE_ROW) {
			count++;
			for (int col = 0; col < columns; col++) {
				switch (sqlite3_column_type(aStmt, col)) {
					case SQLITE_INTEGER:
						aOutput.append(to_string(sqlite3_column_int(aStmt, col)));
						aOutput.append("  ");
						break;
					case SQLITE_TEXT:
						aOutput.append((const char *)sqlite3_column_text(aStmt, col));
						aOutput.append("  ");
						break;
				}
			}
	    	} else if (ret == SQLITE_DONE) {
	      		break;
	    	} else {
	      		break;
	    	}
	    	aOutput.append("\n");
  	}

	if (count == 0) {
		aOutput = "No Paper in This Condition";
	}

	return 0;
}

int DBinterface:: DeletePaper(string buffer)
{
	string 	temp;
	int 	ret;

	temp = "delete from multimedia where id=";
	temp.append(buffer);

	if (sqlite3_prepare(aDB, temp.c_str(), -1, &aStmt, NULL) != SQLITE_OK) {
		aOutput = "Fail to Delete!";
		return 0;
	}

	sqlite3_step(aStmt);
	
	aOutput = "Success to Delete!";
	return 0;
}

string DBinterface:: GetOutput()
{
	return aOutput;
}

void DBinterface:: SetOutput(string buffer)
{
	aOutput = buffer;
}

void DBinterface:: SetToday(int value)
{
	aToday = value;
}

/*
	@brief : calculate return date
			using today & rental period
	@param : aToday of DBinterface, rental period of member 
	@return : date
			ex) 20160529
*/
int CalculateDate (int CurrentDate, int period)
{
	int Year = CurrentDate/10000;
	int Month = (CurrentDate%10000)/100;
	int Day = CurrentDate%100;
//	ASSERT(Month<=12);
//	ASSERT(Day<=31);

	Day+=period;
	switch(Month)
	{
		case 1:
			{
				if(Day>31){
					Day-=31;
					Month=2;
				}
			}
			break;
		case 2:
			{
				if(!(Year%400)){
					if(Day>29){
						Day-=29;
						Month=3;
					}
				}else if(!(Year%100)){
					if(Day>28){
						Day-=28;
						Month=3;
					}
				}else if(!(Year%4)){
					if(Day>29){
						Day-=29;
						Month=3;
					}
				}else{
					if(Day>28){
						Day-=28;
						Month=3;
					}
				}
			}
			break;
		case 3:
			{
				if(Day>31){
					Day-=31;
					Month=4;
				}
			}
			break;
		case 4:
			{
				if(Day>30){
					Day-=30;
					Month=5;
				}
			}
			break;
		case 5:
			{
				if(Day>31){
					Day-=31;
					Month=6;
				}
			}
			break;
		case 6:
			{
				if(Day>30){
					Day-=30;
					Month=7;
				}
			}
			break;
		case 7:
			{
				if(Day>31){
					Day-=31;
					Month=8;
				}
			}
			break;
		case 8:
			{
				if(Day>31){
					Day-=31;
					Month=9;
				}
			}
			break;
		case 9:
			{
				if(Day>30){
					Day-=30;
					Month=10;
				}
			}
			break;
		case 10:
			{
				if(Day>31){
					Day-=31;
					Month=11;
				}
				
			}
			break;
		case 11:
			{
				if(Day>30){
					Day-=30;
					Month=12;
				}
			}
			break;
		case 12:
			{
				if(Day>31){
					Day-=31;
					Month=1;
					Year++;
				}
			}
			break;
		default:
			{
			}
			break;
	}
	return ((Year*10000)+(Month*100)+Day);
}


