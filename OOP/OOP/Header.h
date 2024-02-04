#pragma once
#include <iostream>

using namespace std;

void ShowMenu(void);
void SelectMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowAllAccount(void);

typedef struct Account
{
	int accountNum;
	char name[50];
	int amount;
}Account;