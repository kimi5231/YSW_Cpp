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
	int accountNum, amount;
	char name[50];

	cout << "[���°���]" << endl;
	cout << "����ID: ", cin >> accountNum;
	cout << "�� ��: ", cin >> name;
	cout << "�Աݾ�: ", cin >> amount;
	cout << endl;

	account[custom_num++] = new Account(accountNum, name, amount);
}

void Deposit(void)
{
	int accountNum, amount;

	cout << "[��   ��]" << endl;
	cout << "����ID: ", cin >> accountNum;
	cout << "�Աݾ�: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->Deposit(accountNum, amount))
			return;
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void Withdraw(void)
{
	int accountNum, amount;

	cout << "[��   ��]" << endl;
	cout << "����ID: ", cin >> accountNum;
	cout << "��ݾ�: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i]->Withdraw(accountNum, amount))
			return;
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < custom_num; i++)
		account[i]->ShowAllAccount();
}