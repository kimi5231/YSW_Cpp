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
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	if (pos1 == pos2)
		return false;
	else
		return true;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1.ShowPosition();
	pos2.ShowPosition();
	cout << (pos1 == pos2) << endl;
	cout << (pos1 != pos2) << endl;
	return 0;
}