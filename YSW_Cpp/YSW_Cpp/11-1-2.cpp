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
		cout << "Book 생성자 호출" << endl;

		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	Book(const Book& ref) : price(ref.price)
	{
		cout << "Book 복사 생성자 호출" << endl;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
	}
	void ShowBookInfo(void) const
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	Book& operator=(const Book& ref)
	{
		cout << "Book 대입 연산자 호출" << endl;

		if (title != NULL)
			delete []title;

		if (isbn != NULL)
			delete []isbn;

		price = ref.price;

		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);

		return *this;
	}
	~Book()
	{
		cout << " Book 소멸자 호출" << endl;

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
		cout << "EBook 생성자 호출" << endl;

		DRMKey = new char[strlen(drm) + 1];
		strcpy(DRMKey, drm);
	}
	EBook(const EBook &ref)
		: Book(ref)
	{
		cout << "EBook 복사 생성자 호출" << endl;

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	void ShowEBookInfo(void) const
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	EBook& operator=(const EBook& ref)
	{
		cout << "EBook 대입 연산자 호출" << endl;

		if (ref.DRMKey != NULL)
			delete[]DRMKey;

		Book::operator=(ref);

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}
	~EBook()
	{
		cout << "EBook 소멸자 호출" << endl;

		delete[]DRMKey;
	}
};

int main(void)
{
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	book1.ShowBookInfo();
	cout << endl;
	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook1.ShowEBookInfo();
	cout << endl;
	Book book2 = book1;
	book2.ShowBookInfo();
	cout << endl;
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << endl;
	Book book3("좋은 C", "555-12345-890-0", 20000);
	book3 = book2;
	book3.ShowBookInfo();
	cout << endl;
	EBook ebook3("좋은 C ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	cout << endl;
	return 0;
}