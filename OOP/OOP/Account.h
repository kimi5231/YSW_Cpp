#pragma once
#include "BankingCommonDecl.h"
#include "String.h"

class Account
{
private:
	int ID;
	String name;
	int amount;
public:
	Account(int ID, const String name, int amount);
	//Account(const Account& copy);
	int GetID(void) const;
	virtual void Deposit(int amount);
	void Withdraw(int amount);
	void ShowAccount(void) const;
	//Account& operator=(const Account& ref);
	//~Account();
};
