#include <iostream>
#include <conio.h>

using namespace std;

class PhysicsManager
{
private:
	static bool bCheckFlag;
	static PhysicsManager *s_singleInstance;
	PhysicsManager()
	{
		//private constructor
	}
public:
	static PhysicsManager* getInstance();
	void GetCurrentGravity()const;

	~PhysicsManager()
	{
		bCheckFlag = false;
	}
};

bool PhysicsManager::bCheckFlag = false;

PhysicsManager* PhysicsManager::s_singleInstance = NULL;

PhysicsManager* PhysicsManager::getInstance()
{
	if (!bCheckFlag)
	{
		s_singleInstance = new PhysicsManager();
		bCheckFlag = true;
		return s_singleInstance;
	}
	else
	{
		return s_singleInstance;
	}
}

void PhysicsManager::GetCurrentGravity() const
{
	//Some calculations for finding the current gravity
	//Probably a base variable which constantly gets updated with value
	//based on the environemnt
	cout << "Current gravity of the system is: " <<9.8<< endl;
}

int main()
{
	PhysicsManager *sc1, *sc2;
	sc1 = PhysicsManager::getInstance();
	sc1->GetCurrentGravity();
	sc2 = PhysicsManager::getInstance();
	sc2->GetCurrentGravity();

	_getch();
	return 0;
}