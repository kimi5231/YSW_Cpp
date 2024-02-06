#include <iostream>

using namespace std;

void IncreaseValue(int &ref)
{
	ref++;
}

void ChangeSign(int& ref)
{
	ref *= -1;
}

int main(void)
{
	int num;

	cout << "정수 입력: ", cin >> num;
	IncreaseValue(num);
	cout << "IncreaseValue: " << num << endl;
	ChangeSign(num);
	cout << "ChangeSign: " << num << endl;
	return 0;
}