#include "Header.h"

extern Account* account[100];
extern int custom_num;
extern int q;

void ShowMenu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void SelectMenu(void)
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
		q = 0;
		break;
	default:
		break;
	}
}

void MakeAccount(void)
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

void Deposit(void)
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

void Withdraw(void)
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

void ShowAllAccount(void)
{
	for (int i = 0; i < custom_num; i++)
		account[i]->ShowAllAccount();
}