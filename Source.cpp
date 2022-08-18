#include <iostream>
#include "User.h"
#include "BasicATM.h"
#include "ComplexATM.h"
#include "Atm.h"
using namespace std;
int main()
{
	User u1;
	User u2;
	User u3;
	cout << "Enter Data of !st User: " << endl;
	cin >> u1;
	cout << u1;
	/*cout << "Enter Data of 2nd User: " << endl;
	cin >> u2;
	cout << "Enter Data of 3rd User: " << endl;
	cin >> u3;*/
	/*BasicATM B1(u1);*/
	ComplexATM c1(u1);
	




	return 0;
}