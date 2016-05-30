#include <iostream>

class A
{
public:

	void Calc()const
	{
		Add(a, b);
		//a = 9;       // Not Allowed
	}
	A()
	{
		a = 10;
		b = 10;

	}
private:
	
	int a, b;
	void Add(int a, int b)const
	{
		
		std::cout << a + b << std::endl;
	}
};

int main()
{
	
	A _a;
	_a.Calc();

	int a;
	std::cin >> a;

	return 0;
}