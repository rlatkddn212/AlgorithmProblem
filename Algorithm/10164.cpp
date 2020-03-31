#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstring>
#include <set>
#include <stdio.h>
#include <functional>
#include <tuple>
#include <queue>
#include <map>
using namespace std;

int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };
long long cache[16][16];
long long func(int y, int x, int ey, int ex)
{
	if (y == ey && x == ex)
		return 1;

	long long& ret = cache[y][x];

	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int i = 0; i < 2; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny <= ey && nx <= ex) 
		{
			ret += func(ny, nx, ey, ex);
		}
	}
	return ret;
}

int main()
{
	int n;
	int m;
	int k;
	cin >> n >> m >> k;
	if (k == 0)
	{
		memset(cache, -1, sizeof(cache));
		cout << func(0, 0, n - 1, m - 1);
		return 0;
	}
	int t = 0;
	int ty = (k - 1) / m;
	int tx = (k - 1) % m;
	memset(cache, -1, sizeof(cache));
	cout << func(0, 0, ty, tx) * func(ty, tx, n - 1, m - 1);

	return 0;
}
