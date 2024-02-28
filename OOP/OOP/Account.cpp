#include "Account.h"

Account::Account(int ID, const String name, int amount)
	: ID(ID), amount(amount)
{
	this->name = name;
}

//Account::Account(const Account& copy)
//	: ID(copy.ID), amount(copy.amount)
//{
//	name = new char[strlen(copy.name) + 1];
//	strcpy(name, copy.name);
//}

int Account::GetID(void) const
{
	return ID;
}

void Account::Deposit(int amount)
{
	this->amount += amount;
	cout << "입금완료" << endl << endl;
}

void Account::Withdraw(int amount)
{
	if (this->amount < amount)
		cout << "잔액부족" << endl << endl;
	else
	{
		this->amount -= amount;
		cout << "출금완료" << endl << endl;
	}
}

void Account::ShowAccount(void) const
{
	cout << "계좌ID: " << ID << endl;
	cout << "이 름: " << name << endl;
	cout << "잔 액: " << amount << endl << endl;
}

//Account& Account::operator=(const Account& ref)
//{
//	if (name != NULL)
//		delete []name;
//
//	ID = ref.ID;
//	name = new char[strlen(ref.name) + 1];
//	strcpy(name, ref.name);
//	amount = ref.amount;
//
//	return *this;
//}

//Account::~Account()
//{
//	delete[]name;
//}