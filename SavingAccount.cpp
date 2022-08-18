#include "SavingAccount.h"
#include <iostream>
using namespace std;

SavingAccount::SavingAccount():BankAccount()
{
	interest = 0.0;
}
SavingAccount::SavingAccount(float ir, char* n, char* b, float c) :BankAccount(n, b, c)
{
	interest = ir;
}
SavingAccount::SavingAccount(SavingAccount& obj) : BankAccount(obj)
{
	interest = obj.interest;
}
ostream& operator<<(ostream& Cout, SavingAccount& s)
{
	s.BankAccount::Display();
	Cout << "Interest Rate: " << s.GetInterestRate() << "%" << endl;
	Cout << endl;
	return Cout;
}
istream& operator>>(istream& Cin, SavingAccount& s)
{
	char* name = new char[50];
	cout << "Enter Bank Name: ";
	Cin >> name;
	Cin.ignore();
	s.SetBankName(name);
	char* branch = new char[50];
	cout << "Enter Bank Branch: ";
	Cin.getline(branch, 50);
	s.SetBankBranch(branch);
	float bal = 0.0;
	cout << "Enter Amount You Want to Add: ";
	Cin >> bal;
	s.SetCash(bal);
	s.SetInterestRate(5);

	return Cin;
}
void SavingAccount::SetInterestRate(float i)
{
	interest = i;
}
float SavingAccount::GetInterestRate()
{
	return interest;
}
float SavingAccount::CalculateInterest()
{
	float balance;
	balance = GetCash();
	float ir;
	float x;
	x = interest / 100;
	int t = 1;
	ir = balance * x * t;
	return ir;
}
void SavingAccount::Deposit(float d)
{
	float balance;
	balance = GetCash();
	balance = balance + d;
	float in = CalculateInterest();
	balance = balance - in;
	SetCash(balance);
}
void SavingAccount::Withdraw(float w)
{
	float balance = GetCash();
	float in = CalculateInterest();
	if (balance > w)
	{
		balance = balance - w;
		balance = balance - in;
		SetCash(balance);
		cout << "Amount Withdrawn Successfully .." << endl;
	}
	else
	{
		cout << "==> Insufficient Balance <==" << endl;
	}
}
void SavingAccount::Display()
{
	BankAccount::Display();
	cout << "Interest Rate: " << interest << "%" << endl;
	cout << endl;
}
SavingAccount::~SavingAccount()
{
	/*interest = 0.0;*/
}