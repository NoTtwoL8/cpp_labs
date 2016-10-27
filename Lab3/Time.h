#pragma once


#ifndef TIME_H
#define TIME_H


using namespace std;

class Time
{
private:
	int hours;
	int minutes;

public:
	Time()
	{
		hours = 12;
		minutes = 01;
	}
	void SetTime(int hr, int min);
	void SetHour(int hr);
	void SetMinute(int min);
	int GetHour() const;
	int GetMinute() const;
	void PrintTime();


};
#endif