#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//IFast interface
class IFast
{
public:
	virtual std::string Name() = 0;
};

//ISlow interface
class ISlow
{
public:
	virtual std::string Name() = 0;
};
class Rapter : public ISlow
{
public:
	std::string Name()
	{
		return "Rapter";
	}
};

class Cocumbi : public IFast
{
public:
	std::string Name()
	{
		return "Cocumbi";
	}
};
class Marzel : public ISlow
{
public:
	std::string Name()
	{
		return "Marzel";
	}
};

class Plagmeto : public IFast
{
public:
	std::string Name()
	{
		return "Plagmeto";
	}
};
class Bungindi : public ISlow
{
public:
	std::string Name()
	{
		return "Bungindi";
	}
};

class Zybgry : public IFast
{
public:
	std::string Name()
	{
		return "Zybgry";
	}
};
class Pokili : public ISlow
{
public:
	std::string Name()
	{
		return "Pokili";
	}
};

class Manama : public IFast
{
public:
	std::string Name()
	{
		return "Manama";
	}
};

class AEnemyFactory
{
public:
	enum Enemy_Factories
	{
		Land,
		Air,
		Water
	};

	virtual IFast* GetFast() = 0;
	virtual ISlow* GetSlow() = 0;

	static AEnemyFactory* CreateFactory(Enemy_Factories factory);
};

class LandFactory : public AEnemyFactory
{
public:
	IFast* GetFast()
	{
		return new Cocumbi();
	}

	ISlow* GetSlow()
	{
		return new Marzel();
	}
};

class AirFactory : public AEnemyFactory
{
public:
	IFast* GetFast()
	{
		return new Zybgry();
	}

	ISlow* GetSlow()
	{
		return new Bungindi();
	}
};

class WaterFactory : public AEnemyFactory
{
public:
	IFast* GetFast()
	{
		return new Manama();
	}

	ISlow* GetSlow()
	{
		return new Pokili();
	}
};

//CPP File
AEnemyFactory* AEnemyFactory::CreateFactory(Enemy_Factories factory)
{
	if (factory == Enemy_Factories::Land)
	{
		return new LandFactory();
	}
	else if (factory == Enemy_Factories::Air)
	{
		return new AirFactory();
	}
	else if (factory == Enemy_Factories::Water)
	{
		return new WaterFactory();
	}
}

int main(int argc, char* argv[])
{
	AEnemyFactory *factory = AEnemyFactory::CreateFactory
		(AEnemyFactory::Enemy_Factories::Land);

	cout << "Slow enemy of Land: " << factory->GetSlow()->Name() << "\n";
	delete factory->GetSlow(); 
	cout << "Fast enemy of Land: " << factory->GetFast()->Name() << "\n";
	delete factory->GetFast(); 
	delete factory;
	getchar();

	factory = AEnemyFactory::CreateFactory(AEnemyFactory::Enemy_Factories::Air);
	cout << "Slow enemy of Air: " << factory->GetSlow()->Name() << "\n";
	delete factory->GetSlow(); 
	cout << "Fast enemy of Air: " << factory->GetFast()->Name() << "\n";
	delete factory->GetFast(); 
	delete factory;
	getchar();

	factory = AEnemyFactory::CreateFactory(AEnemyFactory::Enemy_Factories::Water);
	cout << "Slow enemy of Water: " << factory->GetSlow()->Name() << "\n";
	delete factory->GetSlow(); 
	cout << "Fast enemy of Water: " << factory->GetFast()->Name() << "\n";
	delete factory->GetFast(); 
	getchar();

	return 0;
}
