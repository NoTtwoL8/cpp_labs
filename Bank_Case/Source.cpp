#include <iostream>
#include <cctype>
#include <iomanip>
#include "BankAccount.h"

using namespace std;

//Function Prototypes
void withdraw(BankAccount &);
void makeDeposit(BankAccount &);
void displayMenu();


int main() {
	BankAccount Savings;
	char choice;

	do
	{
		displayMenu();
		cin >> choice;
		while (toupper(choice) < 'A' || toupper(choice) > 'G')
		{
			cout << "Please make a choice in the range of A - G: ";
			cin >> choice;
		}
		switch (tolower(choice)) {
		case 'a':
			cout << "Your accout balance is: $" << Savings.getBalance() << endl;
			break;
		case 'b':
			cout << "The number of transactions for this period was: $" << Savings.getTransaction() << endl;
			break;
		case 'c':
			cout << "The interest earned this period: $" << Savings.getInterest();
			break;
		case 'd':
			makeDeposit(Savings);
			break;
		case 'e':
			withdraw(Savings);
			break;
		case 'f':
			Savings.calcInterest();
			cout << "Interest added.\n";
		}
	} while (tolower(choice) != 'g');



	return 0;
}


//Displays the users menu upon logging into the system
void displayMenu() {
	cout << "\n               Menu\n";
	cout << "A) Display the account balance\n";
	cout << "B) Display the number of transactions\n";
	cout << "C) Displayed interest earned this period\n";
	cout << "D) Make a deposit\n";
	cout << "E) Make a withdrawal\n";
	cout << "F) Add interest for this period\n";
	cout << "G) Exit the program\n\n";
	cout << "Enter your choice: ";
}

void makeDeposit(BankAccount &deposit) {
	double dollar;
	cout << "How much would you like to deposit?";
	cin >> dollar;
	cin.ignore();
	deposit.makeDeposit(dollar);
}

void withdraw(BankAccount &withdraw) {
	double dollar;
	cout << "How much would you like to withdraw?";
	cin >> dollar;
	cin.ignore();
	if (!withdraw.withDraw(dollar))
		cout << "Insufficient Funds.\n\n";
}

