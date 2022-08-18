#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount() :BankAccount()
{
	fee = 0, 0;
}
CheckingAccount::CheckingAccount(float f, char* n, char* b, float c) :BankAccount(n, b, c)
{
	fee = f;
}
CheckingAccount::CheckingAccount(CheckingAccount& obj) :BankAccount(obj)
{
	fee = obj.fee;
}
ostream& operator<<(ostream& Cout, CheckingAccount& c)
{
	c.BankAccount::Display();
	Cout << "Fee: " << c.GetFee() << " PKR" << endl;
	Cout << endl;
	return Cout;
}
istream& operator>>(istream& Cin, CheckingAccount& c)
{
	char* name = new char[50];
	cout << "Enter Bank Name: ";
	Cin >> name;
	c.SetBankName(name);
	char* branch = new char[50];
	cout << "Enter Bank Branch: ";
	Cin.ignore();
	Cin.getline(branch, 50);
	c.SetBankBranch(branch);
	float bal = 0.0;
	cout << "Enter Amount You Want to Add: ";
	Cin >> bal;
	c.SetCash(bal);
	c.SetFee(25);

	return Cin;
}
void CheckingAccount::SetFee(float f)
{
	fee = f;
}
float CheckingAccount::GetFee()
{
	return fee;
}
void CheckingAccount::Withdraw(float w)
{
	float balance = GetCash();
	if (balance > fee)
	{
		balance = balance - fee;
		if (balance > w)
		{
			balance = balance - w;
			SetCash(balance);
			cout << "Amount Withdrawn Successfully .." << endl;
		}
		else
		{
			SetCash(balance);
			cout << "==> Insufficient Balance <==" << endl;
		}
	}
}
void CheckingAccount::Deposit(float d)
{
	float balance = GetCash();
	if (balance > 0)
	{
		balance = balance - fee;
		balance = balance + d;
		SetCash(balance);
	}
	else
	{
		cout << "==> INVALID BALANCE <==" << endl;
	}
}
void CheckingAccount::Display()
{
	BankAccount::Display();
	cout << "Fee: " << fee <<" PKR" << endl;
	cout << endl;
}
CheckingAccount::~CheckingAccount()
{
	/*fee = 0.0;*/
}