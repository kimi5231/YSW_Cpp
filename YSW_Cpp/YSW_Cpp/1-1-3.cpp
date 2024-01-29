#include <iostream>

int main(void)
{
	int dan;

	std::cout << "´Ü ÀÔ·Â: ", std::cin >> dan;
	for (int i = 0; i < 9; i++)
		std::cout << dan << "x" << i + 1 << "=" << dan * (i + 1) << std::endl;
	return 0;
}