#include <iostream>

using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2)
{
	Point* result = new Point;

	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;

	return *result;
}

int main(void)
{
	Point* p = new Point[2];

	cout << "ù ��° �� �Է�: ", cin >> p[0].xpos >> p[0].ypos;
	cout << "�� ��° �� �Է�: ", cin >> p[1].xpos >> p[1].ypos;

	Point &result = PntAdder(p[0], p[1]);

	cout << "�� ���� ��: " << result.xpos << " " << result.ypos << endl;

	delete []p;
	return 0;
}