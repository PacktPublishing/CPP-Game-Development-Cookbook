#include <iostream>

struct Type
{
	int a;
	unsigned char c[9];
	unsigned  b;
	float d;

};

struct Type2
{
	int a : 2;
	int b : 2;
};
int main()
{
	std::cout << sizeof(Type)<<std::endl;
	std::cout << sizeof(Type2);

	int a;
	std::cin >> a;
}