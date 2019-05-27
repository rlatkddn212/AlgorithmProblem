#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		int a;
		cin >> a;
		if (a == 0)break;

		int ret = a;
		while (a / 10 != 0)
		{
			ret = 0;
			while (a)
			{
				ret += a % 10;
				a = a / 10;
			}

			a = ret;
		}
		
		cout << ret << "\n";
	}

	return 0;
}