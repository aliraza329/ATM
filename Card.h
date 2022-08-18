#pragma once
#include<iostream>
using namespace std;
class Card
{
private:
	int cardnum;
	int pin;
public:
	//constructors
	Card();
	Card(int, int);
	Card(const Card&);
	friend ostream& operator<<(ostream&, Card&);
	friend istream& operator>>(istream&, Card&);
	//setter and getters
	void SetCardNumber(int);
	void SetPin(int);
	int GetCardNumber();
	int GetPin();
	//randomly generate card number.
	void GenerateCardNumber();
	//display function
	void Display();
	//destructor
	~Card();
};

