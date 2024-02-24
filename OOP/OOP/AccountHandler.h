#pragma once
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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
	void SelectAccountKind(void);
	void MakeNormalAccount(void);
	void MakeHighCreditAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void ShowAllAccount(void) const;
	~AccountHandler();
};