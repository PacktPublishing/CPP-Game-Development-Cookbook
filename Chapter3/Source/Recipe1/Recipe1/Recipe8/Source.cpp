#include <iostream>
#include <map>
#include <conio.h>

using namespace std;

int main()
{
	map <string, int> score_list;

	score_list["John"] = 242;
	score_list["Tim"] = 768;
	score_list["Sam"] = 34;

	if (score_list.find("Samuel") == score_list.end())
	{
		cout << "Samuel is not in the map!" << endl;
	}


	cout << score_list.begin()->second << endl;
	
	
		

	_getch();
	return 0;

}

