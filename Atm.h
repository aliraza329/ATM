#pragma once
#include"User.h"
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
#include"Card.h"
class Atm
{
private:
	User u;
	int flag;
public:
	Atm();
	void CheckInput();
	bool Check();
	void SetUser(User&);
	User& GetUser();
	void Display();
};

