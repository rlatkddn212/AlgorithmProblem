#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 0;
	for (int i = 1; i * i <= n; ++i)
	{
		num++;
	}

	cout << num;

	return 0;
}