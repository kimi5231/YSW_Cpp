#include "AccountHandler.h"

AccountHandler::AccountHandler(void)
	: custom_num(0), q(true)
{

}

bool AccountHandler::GetQ(void) const
{
	return q;
}

void AccountHandler::ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::SelectMenu(void)
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
		q = false;
		break;
	default:
		break;
	}
}

void AccountHandler::MakeAccount(void)
{
	int ID, amount;
	char name[50];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ", cin >> ID;
	cout << "이 름: ", cin >> name;
	cout << "입금액: ", cin >> amount;
	cout << endl;

	account[custom_num++] = new Account(ID, name, amount);
}

void AccountHandler::Deposit(void)
{
	int ID, amount;

	cout << "[입   금]" << endl;
	cout << "계좌ID: ", cin >> ID;
	cout << "입금액: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->GetID() == ID)
		{
			account[i]->Deposit(amount);
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::Withdraw(void)
{
	int ID, amount;

	cout << "[출   금]" << endl;
	cout << "계좌ID: ", cin >> ID;
	cout << "출금액: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->GetID() == ID)
		{
			account[i]->Withdraw(amount);
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::ShowAllAccount(void) const
{
	for (int i = 0; i < custom_num; i++)
		account[i]->ShowAllAccount();
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < custom_num; i++)
		delete[]account[i];
}