#include <iostream>

int main(void)
{
	char name[100], phone[100];

	std::cout << "�̸� �Է�: ", std::cin >> name;
	std::cout << "��ȭ��ȣ �Է�: ", std::cin >> phone;
	std::cout << "�̸�: " << name << std::endl << "��ȭ��ȣ: " << phone << std::endl;
	return 0;
}