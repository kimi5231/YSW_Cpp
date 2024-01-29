#include <iostream>

int main(void)
{
	char name[100], phone[100];

	std::cout << "이름 입력: ", std::cin >> name;
	std::cout << "전화번호 입력: ", std::cin >> phone;
	std::cout << "이름: " << name << std::endl << "전화번호: " << phone << std::endl;
	return 0;
}