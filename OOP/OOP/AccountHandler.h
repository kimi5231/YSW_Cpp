#pragma once
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BoundCheckArray.h"
#include "String.h"
#include "ExceptionClass.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> account;
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