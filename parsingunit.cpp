#include "parsingunit.h"

int ParsingUnit:: Open(DBinterface *NewDB)
{
	DB = NewDB;
}

int ParsingUnit:: Input(string buffer)
{
	char 	temp[8];

	buffer.copy(temp, 7);
	temp[7] = '\0';

	buffer.erase(0,8);

	if(!strcmp(temp, "InsertB")){
		DB->InsertBook(buffer);
	}
	else if(!strcmp(temp, "SearchB")){
		DB->SearchBook(buffer);
	}
	else if(!strcmp(temp, "InsertR")){
		DB->InsertReview(buffer);
	}
	else if(!strcmp(temp, "InsertM")){
		DB->InsertMember(buffer);
	}
	else if(!strcmp(temp, "SearchM")){
		DB->SearchMember(buffer);
	}
	else if(!strcmp(temp, "GetRevB")){
		DB->SearchReview(buffer);
	}
	else if(!strcmp(temp, "GetArgB")){
		DB->GetAvgReview(buffer);
	}
	else if(!strcmp(temp, "DeleteB")){
		DB->DeleteBook(buffer);
	}
	else if(!strcmp(temp, "DeleteM")){
		DB->DeleteMember(buffer);
	}
	else if(!strcmp(temp, "GetRank")){
		DB->GetRank();
	}
	else if(!strcmp(temp, "UpGrade")){
		DB->Upgrade(buffer);
	}
	else if(!strcmp(temp, "Rental_")){
		DB->Rental(buffer);
	}
	else if(!strcmp(temp, "Return_")){
		DB->Return(buffer);
	}
	else if(!strcmp(temp, "UpdateM")){
		DB->UpdateMember(buffer);
	}
	else if(!strcmp(temp, "InsertD")){
		DB->InsertMedia(buffer);
	}
	else if(!strcmp(temp, "SearchD")){
		DB->SearchMedia(buffer);
	}
	else if(!strcmp(temp, "DeleteD")){
		DB->DeleteMedia(buffer);
	}
	else if(!strcmp(temp, "InsertP")){
		DB->InsertPaper(buffer);
	}
	else if(!strcmp(temp, "SearchP")){
		DB->SearchPaper(buffer);
	}
	else if(!strcmp(temp, "DeleteP")){
		DB->DeletePaper(buffer);
	}
	
	else{
		DB->SetOutput("Error: Wrong Protocol!");
	}
	return 0;
}
