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
	Point operator-(void)
	{
		Point pos(-xpos, -ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2 = -pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	return 0;
}