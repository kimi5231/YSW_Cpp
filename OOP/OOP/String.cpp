#include "String.h"

String::String()
{
	str = NULL;
	len = 0;
}

String::String(const char* str)
{
	len = strlen(str) + 1;
	this->str = new char[len];
	strcpy(this->str, str);
}

String::String(const String& ref)
{
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);
}

String& String::operator=(const String& ref)
{
	len = ref.len;

	if (str != NULL)
		delete[]str;
	str = new char[len];
	strcpy(str, ref.str);

	return *this;
}

String String::operator+(const String& ref)
{
	char* temp = new char[len + ref.len - 1];
	strcpy(temp, str);
	strcat(temp, ref.str);

	String Str = temp;
	delete[]temp;
	return Str;
}

String& String::operator+=(const String& ref)
{
	*this = *this + ref;
	return *this;
}

bool String::operator==(const String& ref)
{
	if (strcmp(str, ref.str))
		return true;
	else
		return false;
}

String::~String()
{
	if (str != NULL)
		delete[]str;
}

ostream& operator<<(ostream& os, const String& ref)
{
	os << ref.str;
	return os;
}

istream& operator>>(istream& is, String& ref)
{
	char str[100];

	is >> str;
	ref = String(str);
	return is;
}