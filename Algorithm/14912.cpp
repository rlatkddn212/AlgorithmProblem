#include <iostream>
using namespace std;
int main()
{
	int n, d;
	cin >> n >> d;

	int ret = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a = i;
		while (a)
		{
			int t = a % 10;
			if (t == d)
			{
				ret += 1;
			}

			a /= 10;
		}
	}

	cout << ret;
	return 0;
}