#include <unordered_map>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	unordered_map<string, string> hashtable;
	hashtable.emplace("Alexander", "23ms");
	hashtable.emplace("Christopher", "21ms");
	hashtable.emplace("Steve", "55ms");
	hashtable.emplace("Amy", "17ms");
	hashtable.emplace("Declan", "999ms");

	cout << "Ping time in milliseconds: " << hashtable["Amy"] << endl<<endl;
	cout << "----------------------------------" << endl << endl;

	hashtable.insert(make_pair("Fawad", "67ms"));

	cout << endl<<"Ping time of all player is the server" << endl;
	cout << "------------------------------------" << endl << endl;
	for (auto &itr : hashtable)
	{
		cout << itr.first << ": " << itr.second << endl;
	}

	_getch();
	return 0;
}

