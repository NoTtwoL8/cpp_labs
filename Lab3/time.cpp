
#include <iostream>
#include <string>
#include "Time.h"
#include <iomanip>


using namespace std;

void Time::SetTime(int hr, int min) {
	hours = hr;
	minutes = min;
}

void Time::SetHour(int hr) {
	
	do {
		if (hr < 24 && hr >= 0)
			hours = hr;
		else {
			cout << "Hours must be from 0 to 23...  Please try again: " << endl;
			cin >> hr;			
		}
	} while (hr > 23 || hr < 0);
	hours = hr;
}

void Time::SetMinute(int min) {
	do {
		if (min < 60 && min >= 0)
			minutes = min;
		else {
			cout << "Minutes must be from 00 to 59...  Please try again: " << endl;
			cin >> min;
		}
	} while (min > 59 || min < 0);

	minutes = min;
}
int Time::GetHour() const
{
	return hours;
}
int Time::GetMinute() const
{
	return minutes;
}
void Time::PrintTime() {
	
	if (hours > 12) {
		cout << setw(2) << setfill('0') << (hours - 12) << ":" << setw(2) << setfill('0') << minutes << "pm" << endl;
	}
	else
		cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << "am" << endl;
}







