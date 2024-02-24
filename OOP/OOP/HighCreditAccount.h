#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int creditLevel;
public:
	HighCreditAccount(int ID, const char* name, int amount, int rate, int credit)
		:NormalAccount(ID, name, amount, rate), creditLevel(credit)
	{}
	virtual void Deposit(int amount)
	{
		double rate;

		switch (creditLevel)
		{
		case 1:
			rate = GetInterRate() + 0.07;
			break;
		case 2:
			rate = GetInterRate() + 0.04;
			break;
		case 3:
			rate = GetInterRate() + 0.02;
			break;
		}

		Account::Deposit(amount + amount*rate);
	}
};