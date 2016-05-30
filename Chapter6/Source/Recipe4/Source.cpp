#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class PhysicsSystem {
	
	vector < class Observer * > views; 
	int value;
public:
	void attach(Observer *obs) {
		views.push_back(obs);
	}
	void setVal(int val) {
		value = val;
		notify();
	}
	int getVal() {
		return value;
	}
	void notify();
};

class Observer {

	PhysicsSystem *_attribute;
	int iScalarMultiplier;
public:
	Observer(PhysicsSystem *attribute, int value) 
	{
		_attribute = attribute;
		iScalarMultiplier = value;
		
		_attribute->attach(this);
	}
	virtual void update() = 0;
protected:
	PhysicsSystem *getPhysicsSystem() {
		return _attribute;
	}
	int getvalue() 
	{
		return iScalarMultiplier;
	}
};

void PhysicsSystem::notify() {
	
	for (int i = 0; i < views.size(); i++)
		views[i]->update();
}

class PlayerObserver : public Observer {
public:
	PlayerObserver(PhysicsSystem *attribute, int value) : Observer(attribute, value){}
	void update() {
		
		int v = getPhysicsSystem()->getVal(), d = getvalue();
		cout << "Player is dependant on the Physics system" << endl;
		cout << "Player new impulse value is " << v / d << endl << endl;
	}
};

class AIObserver : public Observer {
public:
	AIObserver(PhysicsSystem *attribute, int value) : Observer(attribute, value){}
	void update() {
		int v = getPhysicsSystem()->getVal(), d = getvalue();
		cout << "AI is dependant on the Physics system" << endl;
		cout << "AI new impulse value is " << v % d << endl << endl;
	}
};

int main() {
	PhysicsSystem subj;

	PlayerObserver valueObs1(&subj, 4); 
	AIObserver attributeObs3(&subj, 3);
	subj.setVal(100);

	_getch();
}