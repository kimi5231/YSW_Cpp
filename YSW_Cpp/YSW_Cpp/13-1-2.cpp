#include <iostream>

using namespace std;

template <typename T>

T SumArray(T arr[], int len)
{
	T sum = 0;

	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main(void)
{
	int arrI[5] = { 1, 2, 3, 4, 5 };
	double arrD[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	cout << SumArray(arrI, 5) << endl;
	cout << SumArray(arrD, 5) << endl;

	return 0;
}