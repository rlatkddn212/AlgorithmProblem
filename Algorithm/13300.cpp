#include <iostream>
using namespace std;

int arr[6][2];

int main()
{
	int n , k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[b-1][a]++;
	}

	int ret = 0;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			ret += arr[i][j] / k + ((arr[i][j] %k == 0)?0:1);
		}
	}

	cout << ret;
	return 0;
}