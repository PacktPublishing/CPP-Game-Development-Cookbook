#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class IBuilding
{
public:
	virtual void TotalHealth() = 0;
};

class Barracks : public IBuilding
{
public:
	void TotalHealth()
	{
		cout << "Health of Barrack is :" << 100;
	}
};
class Temple : public IBuilding
{
public:
	void TotalHealth()
	{
		cout << "Health of Temple is :" << 75;
	}
};
class Farmhouse : public IBuilding
{
public:
	void TotalHealth()
	{
		cout << "Health of Farmhouse is :" << 50;
	}
};

int main()
{
	vector<IBuilding*> BuildingTypes;
	int choice;

	cout << "Specify the different building types in your village" << endl;
	while (true)
	{
		
		cout << "Barracks(1) Temple(2) Farmhouse(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		else if (choice == 1)
			BuildingTypes.push_back(new Barracks);
		else if (choice == 2)
			BuildingTypes.push_back(new Temple);
		else
			BuildingTypes.push_back(new Farmhouse);
	}
	cout << endl;
	cout << "There are total " << BuildingTypes.size() << " buildings" << endl;
	for (int i = 0; i < BuildingTypes.size(); i++)
	{
		BuildingTypes[i]->TotalHealth();
		cout << endl;
	}
		
	for (int i = 0; i < BuildingTypes.size(); i++)
		delete BuildingTypes[i];

	_getch();
}