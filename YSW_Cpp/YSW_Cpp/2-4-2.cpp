#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	int arr[5];

	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << endl;
	}

	return 0;
}