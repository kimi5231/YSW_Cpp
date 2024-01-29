#include <iostream>

int main(void)
{
	int sale, pay;

	while (1)
	{
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ", std::cin >> sale;
		if (sale == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;
			return 0;
		}
		pay = 50 + sale * 0.12;
		std::cout << "이번 달 급여: " << pay << "만원" << std::endl;
	}
}