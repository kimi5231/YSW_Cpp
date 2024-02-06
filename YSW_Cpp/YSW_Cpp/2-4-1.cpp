#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char str1[20], str2[20];

	strcpy(str1, "Hello World!");
	strcpy(str2, str1);
	cout << "strcpy: " << str1 << ", " << str2 << endl;

	strcat(str1, "!");
	cout << "strcat: " << str1 << ", " << str2 << endl;

	cout << "strlen: " << strlen(str1) << " " << strlen(str2) << endl;

	cout << "strcmp(1, 2): " << strcmp(str1, str2) << endl;
	cout << "strcmp(2, 1): " << strcmp(str2, str1) << endl;

	return 0;
}