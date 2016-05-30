#include <iostream>
#include <conio.h>

using namespace std;


class QueueEmptyException
{
public:
	QueueEmptyException()
	{
		cout << "Queue empty" << endl;
	}
};

class Node
{
public:
	int data;
	Node* next;
};

class ListQueue
{
private:
	Node* front;
	Node* rear;
	int count;

public:
	ListQueue()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}

	void Enqueue(int element)
	{
		// Create a new node
		Node* tmp = new Node();
		tmp->data = element;
		tmp->next = NULL;

		if (isEmpty()) {
			// Add the first element
			front = rear = tmp;
		}
		else {
			// Append to the list
			rear->next = tmp;
			rear = tmp;
		}

		count++;
	}

	int Dequeue()
	{
		if (isEmpty())
			throw new QueueEmptyException();

		int ret = front->data;
		Node* tmp = front;

		// Move the front pointer to next node
		front = front->next;

		count--;
		delete tmp;
		return ret;
	}

	int Front()
	{
		if (isEmpty())
			throw new QueueEmptyException();

		return front->data;
	}

	int Size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0 ? true : false;
	}
};

int main()
{
	ListQueue q;
	try {
		if (q.isEmpty())
		{
			cout << "Queue is empty" << endl;
		}

		// Enqueue elements
		q.Enqueue(100);
		q.Enqueue(200);
		q.Enqueue(300);

		// Size of queue
		cout << "Size of queue = " << q.Size() << endl;

		// Front element
		cout << q.Front() << endl;

		// Dequeue elements
		cout << q.Dequeue() << endl;
		cout << q.Dequeue() << endl;
		cout << q.Dequeue() << endl;
	}
	catch (...) {
		cout << "Some exception occured" << endl;
	}

	_getch();
	return 0;
}