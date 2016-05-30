#include <thread>
#include <string>
#include <iostream>

using namespace std;

void function_1()
{
	for (int i = 0; i > -100; i--)
		cout << "From Thread 1: " << i << endl;

}

int main()
{
	std::thread t1(function_1);
	for (int i = 0; i < 100; i++)
		cout << "From main: " << i << endl;

	t1.join();

	int a;
	cin >> a;
	return 0;
}