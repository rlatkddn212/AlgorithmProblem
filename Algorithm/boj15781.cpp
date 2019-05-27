#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char arr[10001][10001];

void func(int y, int x, int n)
{
	if (n == 1)
	{
		arr[y][x] = '*';
		return;
	}

	for (int i = x; i < x + 4 * (n - 1) + 1; ++i)
	{
		arr[y][i] = '*';
	}

	for (int i = y + 1; i < y + 4 * (n - 1) + 1; ++i)
	{
		arr[i][x] = '*';
		arr[i][x + 4 * (n - 1)] = '*';
	}

	for (int i = x; i < x + 4 * (n - 1) + 1; ++i)
	{
		arr[y + 4 * (n - 1)][i] = '*';
	}

	func(y + 2, x + 2, n - 1);
}

void printArr(int n)
{
	for (int i = 0; i < 4 * (n - 1) + 1; ++i)
	{
		for (int j = 0; j < 4 * (n - 1) + 1; ++j)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	memset(arr, ' ', sizeof(arr));
	func(0, 0, n);
	printArr(n);

	return 0;
}