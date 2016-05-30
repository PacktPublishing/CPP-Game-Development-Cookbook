#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

bool isBigEndian()
{
	unsigned int i = 1;
	char *c = (char*)&i;
	if (*c)
		return false;
	else
		return true;
}
int main()
{
	if (isBigEndian())
	{
		cout << "This is a Big Endian machine" << endl;
	}
	else
	{
		cout << "This is a Little Endian machine" << endl;
	}

	_getch();
	return 0;
}
