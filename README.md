# Project3

2011312409 Jeong Jinsu
2011311541 Kim Taeho


This is SW Experiment 3 course's 3rd Project

********************Protocol*********************

Rental_:<UserID>|<ID>   //ex) Rental_:15,12
  >OK
  >Fail : <Reason>
Return_:<UserID>|<ID>
  >OK
InsertB:<ID>|<Name>|<Writer>|<Publisher>|<PublicationDate>|<Categoty>|<Page>|<ISBN>
  >OK
  >Fail : <Reason> (Reason: ID가 겹쳤을 때)
InsertM:<Name>|<Phone>|<Email>|<Address>|<Grade>
  >OK : <UserID>
  >Fail : <Reason> (Reason: 폰번이 겹쳤을 때)
DeleteB:<ID>
  >OK
  >Fail : <Reason>
DeleteM:<UserID>
  >OK
  >Fail : <Reason>
SearchB:<조건>
  >Proper String //<ID> <Name> <Writer> <Publisher>..같은 형식으로 띄워쓰기로 구분하고 한권에 한줄
  >Fail : <Reason>
SearchM:<조건>
  >Proper String
  >Fail : <Reason>
UpdateB: 없음
UpdateM:N|<ID>|<NewName>
UpdateM:P|<ID>|<NewPhone>
UpdateM:E|<ID>|<NewEmail>
UpdateM:A|<ID>|<NewAddr>
  >OK
  >Fail : <Reason> (ID가 없다거나)
UpGrade:<ID>
  >OK
  >Fail : <Reason> (이미 최고 등급일때?)

InsertR:<BookName>|<Grade>|<Review>
  >OK
  >Fail : <Reason> 
GetRevB:<BookName> (그 책이름에 대해 Review다 줘요)
  >Proper String
  >No Review
GetArgB:<BookName> (그 책이름에 대해 Grade평균을 줘요)
  >Average : <average>
  >No Review
GetRank:NULL
  >Proper String



Book(           //Use _ instead ' '; ex) Book name : C++ Library (X) C++_Library
int           ID              //Server에서만 관리
varchar[100]  Name
varchar[50]   Writer
varchar[50]   Publisher
int           PublicationDate //ex)20090205
varchar[50]  Category
int           Page
varchar[16]   ISBN

int           RentalID
int           RentalDate
int           ReturnDate
int           RentalNumber  //몇번이나 대출되었는지
)

Review(
varchar[100]  BookName
int           Grade
varchar[100]  review
)

Member(
int           ID     
varchar[50]   Name
varchar[11]   Phone
varchar[50]   Email
varchar[100]  Address
int           Grade               //회원등급 1~5
int           BookRentalPeriod    //몇일동안?
int           BookRentalLimit     //몇권이나?
int           BookRentalCurrent   //몇권빌리고 있냐
)
