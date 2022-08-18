#pragma once
#include"BankAccount.h"
#include <iostream>
using namespace std;
class CheckingAccount :public BankAccount
{
private:
	float fee;
public:
	CheckingAccount();
	CheckingAccount(float , char*, char* , float );
	CheckingAccount(CheckingAccount&);
	friend ostream& operator<<(ostream&, CheckingAccount&);
	friend istream& operator>>(istream&, CheckingAccount&);
	void SetFee(float f);
	float GetFee();
	void Withdraw(float);
	void Deposit(float);
	void Display();
	~CheckingAccount();
};

