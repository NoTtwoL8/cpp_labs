

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool IsValidPassword(string);


int main() {

	/*test length 6 characters, at least one uppercase and at least one lowercase letter, at least one digit*/
	
	string password;

	cout << "Please enter a password at least 6 characters long, with at least 1 lowercase, 1 uppercase, and 1 digit. " << endl;
	cin >> password;
	
	IsValidPassword(password);

	return 0;
}

bool lengthVal(string s)
{
	
	bool length = false;
	if (s.length() >= 6) {
		length = true;
	}
	else {
		length = false;
	}

	return length;
}

bool upperVal(string s)
{
	
	bool upper = false;
	for (int x = 0; x < s.length(); x++) {
		if (isupper(s[x])) {
			upper = true;			
		}		
	}

	return upper;
}

bool lowerVal(string s)
{
	
	bool lower = false;
	for (int x = 0; x < s.length(); x++) {
		if (islower(s[x])) {
			lower = true;			
		}
	}

	return lower;
}

bool digitVal(string s)
{
	
	bool digit = false;
	for (int x = 0; x < s.length(); x++) {
		if (isdigit(s[x])) {
			digit = true;			
		}
	}

	return digit;
}

bool IsValidPassword(string s)
{
	
	bool pw = false, length, upper, lower, digit ;

	length = lengthVal(s);
	upper = upperVal(s);
	lower = lowerVal(s);
	digit = digitVal(s);

	if ((upper && lower) && (digit && length)) {
		
		pw = true;
		cout << "\nPassword works\n";
	}

	else {
		if (upper < 1)
			cout << "\nPassword needs an uppercase letter" << endl;
		if (lower < 1)
			cout << "\nPassword needs a lowercase letter" << endl;
		if (digit < 1)
			cout << "\nPassword needs a digit" << endl;
		if (length < 1)
			cout << "\nMust be at least 6 characters long" <<endl;
	}

	return pw;
}


