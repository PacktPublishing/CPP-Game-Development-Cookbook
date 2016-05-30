
//Header files
#include <iostream>


class Game
{
	//Member variables (Already known)
public:
private:
protected:

};

//Adding 2 numbers
int Add(int a=4,int b=5)
{
	return a + b;
}


void Logic(int a,int b)
{
	if (a > 10 ? std::cout << a : std::cout << b);
		
}
int main()
{
	std::cout<<Add()<<std::endl;
	Logic(5,8);

	int a;
	std::cin >> a;
}