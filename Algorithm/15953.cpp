#include <iostream>
using namespace std;

int main()
{
	int arr0[6] = { 1, 2, 3, 4, 5, 6 };
	int rewards0[6] = { 5000000, 3000000, 2000000, 500000, 300000, 100000 };
	int arr1[5] = { 1, 2, 4, 8, 16 };
	int rewards1[5] = { 5120000, 2560000, 1280000, 640000, 320000 };
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		int sum = 0;
		int personNum = 0;

		for (int j = 0; j < 6; ++j)
		{
			personNum += arr0[j];
			if (a != 0 && a <= personNum)
			{
				sum += rewards0[j];
				break;
			}
		}

		personNum = 0;
		for (int j = 0; j < 5; ++j)
		{
			personNum += arr1[j];
			if (b != 0 && b <= personNum)
			{
				sum += rewards1[j];
				break;
			}
		}

		cout << sum << "\n";
	}
	return 0;
}