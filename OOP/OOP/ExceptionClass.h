#pragma once
#include "BankingCommonDecl.h"

class DepositException
{
private:
	int money;
public:
	DepositException(int money) : money(money) {}
	void ShowExceptionReasonWithValue(void) const
	{
		cout << "[예외 메세지: " << money << "는 입금불가]" << endl;
		cout << "다시 입력해주세요." << endl;
	}
};

class WithdrawException
{
private:
	int amount;
public:
	WithdrawException(int money) : amount(money) {}
	void ShowExceptionReasonWithValue(void) const
	{
		cout << "[예외 메세지: " << amount << "는 출금불가]" << endl;
		cout << "다시 입력해주세요." << endl;
	}
	void ShowExceptionReasonWithAmount(void) const
	{
		cout << "[예외 메세지: 잔액 " << amount << ", 잔액부족]" << endl;
		cout << "다시 입력해주세요." << endl;
	}
};