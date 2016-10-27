
#include <iostream>
#include <string>
#include "Time.h"


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
			cout << "Hours must be from 1 to 24...  Please try again: " << endl;
			cin >> hr;			
		}
	} while (hr > 23 || hr < 0);
	
}

void Time::SetMinute(int min) {
	if (min < 60 && min > 0)
		minutes = min;
	else
		cout << "Minutes must be from 0 to 59..." << endl;
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
		cout << (hours - 12) << ":" << minutes << "pm" << endl;
	}
	else
		cout << hours << ":" << minutes << "am" << endl;
}







