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
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl << endl;
		break;
	}
}

void AccountHandler::SelectAccountKind(void)
{
	int comm;

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> comm;
	
	switch (comm)
	{
	case 1:
		MakeNormalAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl << endl;
		break;
	}
}

void AccountHandler::MakeNormalAccount(void)
{
	int ID, amount, rate;
	String name;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: ", cin >> ID;
	cout << "�� ��: ", cin >> name;
	cout << "�Աݾ�: ", cin >> amount;
	cout << "������: ", cin >> rate;
	cout << endl;

	account[custom_num++] = new NormalAccount(ID, name, amount, rate);
}

void AccountHandler::MakeHighCreditAccount(void)
{
	int ID, amount, rate, credit;
	String name;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: ", cin >> ID;
	cout << "�� ��: ", cin >> name;
	cout << "�Աݾ�: ", cin >> amount;
	cout << "������: ", cin >> rate;
	cout << "�ſ���(1toA, 2toB, 3toC): ", cin >> credit;
	cout << endl;

	account[custom_num++] = new HighCreditAccount(ID, name, amount, rate, credit);
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
		account[i]->ShowAccount();
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < custom_num; i++)
		delete[]account[i];
}