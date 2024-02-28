#pragma once
#include "BankingCommonDecl.h"

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
	virtual void Deposit(int amount);
	void Withdraw(int amount);
	void ShowAccount(void) const;
	Account& operator=(const Account& ref);
	~Account();
};
