#include "header.h"

Account* account[100];
int custom_num = 0;
int q = 1;

int main(void)
{
	while (q)
	{
		ShowMenu();
		SelectMenu();
	}
	return 0;
}