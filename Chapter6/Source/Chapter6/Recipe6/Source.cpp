#include <iostream>
#include <conio.h>

using namespace std;


class SpecialPower
{
public:
	virtual void power() = 0; 
};

class Fire : public SpecialPower
{
public:
	void power()
	{
		cout << "My power is fire" << endl;
	}
};

class Invisibility : public SpecialPower
{
public:
	void power()
	{
		cout << "My power is invisibility" << endl;
	}
};




class FlyBehaviour
{
public:
	virtual void fly() = 0; 
};

class FlyWithWings : public FlyBehaviour
{
public:
	void fly()
	{
		cout << "I can fly" << endl;
	}
};

class FlyNoWay : public FlyBehaviour
{
public:
	void fly()
	{
		cout << "I can't fly!" << endl;
	}
};

class FlyWithRocket : public FlyBehaviour
{
public:
	void fly()
	{
		cout << "I have a jetpack" << endl;
	}
};




class Enemy
{

public:
	
	SpecialPower *specialPower;
	FlyBehaviour   *flyBehaviour;

	void performPower()
	{
		specialPower->power();
	}

	void setSpecialPower(SpecialPower *qb)
	{
		cout << "Changing special power..." << endl;
		specialPower = qb;
	}

	void performFly()
	{
		flyBehaviour->fly();
	}

	void setFlyBehaviour(FlyBehaviour *fb)
	{
		cout << "Changing fly behaviour..." << endl;
		flyBehaviour = fb;
	}

	void floatAround()
	{
		cout << "I can float." << endl;
	}

	virtual void display() = 0; // Make this an abstract class by having a pure virtual function


};

class Dragon : public Enemy
{
public:
	Dragon()
	{
		specialPower = new Fire();
		flyBehaviour = new FlyWithWings();
	}

	void display()
	{
		cout << "I'm a dragon" << endl;
	}

};

class Soldier : public Enemy
{
public:
	Soldier()
	{
		specialPower = new Invisibility();
		flyBehaviour = new FlyNoWay();
	}

	void display()
	{
		cout << "I'm a soldier" << endl;
	}
};




int main()
{
	Enemy *dragon = new Dragon();
	dragon->display();
	dragon->floatAround();
	dragon->performFly();
	dragon->performPower();

	cout << endl << endl;

	Enemy *soldier = new Soldier();
	soldier->display();
	soldier->floatAround();
	soldier->performFly();
	soldier->setFlyBehaviour(new FlyWithRocket);
	soldier->performFly();
	soldier->performPower();
	soldier->setSpecialPower(new Fire);
	soldier->performPower();

	_getch();
	return 0;
}