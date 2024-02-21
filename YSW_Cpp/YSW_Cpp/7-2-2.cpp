#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo(void) const
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, int price, const char* drm)
		: Book(title, isbn, price)
	{
		DRMKey = new char[strlen(drm) + 1];
		strcpy(DRMKey, drm);
	}
	void ShowEBookInfo(void) const
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[]DRMKey;
	}
};

int main(void)
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}