#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
	cout << "Please enter the month, day and year in the format (MM/DD/YYYY): ";
	string s = "";	
	cin >> s;
	if(s.size() != 10){
		cout << "That is an invalid input" << endl;
		return 0;
	}
	char charArr[10];
	strcpy(charArr, s.c_str());
	
	int daysInMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int daysInMonthLeap[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	
	int month = ((int)charArr[1]) - 48;
	month += (((int)charArr[0]) - 48) * 10;
	
	int day = ((int)charArr[4]) - 48;
	day += (((int)charArr[3]) - 48) * 10;
	
	int year = ((int)charArr[9]) - 48;
	year += (((int)charArr[8]) - 48) * 10;
	year += (((int)charArr[7]) - 48) * 100;
	year += (((int)charArr[6]) - 48) * 1000;
	
	int output = 0;
	if(year % 4 == 0){
		for(int i = 1; i < month; i++)
			output += daysInMonthLeap[i];
		output += day;
	}
	else{
		for(int i = 1; i < month; i++)
			output += daysInMonth[i];
		output += day;
	}
	
	cout << endl << "The Julian Calendar day is: " << output;
}
