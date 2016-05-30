#include <iostream>
#include <conio.h>

using namespace std;

typedef struct LinkedList {
	int LevelNumber;
	LinkedList * next;
} LinkedList;

int main() {
	LinkedList * head = NULL;
	int i;
	for (i = 1; i <= 10; i++) {
		LinkedList * currentNode = new LinkedList;
		currentNode->LevelNumber = i;
		currentNode->next = head;
		head = currentNode;
	}
	while (head) {
		cout << head->LevelNumber << " ";
		head = head->next;
	}
	_getch();
	return 0;
}