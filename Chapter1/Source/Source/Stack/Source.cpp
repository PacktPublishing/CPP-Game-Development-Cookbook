#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


class Stack
{
private:
	string UI_Elements[10];
	int top;
public:
	Stack()
	{
		top = -1;
	}

	void Push(string element)
	{
		if (top >= 10)
		{
			cout << "Some error occured";
		}
		UI_Elements[++top] = element;
	}

	string Pop()
	{
		if (top == -1)
		{
			cout << "Some error occured";
		}
		return UI_Elements[top--];
	}

	string Top()
	{
		return UI_Elements[top];
	}

	int Size()
	{
		return top + 1;
	}

	bool isEmpty()
	{
		return (top == -1) ? true : false;
	}
};

int main()
{
		Stack _stack;

		if (_stack.isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		// Push elements    
		_stack.Push("UI_Element1");
		_stack.Push("UI_Element2");
		// Size of stack
		cout << "Size of stack = " << _stack.Size() << endl;
		// Top element    
		cout << _stack.Top() << endl;
		// Pop element    
		cout << _stack.Pop() << endl;
		// Top element    
		cout << _stack.Top() << endl;


		_getch();
		return 0;
	}
