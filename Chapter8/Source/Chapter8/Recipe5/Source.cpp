/* Adding Behavorial Movements*/


#include <iostream>
using namespace std;
class Machine
{
	class State *current;
public:
	Machine();
	void setCurrent(State *s)
	{
		current = s;
	}
	void Run();
	void Walk();
};

class State
{
public:
	virtual void Run(Machine *m)
	{
		cout << "   Already Running\n";
	}
	virtual void Walk(Machine *m)
	{
		cout << "   Already Walking\n";
	}
};

void Machine::Run()
{
	current->Run(this);
}

void Machine::Walk()
{
	current->Walk(this);
}

class RUN : public State
{
public:
	RUN()
	{
		cout << "   RUN-ctor ";
	};
	~RUN()
	{
		cout << "   dtor-RUN\n";
	};
	void Walk(Machine *m);
};

class WALK : public State
{
public:
	WALK()
	{
		cout << "   WALK-ctor ";
	};
	~WALK()
	{
		cout << "   dtor-WALK\n";
	};
	void Run(Machine *m)
	{
		cout << " Changing behaviour from WALK to RUN";
		m->setCurrent(new RUN());
		delete this;
	}
};

void RUN::Walk(Machine *m)
{
	cout << "   Changing behaviour RUN to WALK";
	m->setCurrent(new WALK());
	delete this;
}

Machine::Machine()
{
	current = new WALK();
	cout << '\n';
}

int main()
{
	Machine m;
	m.Run();
	m.Walk();
	m.Walk();

	int a;
	cin >> a;

	return 0;
}
