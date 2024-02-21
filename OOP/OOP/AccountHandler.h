#pragma once
#include "Header.h"
#include "Account.h"

class AccountHandler
{
private:
	Account* account[100];
	int custom_num;
	bool q;
public:
	AccountHandler(void);
	bool GetQ(void) const;
	void ShowMenu(void);
	void SelectMenu(void);
	void MakeAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void ShowAllAccount(void) const;
	~AccountHandler();
};