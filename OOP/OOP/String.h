#pragma once
#include "BankingCommonDecl.h"

class String
{
private:
	char* str;
	int len;
public:
	String();
	String(const char* str);
	String(const String& ref);
	String& operator=(const String& ref);
	String operator+(const String& ref);
	String& operator+=(const String& ref);
	bool operator==(const String& ref);
	~String();
	friend ostream& operator<<(ostream& os, const String& ref);
	friend istream& operator>>(istream& is, String& ref);
};