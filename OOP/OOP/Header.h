#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

void ShowMenu(void);
void SelectMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowAllAccount(void);

class Account
{
private:
	int ID;
	char* name;
	int amount;
public:
	Account(int ID, const char* name, int amount)
		: ID(ID), amount(amount)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	Account(const Account &copy)
		: ID(copy.ID), amount(copy.amount)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	int GetID(void)
	{
		return ID;
	}
	void Deposit(int amount)
	{
		this->amount += amount;
		cout << "�ԱݿϷ�" << endl << endl;
	}
	void Withdraw(int amount)
	{
		if (this->amount < amount)
			cout << "�ܾ׺���" << endl << endl;
		else
		{
			this->amount -= amount;
			cout << "��ݿϷ�" << endl << endl;
		}
	}
	void ShowAllAccount(void) const
	{
		cout << "����ID: " << ID << endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << amount << endl << endl;
	}
	~Account()
	{
		delete[]name;
	}
};