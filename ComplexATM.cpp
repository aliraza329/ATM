#include "ComplexATM.h"
#include <iostream>
using namespace std;

ComplexATM::ComplexATM(){}
ComplexATM::ComplexATM(User& u)
{
	ComplexATM obj;
	SetUser(u);
	while (1) {
		Menu();
		int choice = 0;
		cout << "Your Choice? ";
		cin >> choice;
		if (choice == 1) {
			CheckInput();
			if (Check()) {
				cout << endl;
				-obj;
				Display(u);
				cout << endl;
			}
			else {
				cout << "Incorrect Details Entered!" << endl;
			}
		}
		else if (choice == 2) {
			CheckInput();
			cout << endl;
			*obj;
		}
		else if (choice == 3) {
			int temp = 0;
			CheckInput();
			cout << endl;
			obj %(temp);
		}
		else if (choice == 4) {
			int temp = 0;
			CheckInput();
			cout << endl;
			obj ^ (temp);
		}
		else if (choice == 5) {
			CheckInput();
			cout << endl;
			DisplayInfo(u);
			cout << endl;
		}
		else if (choice == 0) {
			cout << "Thanks For Using Atm." << endl;
			break;
		}
		else {
			cout << "Invalid Choice! " << endl;
			cout << endl;
		}
	}
}
void ComplexATM::Withdraw(User& u)
{
	float bal = 0.0;
	cout << "Enter Amount You Want to Withdraw: ";
	cin >> bal;
	if (u.GetType() == 'c' || u.GetType() == 'C')
	{
		u.checking.Withdraw(bal);
	}
	if (u.GetType() == 's' || u.GetType() == 'S')
	{
		u.saving.Withdraw(bal);
	}
}
void ComplexATM::Display(User& u)
{
	cout << " --> RECIEPT <-- " << endl;
	cout << "Date: 31/8/2021" << endl;
	cout << "Time: 12:00 pm" << endl;
	cout << "Machine Location: Lahore" << endl;
	if (u.GetType() == 'c' || u.GetType() == 'C') {
		cout << "Type: Checking" << endl;
	}
	else {
		cout << "Type: Saving" << endl;
	}
	cout << "Account Number: " << u.card.GetCardNumber() << endl;
	if (u.GetType() == 'c' || u.GetType() == 'C') {
		cout << "Remaining Balance: " << u.checking.GetCash() << endl;
		cout << "Withdrawl Fee: " << u.checking.GetFee() << " PKR" << endl;
	}
	else {
		cout << "Remaining Balance: " << u.saving.GetCash() << endl;
		cout << "Withdrawl Interest: " << u.saving.GetInterestRate() << "%" << endl;
	}
}
void ComplexATM::DisplayInfo(User& u)
{
	cout << endl;
	cout << " --> Details <-- " << endl;
	cout << "Account Number: " << u.card.GetCardNumber() << endl;
	cout << "Pin: ****" << endl;
	if (u.GetType() == 'c' || u.GetType() == 'C') {
		cout << "Balance: " << u.checking.GetCash() << endl;
	}
	else {
		cout << "Balance: " << u.saving.GetCash() << endl;
	}
}
void ComplexATM::BalanceInquery(User& u)
{
	if (u.GetType() == 'c' || u.GetType() == 'C') {
		cout << "Balance: " << u.checking.GetCash() << "PKR" << endl;
	}
	else {
		cout << "Balance: " << u.saving.GetCash() << "PKR" << endl;
	}
	cout << endl;
}
void ComplexATM::Transfer(User& u)
{
	int acc = 0;
	cout << "Enter Account Number Where You Want To Transfer Money: ";
	cin >> acc;
	float bal = 0;
	cout << "Enter Amount You Want to Send: ";
	cin >> bal;
	if (u.GetType() == 'c' || u.GetType() == 'C') {
		if (bal <= u.checking.GetCash())
		{
			float temp = 0;
			temp = u.checking.GetCash();
			temp -= bal;
			u.checking.SetCash(temp);
			cout << "Money Transferred Successfully .. " << endl;
			cout << "Remaining Balance: " << u.checking.GetCash() << "PKR " << endl;
		}
	}
	else {
		if (bal <= u.saving.GetCash())
		{
			float temp = 0;
			temp = u.saving.GetCash();
			temp -= bal;
			u.saving.SetCash(temp);
			cout << "Money Transferred Successfully .. " << endl;
			cout << "Remaining Balance: " << u.saving.GetCash() << "PKR " << endl;
		}
	}
}
void ComplexATM::ChangePin(User& u)
{
	int pin = 0;
	cout << "Enter New Pin: ";
	cin >> pin;
	int pin1 = 0;
	cout << "Confirm Your Pin: ";
	cin >> pin1;
	if (pin == pin1) {
		u.card.SetPin(pin);
		cout << "Pin Updated Successfully!" << endl;
	}
	else {
		cout << "Pin Not Matched .." << endl;
	}
}
void ComplexATM::Menu()
{
	cout << endl;
	cout << "Press 1 to withdrawal" << endl;
	cout << "Press 2 for balance inquiry" << endl;
	cout << "Press 3 to transfer money" << endl;
	cout << "Press 4 to change your PIN" << endl;
	cout << "Press 5 to display information" << endl;
	cout << "Press 0 to Exit" << endl;
	cout << endl;
}
void ComplexATM::operator-()
{
	Withdraw(GetUser());
}
void ComplexATM::operator*()
{
	BalanceInquery(GetUser());
}
void ComplexATM::operator%(int a)
{
	Transfer(GetUser());
}
void ComplexATM::operator^(int a)
{
	ChangePin(GetUser());
}