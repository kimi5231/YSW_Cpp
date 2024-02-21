#include <iostream>

using namespace std;

class Rectangle
{
private:
	int length;
	int width;
public:
	Rectangle(int l, int w) : length(l), width(w) {}
	void ShowAreaInfo(void)
	{
		cout << "¸éÀû: " << length * width << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int s) : Rectangle(s, s) {}
};

int main(void)
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}