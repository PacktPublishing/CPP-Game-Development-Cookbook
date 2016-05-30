#include <iostream>
#include <string>
#include <map>
#include <conio.h>

using namespace std;


class TreeType
{
public:
	virtual void Display(int size) = 0;

protected:
	//Some Model we need to assign.For relevance we are substituting this with a character symbol
	char symbol_;
	int width_;
	int height_;
	float color_;
	
	int Size_;
};


class TreeTypeA : public TreeType
{
public:
	TreeTypeA()
	{
		symbol_ = 'A';
		width_ = 94;
		height_ = 135;
		color_ = 0;
		
		Size_ = 0; 
	}
	void Display(int size)
	{
		Size_ = size;
		cout << "Size of " << symbol_ << " is :" << Size_ << endl;
	}
};


class TreeTypeB : public TreeType
{
public:
	TreeTypeB()
	{
		symbol_ = 'B';
		width_ = 70;
		height_ = 25;
		color_ = 0;

		Size_ = 0; 
	}
	void Display(int size)
	{
		Size_ = size;
		cout << "Size of " << symbol_ << " is :" << Size_ << endl;
	}
};

class TreeTypeZ : public TreeType
{
public:
	TreeTypeZ()
	{
		symbol_ = 'Z';
		width_ = 20;
		height_ = 40;
		color_ = 1;

		Size_ = 0; 
	}
	void Display(int size)
	{
		Size_ = size;
		cout <<"Size of " << symbol_ << " is :" << Size_ << endl;
	}
};

// The 'FlyweightFactory' class
class TreeTypeFactory
{
public:
	virtual ~TreeTypeFactory()
	{
		while (!TreeTypes_.empty())
		{
			map<char, TreeType*>::iterator it = TreeTypes_.begin();
			delete it->second;
			TreeTypes_.erase(it);
		}
	}
	TreeType* GetTreeType(char key)
	{
		TreeType* TreeType = NULL;
		if (TreeTypes_.find(key) != TreeTypes_.end())
		{
			TreeType = TreeTypes_[key];
		}
		else
		{
			switch (key)
			{
			case 'A':
				TreeType = new TreeTypeA();
				break;
			case 'B':
				TreeType = new TreeTypeB();
				break;
				//...
			case 'Z':
				TreeType = new TreeTypeZ();
				break;
			default:
				cout << "Not Implemented" << endl;
				throw("Not Implemented");
			}
			TreeTypes_[key] = TreeType;
		}
		return TreeType;
	}
private:
	map<char, TreeType*> TreeTypes_;
};


//The Main method
int main()
{
	string forestType = "ZAZZBAZZBZZAZZ";
	const char* chars = forestType.c_str();

	TreeTypeFactory* factory = new TreeTypeFactory;

	// extrinsic state
	int size = 10;

	// For each TreeType use a flyweight object
	for (size_t i = 0; i < forestType.length(); i++)
	{
		size++;
		TreeType* TreeType = factory->GetTreeType(chars[i]);
		TreeType->Display(size);
	}

	//Clean memory
	delete factory;

	_getch();
	return 0;
}