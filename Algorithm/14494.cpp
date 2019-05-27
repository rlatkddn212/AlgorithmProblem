#include <iostream>
#include <string.h>
using namespace std;
int n, m;
int cache[1001][1001];
const int mod = 1000000007;
int dy[3] = {0, 1, 1};
int dx[3] = {1,0, 1};
int func(int y, int x)
{
	if (y == n - 1 && x == m - 1)return 1;


	int& ret = cache[y][x];
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	for (int i = 0; i < 3; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < n&& nx < m)
		{
			ret = (ret + func(ny, nx)) % mod;
		}
	}

	return ret;
}

int main()
{
	memset(cache, -1, sizeof(cache));

	cin >> n >> m;
	cout << func(0,0) % mod;

	return 0;
}