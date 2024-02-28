#include "AccountHandler.h"
#include "String.h"

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
		SelectAccountKind();
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
		cout << "잘못된 입력입니다. 다시 입력해주세요." << endl << endl;
		break;
	}
}

void AccountHandler::SelectAccountKind(void)
{
	int comm;

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: "; cin >> comm;
	
	switch (comm)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "잘못된 입력입니다. 다시 입력해주세요." << endl << endl;
		break;
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int ID, amount, rate;
	String name;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: ", cin >> ID;
	cout << "이 름: ", cin >> name;
	cout << "입금액: ", cin >> amount;
	cout << "이자율: ", cin >> rate;
	cout << endl;

	account[custom_num++] = new NormalAccount(ID, name, amount, rate);
}

void AccountHandler::MakeHighCreditAccount(void)
{
	int ID, amount, rate, credit;
	String name;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: ", cin >> ID;
	cout << "이 름: ", cin >> name;
	cout << "입금액: ", cin >> amount;
	cout << "이자율: ", cin >> rate;
	cout << "신용등급(1toA, 2toB, 3toC): ", cin >> credit;
	cout << endl;

	account[custom_num++] = new HighCreditAccount(ID, name, amount, rate, credit);
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
		account[i]->ShowAccount();
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < custom_num; i++)
		delete[]account[i];
}