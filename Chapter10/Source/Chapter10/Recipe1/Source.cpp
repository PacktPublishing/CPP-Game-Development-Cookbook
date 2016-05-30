#include <iostream>
#include <thread>
#include <conio.h>

int ThreadOne()
{
	std::cout << "I am thread 1" << std::endl;
	return 0;
}

int ThreadTwo()
{
	std::cout << "I am thread 2" << std::endl;
	return 0;
}

int main()
{
	std::thread T1(ThreadOne);
	std::thread T2(ThreadTwo);

	if (T1.joinable()) // Check if can be joined to the main thread
		T1.join();     // Main thread waits for this to finish

	
	T2.detach();	  //Detached from main thread

	_getch();
	return 0;
}