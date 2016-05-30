#include <iostream>

enum Flags
{
	FLAG1 = (1 << 0),
	FLAG2 = (1 << 1),
	FLAG3 = (1 << 2)
};

int main()
{

	int flags = FLAG1 | FLAG2;

	if (flags&FLAG1)
	{
		//Do Something
	}
	if (flags&FLAG2)
	{
		//Do Something
	}


	return 0;
}