#include <iostream>
#include <string.h>
using namespace std;

int arr[1050][1050];
int cache[1050][1050];
int n;

int sum(int y1, int x1)
{
	return cache[y1][x1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int  k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	memset(cache, 0, sizeof(cache));
	for (int i = n - 1; i >= 0; --i)
	{
		int sum = 0;
		for (int j = n - 1; j >= 0; --j)
		{
			cache[i][j] = arr[i][j] + cache[i + 1][j] + sum;
			sum += arr[i][j];
		}
	}

	for (int i = 0; i < k; ++i)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1;

		cout << sum(y1, x1) + sum(y2 + 1, x2 + 1) - sum(y2 + 1, x1) - sum(y1, x2 + 1)   <<"\n";
	}

	return 0;
}