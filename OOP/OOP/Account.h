#pragma once
#include "Header.h"

class Account
{
private:
	int ID;
	char* name;
	int amount;
public:
	Account(int ID, const char* name, int amount);
	Account(const Account& copy);
	int GetID(void) const;
	void Deposit(int amount);
	void Withdraw(int amount);
	void ShowAllAccount(void) const;
	~Account();
};
