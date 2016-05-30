

#include<iostream>
#include <conio.h>

using namespace std;

// This is a ternary operation to check which of the expression is higher of the two 
int maximum(int x, int y) { return (x > y) ? x : y; }


int AIInventorySack(int TotalWeight, int individual_weight[], int individual_value[], int size)
{
	
	if (size == 0 || TotalWeight == 0)
		return 0;
	else if (individual_weight[size - 1] > TotalWeight)
		return AIInventorySack(TotalWeight, individual_weight, individual_value, size - 1);
	else return maximum(individual_value[size - 1] + AIInventorySack(TotalWeight - individual_weight[size - 1], individual_weight, individual_value, size - 1),
		AIInventorySack(TotalWeight, individual_weight, individual_value, size - 1)
		);
}


int main()
{
	int individual_value[] = { 60, 100, 120 };
	int individual_weight[] = { 10, 25, 40 };
	int  TotalWeight = 60;
	int size = sizeof(individual_value) / sizeof(individual_weight[0]);
	cout << "Total value of sack " << AIInventorySack(TotalWeight, individual_weight, individual_value, size);

	_getch();
	return 0;
}

