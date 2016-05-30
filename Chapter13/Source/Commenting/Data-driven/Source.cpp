#include <iostream>
#include <string>
#include <fstream>

int main()
{
    using namespace std;

	string myArray[5];
    ifstream file("file.txt");
    if(file.is_open())
    {
        for(int i = 0; i < 5; ++i)
        {
            file >> myArray[i];
        }
    }

	for (int i = 0; i < 5; ++i)
	{
		cout<<myArray[i]<<endl;
	}


	int a;
	cin >> a;
}