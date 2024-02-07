#include <iostream>

using namespace std;

class Calculator
{
private:
	int add;
	int min;
	int mul;
	int div;
public:
	void Init(void);
	double Add(double, double);
	double Min(double, double);
	double Mul(double, double);
	double Div(double, double);
	void ShowOpCount(void);
};

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}

void Calculator::Init(void)
{
	add = 0;
	min = 0;
	mul = 0;
	div = 0;
}

inline double Calculator::Add(double n1, double n2)
{
	add++;
	return n1 + n2;
}

inline double Calculator::Min(double n1, double n2)
{
	min++;
	return n1 - n2;
}

inline double Calculator::Mul(double n1, double n2)
{
	mul++;
	return n1 * n2;
}

inline double Calculator::Div(double n1, double n2)
{
	div++;
	return n1 / n2;
}

inline void Calculator::ShowOpCount(void)
{
	cout << "µ¡¼À: " << add << " »¬¼À: " << min << " °ö¼À: " << mul << " ³ª´°¼À: " << div << endl;
}