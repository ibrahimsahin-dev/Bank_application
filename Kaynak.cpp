#include <iostream>
using namespace std;
#include "bank.h"
#include <string>
#include <cstdlib>




int main()
{

	investmentAccount user[3];
	string Name, Surname;
	int pin = 0;

	user[0].setName("soner");
	user[0].setSurname("aydinlik");
	user[0].setPin(123);
	user[0].setBalance(1000000);

	user[1].setName("beytullah");
	user[1].setSurname("turan");
	user[1].setPin(3461);
	user[1].setBalance(1000);

	user[2].setName("ibrahim");
	user[2].setSurname("sahin");
	user[2].setPin(3455);
	user[2].setBalance(1000);
	cout << "\t\tDogus Bank\t" << endl;
	cout << "Please Enter Name:   ";
	cin >> Name;
	cout << "Please Enter SurName:   ";
	cin >> Surname;
	cout << "Please Enter Your Pin:   ";
	cin >> pin;

	for (int i = 0; i < 3; i++)
	{
		if (Name == user[i].name && Surname == user[i].surname && pin == user[i].password)
		{
			system("cls");
			int choice = 0;
			cout << "[1] Customer Information " << endl;
			cout << "[2] Deposit" << endl;
			cout << "[3] Withdraw " << endl;
			cout << "[4] Learn credit limit " << endl;
			cout << "[5] Stock " << endl;
			cout << "[6] Currency" << endl;
			cout << "[0] EXIT" << endl << endl;

			cout << "Please make a choice" << endl;
			cin >> choice;
			while (choice != 0)
			{
				switch (choice)
				{
				case 1:user[i].showinformations();
					cin >> choice;
					break;
				case 2: user[i].Deposit();
					cin >> choice;
					break;
				case 3: user[i].withdraw();
					cin >> choice;
					break;
				case 4: user[i].learnLimit();
					cin >> choice;
					break;
				case 5: 
					user[i].menustocks();
					system("cls");
					cout << "[1] Customer Information " << endl;
					cout << "[2] Deposit" << endl;
					cout << "[3] Withdraw " << endl;
					cout << "[4] Learn credit limit " << endl;
					cout << "[5] Stock " << endl;
					cout << "[6] Buying Currency" << endl;
					cout << "[0] EXIT" << endl << endl;
					cout << "Please make a choice" << endl;
					cin >> choice;
					break;
				case 6:
					user[i].menucurrency();
					system("cls");
					cout << "[1] Customer Information " << endl;
					cout << "[2] Deposit" << endl;
					cout << "[3] Withdraw " << endl;
					cout << "[4] Learn credit limit " << endl;
					cout << "[5] Stock " << endl;
					cout << "[6] Buying Currency" << endl;
					cout << "[0] EXIT" << endl << endl;
					cout << "Please make a choice" << endl;
					cin >> choice;
					break;
				default: cout << "you made a mistake"<<endl;
					cin >> choice;
					break;
				}
			}
		}
	}
		




	return 0;
}



