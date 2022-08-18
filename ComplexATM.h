#pragma once
#include "Atm.h"
#include <iostream>
using namespace std;
class ComplexATM: public Atm
{
public:
	ComplexATM();
	ComplexATM(User&);
	void operator-();
	void operator*();
	void operator%(int);
	void operator^(int);
	void ChangePin(User&);
	void Transfer(User&);
	void BalanceInquery(User&);
	void Withdraw(User&);
	void DisplayInfo(User&);
	void Display(User&);
	void Menu();
};

