#include <iostream>
using namespace std;

int main()
{
	int n;
	int m;
	cin >> n >> m;
	int arr[101];
	int t = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		t += a;
		arr[i] = t;
	}

	for (int i = 0; i < m; ++i)
	{
		int b;
		cin >> b;

		for (int j = 0; j < n; ++j)
		{

			if (b < arr[j])
			{
				cout << j + 1 << "\n";
				break;
			}
		}
	}

	return 0;
}