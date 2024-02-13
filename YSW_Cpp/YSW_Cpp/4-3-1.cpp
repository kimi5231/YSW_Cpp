#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y) {}
	void ShowPointInfo(void) const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	Point pnt;
	int rad;
public:
	Circle (int x, int y, int r) : pnt(x, y), rad(r) {}
	void ShowCircleInfo(void) const
	{
		cout << "radius: " << rad << endl;
		pnt.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inner, outter;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2) : inner(x1, y1, r1), outter(x2, y2, r2) {}
	void ShowRingInfo(void) const
	{
		cout << "Inner Circle Info..." << endl;
		inner.ShowCircleInfo();
		cout << "outter Circle Info..." << endl;
		outter.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}