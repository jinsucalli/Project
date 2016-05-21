# Project3

2011312409 Jeong Jinsu
2011311541 Kim Taeho


This is SW Experiment 3 course's 3rd Project

Book(
int           ID              //Server에서만 관리
varchar[100]  Name
varchar[50]   Writer
varchar[50]   Publisher
int           PublicationDate //ex)20090205
varchar[50]   Group
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
