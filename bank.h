#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>



class Users {
public:
	Users();
	Users(string, string, int);
	string name = "";
	string surname = "";
	int password = 0;
	void setName(string newname);
	void setSurname(string newsurname);
	void setPin(int pin);

};

Users::Users()
{
	;
}
Users::Users(string name, string surname, int pin)
{
	this->name = name;
	this->surname = surname;
	password = pin;
}

void Users::setName(string newname)
{
	name = newname;
}

void Users::setSurname(string newsurname)
{
	surname = newsurname;
}

void Users::setPin(int pin)
{
	password = pin;
}

class bankAccount :public Users {
public:
	int number = 0;
	int creditpoint = 5;
public:
	double balance = 0;
	bankAccount(string, string, double, int);
	bankAccount();
	void setBalance(double newbalance);
	void setPhone(int newphone);
	string getName();
	string getSurname();
	double getBalance();
	int getPhone();
	void showinformations();
	void Deposit();
	void withdraw();
	void sendMoney(bankAccount&, float amount);
	void learnLimit();


};
bankAccount::bankAccount(string newname, string newsurname, double balance = 0, int number = 0)
{
	this->name = newname;
	this->surname = newsurname;
	this->balance = balance;
	this->number = number;
	cout << "Profile successfuly created" << endl;
}

bankAccount::bankAccount()
{
	;
}

void bankAccount::setBalance(double newbalance)
{
	balance = newbalance;
}

void bankAccount::setPhone(int newphone)
{
	number = newphone;
}

string bankAccount::getName()
{
	return name;
}
string bankAccount::getSurname()
{
	return surname;
}

int bankAccount::getPhone()
{
	return number;
}

double bankAccount::getBalance()
{
	return balance;
}


void bankAccount::showinformations()
{
	cout << "Name: " << name << endl << "Surname: " << surname << endl;
	cout << "Balance: " << balance << endl << "Phone number: " << number << endl << "Credit point: " << creditpoint << endl << endl;
}

void bankAccount::Deposit() {
	cout << "[2] Desposit " << endl;
	cout << "Please enter amount" << endl;

	int amount = 0;
	cin >> amount;
	while (amount <= 0) {
		cout << "Invalid amount! Please enter valid value:";
		cin >> amount;
	}
	balance += amount;
	creditpoint++;
	cout << "*****Your transaction is successful******" << endl;
	cout << "Your Balance:     " << balance << endl;
}

void bankAccount::withdraw() {
	cout << "[3] Withdraw " << endl;
	cout << "Please enter amount" << endl;
	int amount = 0;
	cin >> amount;
	while (amount <= 0 || amount > balance) {
		cout << "Invalid amount! Please enter valid value:";
		cin >> amount;
	}
	balance -= amount;
	creditpoint--;
	cout << "*****Your transaction is successful******" << endl;
	cout << "Your Balance:     " << balance << endl;
}


void bankAccount::sendMoney(bankAccount& obj, float amount)
{
	while (amount <= 0 || amount > balance) {
		cout << "Invalid amount! Please enter valid value:";
		cin >> amount;
	}
	obj.balance += amount;
	obj.creditpoint++;
	balance -= amount;
	creditpoint--;
}

void bankAccount::learnLimit()
{
	if (creditpoint <= 2)
		cout << "You have not any limit" << endl;
	else if (creditpoint > 2 && creditpoint <= 5)
	{
		cout << "You have 10 000 Turkish lira limit" << endl;
		cout << "Dou you want to take? Write yes or no " << endl;
		string acc;
		cin >> acc;
		if (acc == "yes")
		{
			cout << "Your transaction is succesfuly"<<endl;
			balance += 10000;
		}
		else
		{
			system("cls");
			cout << "[1] Customer Information " << endl;
			cout << "[2] Deposit" << endl;
			cout << "[3] Withdraw " << endl;
			cout << "[4] Learn credit limit " << endl;
			cout << "[5] Stock " << endl;
			cout << "[6] Buying Currency" << endl;
			cout << "[0] EXIT" << endl << endl;
			cout << "Please make a choice" << endl;
		}
	}
	else if (creditpoint > 5)
	{
		cout << "You have 20 000 Turkish lira limit" << endl;
		cout << "Dou you want to take? Write yes or no " << endl;
		string accept;
		cin >> accept;
		if (accept == "yes")
		{
			cout << "Your transaction is succesfuly" << endl;
			balance += 20000;
		}
		else
		{
			system("cls");
			cout << "[1] Customer Information " << endl;
			cout << "[2] Deposit" << endl;
			cout << "[3] Withdraw " << endl;
			cout << "[4] Learn credit limit " << endl;
			cout << "[5] Stock " << endl;
			cout << "[6] Buying Currency" << endl;
			cout << "[0] EXIT" << endl << endl;
			cout << "Please make a choice" << endl;
		}
	}


}

class investmentAccount : public bankAccount {
private:
	double dolar = 20.10;
	double euro = 21.86;
	double sterlin = 25.27;
	double x = 11.60;//Türkiye Ýþ Bankasý A.Þ. (ISCTR)
	double y = 49.00; // Aselsan Elektronik Sanayi ve Ticaret A.Þ. (ASELS)
	double z = 30.80;// Avrupa Yatýrým Holding A.Þ. (AVHOL)
	double currencyhesabi[3] = {};
	double hissehesabi[3] = {};
public:
	void showcurrency();
	void buycurrency();
	void sellcurrency();
	void showMycurrency();
	void showstocks();
	void buystocks();
	void showMyStocks();
	void sellstocks();
	void menustocks();
	void menucurrency();
};

void investmentAccount::showcurrency()
{
	cout << "\tLive Prices according to turkish lira" << endl;
	cout << "Dolar: " << dolar << endl;
	cout << "Euro: " << euro << endl;
	cout << "Sterlin: " << sterlin << endl;

}

void investmentAccount::buycurrency()
{
	double deneme = balance;
	cout << "Which currency do you want to buy? Write name of it: ";
	string cur;
	cin >> cur;
	while (cur != "dolar" && cur != "DOLAR" && cur != "euro" && cur != "EURO" && cur != "sterlin" && cur != "STERLIN")
	{
		cout << "Invalid code, try again: ";
		cin >> cur;
		if (cur == "dolar" || cur == "DOLAR" || cur == "euro" || cur == "EURO" || cur == "sterlin" || cur == "STERLIN")
			break;
	}
	cout << endl << "Avaible balance: " << balance << endl;
	cout << endl << "Avaible balance: " << deneme << endl;
	cout << "How much price do you want to buy: ";
	double exc;
	cin >> exc;

	if (exc <= 0 || exc > deneme)
		cout << "Invalid value or insufficient balance" << endl;

	else if (cur == "dolar" || cur == "DOLAR")
	{
		double a = exc / dolar;
		cout << endl << "You buyed " << a << "pieces DOLAR";
		currencyhesabi[0] = a;
		deneme = deneme - exc;
	}

	else if (cur == "euro" || cur == "EURO")
	{
		double b = exc / y;
		cout << endl << "You buyed " << b << "pieces EURO";
		currencyhesabi[1] = euro;
		deneme = deneme - exc;
	}

	else if (cur == "sterlin" || cur == "STERLIN")
	{
		double c = exc / z;
		cout << endl << "You buyed " << c << "pieces STERLIN";
		currencyhesabi[2] = sterlin;
		deneme = deneme - exc;
	}
	balance = deneme;
	cout << endl << "Avaible balance: " << deneme << endl;

}

void investmentAccount::sellcurrency()
{
	if (currencyhesabi[0] <= 0 && currencyhesabi[1] <= 0 && currencyhesabi[2] <= 0)
		cout << "You dont have any stocks";
	if (currencyhesabi[0] > 0)
	{
		cout << endl << "You have " << currencyhesabi[0] << " pieces ISCTR" << endl;
		cout << "How many ISCTR do you want to sell: ";
		int girdi;
		cin >> girdi;

		if (girdi > currencyhesabi[0])
			cout << "Mistake! " << girdi << " is bigger than you have";
		currencyhesabi[0] = currencyhesabi[0] - girdi;
		balance += girdi * dolar;
		cout << "Current balance: " << balance << endl;

	}
	if (currencyhesabi[1] > 0)
	{
		cout << "You have " << currencyhesabi[1] << " pieces ASELS" << endl;
		cout << "How many ASELS do you want to sell: ";
		int girdi;
		cin >> girdi;

		if (girdi > currencyhesabi[1])
			cout << "Mistake! " << girdi << " is bigger than you have";
		currencyhesabi[1] = currencyhesabi[1] - girdi;
		balance += girdi * euro;
		cout << "Current balance: " << balance << endl;
	}
	if (currencyhesabi[2] > 0)
	{
		cout << "You have " << currencyhesabi[2] << " pieces AVHOL" << endl << endl;
		cout << "How many AVHOL do you want to sell: ";
		int girdi;
		cin >> girdi;

		if (girdi > currencyhesabi[2])
			cout << "Mistake! " << girdi << " is bigger than you have";
		currencyhesabi[2] = currencyhesabi[2] - girdi;
		balance += girdi * sterlin;
		cout << "Current balance: " << balance << endl;
	}
}
void investmentAccount::showMycurrency()
{
	cout << endl << "You have " << currencyhesabi[0] << " pieces DOLAR" << endl;
	cout << "You have " << currencyhesabi[1] << " pieces EURO" << endl;
	cout << "You have " << currencyhesabi[2] << " pieces STERLIN" << endl << endl;

}

void investmentAccount::showstocks()
{
	cout << "Turkiye Is Bankasi A.S. (ISCTR): " << x << endl;
	cout << "Aselsan Elektronik Sanayi ve Ticaret A.S. (ASELS): " << y << endl;
	cout << "Avrupa Yatirim Holding A.S. (AVHOL): " << z << endl << endl;

}

void investmentAccount::buystocks()
{
	
	cout << "Enter code of stock which you want to buy: ";
	string stockname;
	cin >> stockname;
	while (stockname != "ISCTR" && stockname != "isctr" && stockname != "ASELS" && stockname != "asels" && stockname != "AVHOL" && stockname != "avhol")
	{
		cout << "Invalid code, try again: ";
		cin >> stockname;
		if (stockname == "ISCTR" || stockname == "isctr" || stockname == "ASELS" || stockname == "asels" || stockname == "AVHOL" || stockname == "avhol")
			break;
	}

	cout << endl << "Avaible balance: " << balance << endl;;
	cout << "How much price do you want to buy: ";
	double exc;
	cin >> exc;
	if (exc <= 0 || exc > balance)
		cout << "Invalid value or insufficient balance"<<endl;
	else if (stockname == "ISCTR" || stockname == "isctr")
	{
		double a = exc / x;
		cout << "You buyed " << a << " pieces ISCTR"<<endl;
		hissehesabi[0] = a;
		balance = balance - exc;
	}

	else if (stockname == "ASELS" || stockname == "asels")
	{
		double b = exc / y;
		cout << "You buyed " << b << " pieces ASELS"<<endl;
		hissehesabi[1] = b;
		balance = balance - exc;

	}

	else if (stockname == "AVHOL" || stockname == "avhol")
	{
		double c = exc / z;
		cout << "You buyed " << c << " pieces AVHOL"<<endl;
		hissehesabi[2] = c;
		balance = balance - exc;
	}

}

void investmentAccount::showMyStocks()
{
	cout << endl << "You have " << hissehesabi[0] << " pieces ISCTR" << endl;
	cout << "You have " << hissehesabi[1] << " pieces ASELS" << endl;
	cout << "You have " << hissehesabi[2] << " pieces AVHOL" << endl << endl;

}

void investmentAccount::sellstocks()
{
	if (hissehesabi[0] <= 0 && hissehesabi[1] <= 0 && hissehesabi[2] <= 0)
		cout << "You dont have any stocks";
	if (hissehesabi[0] > 0)
	{
		cout << endl << "You have " << hissehesabi[0] << " pieces ISCTR" << endl;
		cout << "How many ISCTR do you want to sell: ";
		int girdi;
		cin >> girdi;

		if (girdi > hissehesabi[0])
			cout<<"Mistake! "<<girdi<<" is bigger than you have";
		hissehesabi[0] = hissehesabi[0] - girdi;
		balance += girdi * x;
		cout << "Current balance: " << balance<<endl;

	}
	if (hissehesabi[1] > 0)
	{
		cout << "You have " << hissehesabi[1] << " pieces ASELS" << endl;
		cout << "How many ASELS do you want to sell: ";
		int girdi;
		cin >> girdi;

		if (girdi > hissehesabi[1])
			cout << "Mistake! " << girdi << " is bigger than you have";
		hissehesabi[1] = hissehesabi[1] - girdi;
		balance += girdi * y;
		cout << "Current balance: " << balance<<endl;
	}
	if (hissehesabi[2] > 0)
	{
		cout << "You have " << hissehesabi[2] << " pieces AVHOL" << endl << endl;
		cout << "How many AVHOL do you want to sell: ";
		int girdi;
		cin >> girdi;

		if (girdi > hissehesabi[2])
			cout << "Mistake! " << girdi << " is bigger than you have";
		hissehesabi[2] = hissehesabi[2] - girdi;
		balance += girdi * z;
		cout << "Current balance: " << balance<<endl;
	}
}

void investmentAccount::menustocks()
{
	
	cout << "[1] Show stocks" << endl;
	cout << "[2] Buy stocks" << endl;
	cout << "[3] Show Mystocks" << endl;
	cout << "[4] Sell stocks" << endl;



	cout << "Please make a choice" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1: showstocks();
			cin >> choice;
			break;
			
		case 2: buystocks();
			cin >> choice;
			break;
			
		case 3: showMyStocks();
			cin >> choice;
			break;
			
		case 4: sellstocks();
			cin >> choice;
			break;
		default:
			cout << "There is a mistake, Write 0 or close the programming"<<endl;
			cin >> choice;

		}

	}
	

}


void investmentAccount::menucurrency()
{

	cout << "[1] Show currencies" << endl;
	cout << "[2] Buy currencies" << endl;
	cout << "[3] Show my currencies" << endl;
	cout << "[4] Sell currencies" << endl;



	cout << "Please make a choice" << endl;
	int choice = 0;
	cin >> choice;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1: showcurrency();
			cin >> choice;
			break;

		case 2: buycurrency();
			cin >> choice;
			break;

		case 3: showMycurrency();
			cin >> choice;
			break;

		case 4: sellcurrency();
			cin >> choice;
			break;
		default:
			cout << "There is a mistake, Write 0 or close the programming" << endl;
			cin >> choice;

		}

	}
	

}
