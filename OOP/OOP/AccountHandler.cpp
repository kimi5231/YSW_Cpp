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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::SelectMenu(void)
{
	int comm;

	cout << "����: ", cin >> comm;
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

	cout << "[���°���]" << endl;
	cout << "����ID: ", cin >> ID;
	cout << "�� ��: ", cin >> name;
	cout << "�Աݾ�: ", cin >> amount;
	cout << endl;

	account[custom_num++] = new Account(ID, name, amount);
}

void AccountHandler::Deposit(void)
{
	int ID, amount;

	cout << "[��   ��]" << endl;
	cout << "����ID: ", cin >> ID;
	cout << "�Աݾ�: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->GetID() == ID)
		{
			account[i]->Deposit(amount);
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::Withdraw(void)
{
	int ID, amount;

	cout << "[��   ��]" << endl;
	cout << "����ID: ", cin >> ID;
	cout << "��ݾ�: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->GetID() == ID)
		{
			account[i]->Withdraw(amount);
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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