#include <iostream>
#include <conio.h>

using namespace std;

void printMaxActivities(int start_Time[], int finish_Time[], int n)
{
	int i, j;	
	i = 0;
	cout << i;
	for (j = 1; j < n; j++)
	{		
		if (start_Time[j] >= finish_Time[i])
		{
			cout << j;
			i = j;
		}
	}
}


int main()
{
	int start_Time[] = { 0, 2, 4, 7, 8, 11 };
	int finish_Time[] = { 7, 4, 6, 7, 9, 9 };
	int n = sizeof(start_Time) / sizeof(start_Time[0]);
	printMaxActivities(start_Time, finish_Time, n);

	_getch();
	return 0;
}
