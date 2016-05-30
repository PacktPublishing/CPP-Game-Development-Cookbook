#include <cstdlib>
#include<iostream>
#include <conio.h>
#include <string>

using namespace std;


class node
{
public:
	string data;
	node* next;
};

class StackusingList
{
public:
	StackusingList(int max)
	{
		top = NULL;
		maxnum = max;
		count = 0;
	}

	void push(string element)
	{
		if (count == maxnum)
			cout << "Stack is full" << endl;
		else
		{
			node *newTop = new node;
			if (top == NULL)
			{
				newTop->data = element;
				newTop->next = NULL;
				top = newTop;
				count++;
			}
			else
			{
				newTop->data = element;
				newTop->next = top;
				top = newTop;
				count++;
			}
		}
	}

	void pop()
	{
		if (top == NULL)
			cout << "nothing to pop";
		else
		{
			node * old = top;
			top = top->next;
			count--;
			delete(old);
		}
	}
	void print()
	{
		node *temp;
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data;
			cout << endl;
			temp = temp->next;
		}
	}
private:
	node *top;
	int count; //head
	int maxnum;
	string stackData;
};

int main()
{
	StackusingList *sl = new StackusingList(5);
	sl->push("UI element1");
	sl->push("UI element2");
	sl->push("UI element3");
	sl->push("UI element4");
	sl->push("UI element5");
	sl->push("UI element6");

	sl->pop();
	cout << endl;
	cout << "Stack values in LIFO order";
	cout << endl;
	sl->print();

	_getch();
	return 0;
}