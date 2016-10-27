

#include <iostream>
#include "Time.h"
#include <cassert>

using namespace std;

int main() {
	Time today;
	
	today.SetHour(16);
	today.SetMinute(1);
	today.PrintTime();
	today.SetHour(0);
	today.SetMinute(9);
	today.PrintTime();
	today.SetHour(12);
	today.SetMinute(1);
	today.PrintTime();

	// today.PrintTime();

	return 0;





}