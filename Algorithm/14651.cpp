#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
	}
	else if (n == 2)
	{
		cout << 2;
	}
	else
	{
		long long ret = 2;
		for (int i = 2; i < n; ++i)
		{
			ret *= 3;
			ret = ret % 1000000009;
		}
		cout << ret;
	}

	return 0;
}