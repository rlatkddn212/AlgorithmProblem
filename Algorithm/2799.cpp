#include <iostream>
using namespace std;

char arr[600][600];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n * 5 + 1; ++i)
	{
		for (int j = 0; j < m * 5 + 1; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int v[5] = { 0,0,0,0,0 };

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int y = 1 + 5 * i;
			int x = 1 + 5 * j;
			int c = 0;
			for (int k = 0; k < 4; ++k)
			{
				if (arr[y+k][x] == '*')
				{
					c++;
				}
			}

			v[c]++;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << v[i] << " ";
	}


	return 0;
}