#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
private:
	char string[50];
public:
	void SetString(const char*);
	void ShowString(void);
};

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}

void Printer::SetString(const char* str)
{
	strcpy(string, str);
}

inline void Printer::ShowString(void)
{
	cout << string << endl;
}