#pragma once
#include "Account.h"

class NormalAccount : public Account
{
private:
	double interRate;
public:
	NormalAccount(int ID, const char* name, int amount, int rate)
		:Account(ID, name, amount), interRate(rate*0.01)
	{}
	double GetInterRate(void) const
	{
		return interRate;
	}
	virtual void Deposit(int amount)
	{
		Account::Deposit(amount + amount*interRate);
	}
};