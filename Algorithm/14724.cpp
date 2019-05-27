#include <iostream>
#include <string>
using namespace std;

string arr[9] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

int main()
{
	int t;
	cin >> t;

	int ret = 0;
	int team = 0;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < t; ++j)
		{
			int a;
			cin >> a;

			if (ret < a)
			{
				ret = a;
				team = i;
			}
		}
	}

	cout << arr[team];
	return 0;
}