#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y)
	{}
	void ShowPosition(void) const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1 += pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos1 -= pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}