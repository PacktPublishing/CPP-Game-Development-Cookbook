// Basic AI : Keyword identification

#include <iostream>
#include <string>
#include <string.h>

//Add more responses in this
std::string arr[] = { "Hello,what is your name ?", "My name is Siri" };

int main()
{

	std::string UserResponse;

	std::cout << "Enter your question? ";
	std::cin >> UserResponse;

	//TODO : Need to search also based on keywords and other parameters. 
	if (UserResponse == "Hi")
	{
		std::cout << arr[0] << std::endl;
		std::cout << arr[1];
	}
		

	int a;
	std::cin >> a;
	return 0;

}