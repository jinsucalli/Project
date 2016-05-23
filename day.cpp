#include <iostream>

using namespace std;
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

int main(void)
{
	int day;
	while(1)
	{
	cin>>day;
	cout<<CalculateDate(day,5)<<endl;
	}
}
