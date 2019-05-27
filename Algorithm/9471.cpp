#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i;
		int m;
		cin >> i >> m;

		int ret = 0;

		int a = 1;
		int b = 1;
		int c = 0;
		while (true)
		{
			int temp = a;
			a = b;
			b = (b + temp) % m;
			c++;
			if (a == 1 && b == 1)break;
		}


		cout << i << " " << c << "\n";
	}

	return 0;
}