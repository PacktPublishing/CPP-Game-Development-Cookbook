#include <iostream>
#include <thread>
#include <string>
#include <conio.h>

class Wrapper
{
public:
	void operator()(std::string& msg)
	{
		msg = " I am from T1";
		std::cout << "T1 thread initiated" << msg << std::endl;
		

	}
};

int main()
{
	std::string s = "This is a message";
	std::cout << std::this_thread::get_id() << std::endl;

	std::thread T1((Wrapper()), std::move(s));
	std::cout << T1.get_id() << std::endl;

	std::thread T2 = std::move(T1);
	T2.join();

	

	_getch();

}