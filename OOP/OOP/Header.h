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
	int accountNum;
	char* name;
	int amount;
public:
	Account(int accountNum, const char* name, int amount)
		: accountNum(accountNum), amount(amount)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	bool Deposit(int accountNum, int amount)
	{
		if (this->accountNum == accountNum)
		{
			this->amount += amount;
			cout << "입금완료" << endl << endl;
			return true;
		}
		return false;
	}
	bool Withdraw(int accountNum, int amount)
	{
		if (this->accountNum == accountNum)
		{
			if (this->amount < amount)
				cout << "잔액부족" << endl << endl;
			else
			{
				this->amount -= amount;
				cout << "출금완료" << endl << endl;
			}
			return true;
		}

		return false;
	}
	void ShowAllAccount(void) const
	{
		cout << "계좌ID: " << accountNum << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << amount << endl << endl;
	}
	~Account()
	{
		delete[]name;
	}
};