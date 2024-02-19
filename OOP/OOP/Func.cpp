#include "Header.h"

extern Account* account[100];
extern int custom_num;
extern int q;

void ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void SelectMenu(void)
{
	int comm;

	cout << "선택: ", cin >> comm;
	cout << endl;

	switch (comm)
	{
	case 1:
		MakeAccount();
		break;
	case 2:
		Deposit();
		break;
	case 3:
		Withdraw();
		break;
	case 4:
		ShowAllAccount();
		break;
	case 5:
		q = 0;
		break;
	default:
		break;
	}
}

void MakeAccount(void)
{
	int accountNum, amount;
	char name[50];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ", cin >> accountNum;
	cout << "이 름: ", cin >> name;
	cout << "입금액: ", cin >> amount;
	cout << endl;

	account[custom_num++] = new Account(accountNum, name, amount);
}

void Deposit(void)
{
	int accountNum, amount;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ", cin >> accountNum;
	cout << "입금액: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->Deposit(accountNum, amount))
			return;
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void Withdraw(void)
{
	int accountNum, amount;

	cout << "[출   금]" << endl;
	cout << "계좌ID: ", cin >> accountNum;
	cout << "출금액: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->Withdraw(accountNum, amount))
			return;
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < custom_num; i++)
		account[i]->ShowAllAccount();
}