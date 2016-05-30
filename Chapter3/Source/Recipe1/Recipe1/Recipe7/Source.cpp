#include <iostream>
#include <list>
#include <conio.h>

using namespace std;

int main()
{
	list<int> possible_paths;
	possible_paths.push_back(1);
	possible_paths.push_back(1);
	possible_paths.push_back(8);
	possible_paths.push_back(9);
	possible_paths.push_back(7);
	possible_paths.push_back(8);
	possible_paths.push_back(2);
	possible_paths.push_back(3);
	possible_paths.push_back(3);

	possible_paths.sort();
	possible_paths.unique();

	for (list<int>::iterator list_iter = possible_paths.begin();
		list_iter != possible_paths.end(); list_iter++)
	{
		cout << *list_iter << endl;
	}


	_getch();
	return 0;

}
