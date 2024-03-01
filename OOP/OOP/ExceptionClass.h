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
		cout << "[���� �޼���: " << money << "�� �ԱݺҰ�]" << endl;
		cout << "�ٽ� �Է����ּ���." << endl;
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
		cout << "[���� �޼���: " << amount << "�� ��ݺҰ�]" << endl;
		cout << "�ٽ� �Է����ּ���." << endl;
	}
	void ShowExceptionReasonWithAmount(void) const
	{
		cout << "[���� �޼���: �ܾ� " << amount << ", �ܾ׺���]" << endl;
		cout << "�ٽ� �Է����ּ���." << endl;
	}
};