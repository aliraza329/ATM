#include "User.h"
#include <iostream>
using namespace std;

User::User()
{
	name = nullptr;
	address = nullptr;
	phonenum = 0;
	type = '\0';
}
User::User(User& obj)
{
	Strcopy(name, obj.name);
	Strcopy(address, obj.address);
	phonenum = obj.phonenum;
	type = obj.type;
}
istream& operator>>(istream& Cin, User& u)
{
	u.name = new char[50];
	cout << "Enter your Name: ";
	Cin.getline( u.name,50);
	u.address = new char[100];
	cout << "Enter Your Address: ";
	Cin.getline(u.address, 100);
	cout << "Enter Your Phone Number: ";
	Cin >> u.phonenum;

	char choice = '\0';
	cout << "Select Account Type: " << endl;
	cout << "Press S/s for Saving Account " << endl;
	cout << "Press C/c for Checking Account " << endl;
	cout << "Choice: ";
	Cin >> choice;
	u.SetType(choice);

	if (choice == 's' || choice == 'S') {
		Cin >> u.saving;
		Cin >> u.card;
	}
	else if (choice == 'c' || choice == 'C')
	{
		Cin >> u.checking;
		Cin >> u.card;
	}
	else {
		cout << "Invalid Account Type." << endl;
	}

	return Cin;
}
ostream& operator<<(ostream& Cout, User& u)
{
	Cout << endl;
	Cout << "Your name: " << u.GetName() << endl;
	Cout << "Your Address: " << u.GetAddress() << endl;
	Cout << "Your Phone Number: " << u.GetPhoneNumber() << endl;
	if (u.GetType() == 's' || u.GetType() == 'S')
	{
		Cout << u.saving;
		Cout << u.card;
	}
	if (u.GetType() == 'c' || u.GetType() == 'C') {
		Cout << u.checking;
		Cout << u.card;
	}
	Cout << endl;
	return Cout;
}
void User::SetName(char* n)
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
	Strcopy(name, n);
}
void User::SetAddress(char* a)
{
	if (address)
	{
		delete[] address;
		address = nullptr;
	}
	Strcopy(address, a);
}
void User::SetPhoneNumber(int p)
{
	phonenum = p;
}
void User::SetType(char c)
{
	type = c;
}
char* User::GetName()
{
	char* temp = new char[Strlen(name) + 1];
	Strcopy(temp, name);
	return temp;
}
char* User::GetAddress()
{
	char* temp = new char[Strlen(address) + 1];
	Strcopy(temp, address);
	return temp;
}
int User::GetPhoneNumber()
{
	return phonenum;
}
char User::GetType()
{
	return type;
}
void User::Display()
{
	cout << "User name: " << name << endl;
	cout << "User Address: " << address << endl;
	cout << "User Phone Number: " << phonenum << endl;
	cout << endl;
}
User::~User()
{
	/*delete[] name;
	name = nullptr;
	delete[] address;
	address = nullptr;
	phonenum = 0;
	type = '\0';*/
}