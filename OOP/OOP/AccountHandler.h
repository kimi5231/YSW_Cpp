#pragma once
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	AccountArray account;
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