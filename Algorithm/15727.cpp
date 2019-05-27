#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int t = n / 5;
	if (n % 5 == 0)
	{
		cout << t;
	}
	else
	{
		cout << t + 1;
	}

	return 0;
}