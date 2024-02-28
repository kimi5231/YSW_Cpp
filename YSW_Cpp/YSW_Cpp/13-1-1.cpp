#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y=0) : xpos(x), ypos(y) {}
	void ShowPosition(void) const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <typename T>

void SwapData(T& p1, T& p2)
{
	T temp = p1;
	p1 = p2;
	p2 = temp;
}

int main(void)
{
	Point p1(1, 2);
	Point p2(3, 4);

	p1.ShowPosition();
	p2.ShowPosition();
	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

	return 0;
}