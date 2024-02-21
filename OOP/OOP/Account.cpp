#include "Account.h"

Account::Account(int ID, const char* name, int amount)
	: ID(ID), amount(amount)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& copy)
	: ID(copy.ID), amount(copy.amount)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Account::GetID(void) const
{
	return ID;
}

void Account::Deposit(int amount)
{
	this->amount += amount;
	cout << "�ԱݿϷ�" << endl << endl;
}

void Account::Withdraw(int amount)
{
	if (this->amount < amount)
		cout << "�ܾ׺���" << endl << endl;
	else
	{
		this->amount -= amount;
		cout << "��ݿϷ�" << endl << endl;
	}
}

void Account::ShowAllAccount(void) const
{
	cout << "����ID: " << ID << endl;
	cout << "�� ��: " << name << endl;
	cout << "�� ��: " << amount << endl << endl;
}

Account::~Account()
{
	delete[]name;
}