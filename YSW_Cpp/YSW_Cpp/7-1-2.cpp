#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* name, int age) : age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void ShowMyFriendInfo(void) const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* name, int age, const char* addr, const char* phone)
		: MyFriendInfo(name, age) 
	{
		this->addr = new char[strlen(addr) + 1];
		strcpy(this->addr, addr);
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->phone, phone);
	}
	void ShowMyFriendDetailInfo(void) const
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
	}
};

int main(void)
{
	MyFriendDetailInfo myfriend("윤성우", 20, "집", "010-1111-1111");

	myfriend.ShowMyFriendDetailInfo();
	return 0;
}