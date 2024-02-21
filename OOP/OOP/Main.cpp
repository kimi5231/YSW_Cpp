#include "header.h"
#include "AccountHandler.h"

int main(void)
{
	AccountHandler handler;

	while (handler.GetQ())
	{
		handler.ShowMenu();
		handler.SelectMenu();
	}
}