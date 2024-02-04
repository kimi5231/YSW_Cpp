#include "Header.h"

extern Account account[100];
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
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ", cin >> account[custom_num].accountNum;
	cout << "이 름: ", cin >> account[custom_num].name;
	cout << "입금액: ", cin >> account[custom_num++].amount;
	cout << endl;
}

void Deposit(void)
{
	int accountNum, amount;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ", cin >> accountNum;
	cout << "입금액: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i].accountNum == accountNum)
		{
			account[i].amount += amount;
			cout << "입금완료" << endl << endl;
			return;
		}
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
		if (account[i].accountNum == accountNum)
		{
			if (account[i].amount < amount)
				cout << "잔액부족" << endl << endl;
			else
			{
				account[i].amount -= amount;
				cout << "출금완료" << endl << endl;
			}
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < custom_num; i++)
	{
		cout << "계좌ID: " << account[i].accountNum << endl;
		cout << "이 름: " << account[i].name << endl;
		cout << "잔 액: " << account[i].amount << endl << endl;
	}
}