#include <iostream>

int main(void)
{
	int sale, pay;

	while (1)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ", std::cin >> sale;
		if (sale == -1)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			return 0;
		}
		pay = 50 + sale * 0.12;
		std::cout << "�̹� �� �޿�: " << pay << "����" << std::endl;
	}
}