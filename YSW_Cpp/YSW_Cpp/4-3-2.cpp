#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int position)
	{
		cout << "����: ";
		switch (position)
		{
		case CLERK:
			cout << "���";
			break;
		case SENIOR:
			cout << "����";
			break;
		case ASSIST:
			cout << "�븮";
			break;
		case MANAGER:
			cout << "����";
			break;
		}
		cout<< endl << endl;
	}
}

class NameCard
{
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* myname, const char* mycompany, const char* myphone, int myposition) : position(myposition)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		company = new char[strlen(mycompany) + 1];
		strcpy(company, mycompany);
		phone = new char[strlen(myphone) + 1];
		strcpy(phone, myphone);
	}
	void ShowNameCardInfo(void) const
	{
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		COMP_POS::ShowPositionInfo(position);
	}
	~NameCard()
	{
		delete []name;
		delete []company;
		delete []phone;
	}
};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}