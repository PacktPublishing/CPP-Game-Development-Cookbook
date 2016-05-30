#include "HashTable.h"
#include <conio.h>

int main()
{
	// Create 26 Items to store in the Hash Table.
	Item * A = new Item{ "Enemy1", NULL };
	Item * B = new Item{ "Enemy2", NULL };
	Item * C = new Item{ "Enemy3", NULL };
	Item * D = new Item{ "Enemy4", NULL };
	Item * E = new Item{ "Enemy5", NULL };
	Item * F = new Item{ "Enemy6", NULL };
	Item * G = new Item{ "Enemy7", NULL };
	Item * H = new Item{ "Enemy8", NULL };
	Item * I = new Item{ "Enemy9", NULL };
	Item * J = new Item{ "Enemy10", NULL };
	Item * K = new Item{ "Enemy11", NULL };
	Item * L = new Item{ "Enemy12", NULL };
	Item * M = new Item{ "Enemy13", NULL };
	Item * N = new Item{ "Enemy14", NULL };
	Item * O = new Item{ "Enemy15", NULL };
	Item * P = new Item{ "Enemy16", NULL };
	Item * Q = new Item{ "Enemy17", NULL };
	Item * R = new Item{ "Enemy18", NULL };
	Item * S = new Item{ "Enemy19", NULL };
	Item * T = new Item{ "Enemy20", NULL };
	Item * U = new Item{ "Enemy21", NULL };
	Item * V = new Item{ "Enemy22", NULL };
	Item * W = new Item{ "Enemy23", NULL };
	Item * X = new Item{ "Enemy24", NULL };
	Item * Y = new Item{ "Enemy25", NULL };
	Item * Z = new Item{ "Enemy26", NULL };

	// Create a Hash Table of 13 Linked List elements.
	HashTable table;

	// Add 3 Items to Hash Table.
	table.insertItem(A);
	table.insertItem(B);
	table.insertItem(C);
	table.printTable();
	

	// Remove one item from Hash Table.
	table.removeItem("Enemy3");
	table.printTable();
	


	// Add 23 items to Hash Table.
	table.insertItem(D);
	table.insertItem(E);
	table.insertItem(F);
	table.insertItem(G);
	table.insertItem(H);
	table.insertItem(I);
	table.insertItem(J);
	table.insertItem(K);
	table.insertItem(L);
	table.insertItem(M);
	table.insertItem(N);
	table.insertItem(O);
	table.insertItem(P);
	table.insertItem(Q);
	table.insertItem(R);
	table.insertItem(S);
	table.insertItem(T);
	table.insertItem(U);
	table.insertItem(V);
	table.insertItem(W);
	table.insertItem(X);
	table.insertItem(Y);
	table.insertItem(Z);
	table.printTable();


	// Look up an item in the hash table
	Item * result = table.getItemByKey("Enemy4");
	if (result!=nullptr)
	cout << endl<<"The next key is "<<result->next->key << endl;

	_getch();
	return 0;
}