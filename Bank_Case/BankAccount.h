#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
private:
	double balance;
	double interestRate;
	double interest;
	int	   transactions;
public:
	BankAccount(double bal = 0.00, double intRate = 0.045)
	{
		interest = 0.00;
		balance = bal;
		interestRate = intRate;
		transactions = 0;
	}
	void setInterestRate(double intRate)
	{
		interestRate = intRate;
	}

	void makeDeposit(double deposit)
	{
		balance += deposit;
		transactions++;
	}

	bool withDraw(double withDrawal)
	{
		if (withDrawal > balance) {
			return false;
		}
		else {
			balance -= withDrawal;
			transactions++;
			return true;
		}
	}
	void calcInterest() 
	{
		interest = interestRate * balance;
		balance += interest;		
	}
	double getInterestRate() const
	{
		return interestRate;
	}
	double getBalance() const
	{
		return balance;
	}
	double getInterest() const
	{
		return interest;
	}
	int getTransaction() const
	{
		return transactions;
	}

};
#endif