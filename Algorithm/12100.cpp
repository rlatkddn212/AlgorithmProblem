#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ret = 0;

int n;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0 , 0 };

void printTable(vector<vector<int>>& v)
{
	return;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

void moveBlock(vector<vector<int>>& v, int y, int x, int d, int& mergedPosY, int& mergedPosX)
{
	int ny = y;
	int nx = x;
	int c = 0;
	while (true)
	{
		if ((ny == 0 && d == 2)
			|| (ny == n - 1 && d == 3)
			|| (nx == 0 && d == 0)
			|| (nx == n - 1 && d == 1))
		{
			v[ny][nx] = v[y][x];
			v[y][x] = 0;
			break;
		}

		ny = dy[d] + ny;
		nx = dx[d] + nx;

		if (v[y][x] == v[ny][nx] && (!(mergedPosX == nx && mergedPosY == ny)))
		{
			mergedPosX = nx;
			mergedPosY = ny;
			v[ny][nx] *= 2;
			v[y][x] = 0;
			break;
		}
		else if (v[ny][nx] != 0)
		{
			if (c != 0)
			{
				v[ny - dy[d]][nx - dx[d]] = v[y][x];
				v[y][x] = 0;
			}
			break;
		}

		c++;
	}
}

void moveTable(vector<vector<int>>& v, int d)
{
	int mergedPosY = -1;
	int mergedPosX = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (d == 0) // 왼쪽
			{
				if (v[i][j] == 0)continue;
				moveBlock(v, i, j, d, mergedPosY, mergedPosX);
				//printTable(v);
			}
			else if (d == 1) // 오른쪽
			{
				if (v[i][n - j - 1] == 0)continue;
				moveBlock(v, i, n - j - 1, d, mergedPosY, mergedPosX);
				//printTable(v);
			}
			else if (d == 2) // 위쪽
			{
				if (v[j][i] == 0)continue;
				moveBlock(v, j, i, d, mergedPosY, mergedPosX);
				//printTable(v);

			}
			else if (d == 3) // 아래쪽
			{
				if (v[n - j - 1][i] == 0)continue;
				moveBlock(v, n - j - 1, i, d, mergedPosY, mergedPosX);
				//printTable(v);
			}
		}
	}
}

int test[5] = { 0 ,1,3,3,0 };

void func(vector<vector<int>>& v, int k)
{
	if (k == 0)
	{
		// table을 확인한다.
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				ret = max(ret, v[i][j]);
			}
		}

		return;
	}

	//int i = 3;
	for (int i = 0; i < 4; ++i)
	{
		vector<vector<int>> v2(n, vector<int>(n));
		for (int j = 0; j < n; ++j)
		{
			copy(v[j].begin(), v[j].end(), v2[j].begin());
		}

		// 처리
		moveTable(v2, i);
		//printTable(v2);
		//cout << "\n";
		func(v2, k - 1);
	}
}

int main()
{

	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	func(v, 5);
	cout << ret;

	return 0;
}