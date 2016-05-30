#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers{ 4,8,9,9,77,8,11,2,7 };
	int b = 10;
	for_each(numbers.begin(), numbers.end(), [=](int y) mutable->void { if(y>b) cout<<  y<<endl;  });

	int a;
	cin >> a;

}