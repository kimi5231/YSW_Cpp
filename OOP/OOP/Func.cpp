#include "Header.h"

extern Account account[100];
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
	cout << "[���°���]" << endl;
	cout << "����ID: ", cin >> account[custom_num].accountNum;
	cout << "�� ��: ", cin >> account[custom_num].name;
	cout << "�Աݾ�: ", cin >> account[custom_num++].amount;
	cout << endl;
}

void Deposit(void)
{
	int accountNum, amount;

	cout << "[��   ��]" << endl;
	cout << "����ID: ", cin >> accountNum;
	cout << "�Աݾ�: ", cin >> amount;

	for (int i = 0; i < custom_num; i++)
	{
		if (account[i].accountNum == accountNum)
		{
			account[i].amount += amount;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
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
		if (account[i].accountNum == accountNum)
		{
			if (account[i].amount < amount)
				cout << "�ܾ׺���" << endl << endl;
			else
			{
				account[i].amount -= amount;
				cout << "��ݿϷ�" << endl << endl;
			}
			return;
		}
	}

	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void ShowAllAccount(void)
{
	for (int i = 0; i < custom_num; i++)
	{
		cout << "����ID: " << account[i].accountNum << endl;
		cout << "�� ��: " << account[i].name << endl;
		cout << "�� ��: " << account[i].amount << endl << endl;
	}
}