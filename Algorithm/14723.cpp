#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 1;
	int a = 0;
	int c = 1;
	while(true)
	{
		if (n <= num + a)break;
		a++;
		c++;
		num += a;
		
	}

	cout << c - (n - num) << " " << n - num + 1;

	return 0;
}