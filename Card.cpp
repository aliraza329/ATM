#include "Card.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

Card::Card()
{
	cardnum = 0;
	pin = 0;
}
Card::Card(int c, int p)
{
	cardnum = c;
	pin = p;
}
Card::Card(const Card& obj)
{
	cardnum = obj.cardnum;
	pin = obj.pin;
}
ostream& operator<<(ostream& Cout, Card& c)
{
	Cout << "Your Card Number: " << c.GetCardNumber() << endl;
	Cout << "Your Pin: " << c.GetPin() << endl;

	return Cout;
}
istream& operator>>(istream& Cin, Card& c)
{
	c.GenerateCardNumber();
	int pin = 0;
	cout << "Enter Your Card Pin: ";
	Cin >> pin;
	c.SetPin(pin);

	return Cin;
}
void Card::SetCardNumber(int c)
{
	cardnum = c;
}
void Card::SetPin(int p)
{
	pin = p;
}
int Card::GetCardNumber()
{
	return cardnum;
}
int Card::GetPin()
{
	return pin;
}
void Card::GenerateCardNumber()
{
	srand(time(NULL));
	cardnum = 100000 + rand() % 1000000;
}
void Card::Display()
{
	cout << "Card Number: " << cardnum << endl;
	cout << "Pin: " << pin << endl;
}
Card::~Card()
{
	/*cardnum = 0;
	pin = 0;*/
}