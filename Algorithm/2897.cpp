#include <iostream>
#include <vector>
using namespace std;

char arr[51][51];
int dy[4] = {0, 0, 1, 1};
int dx[4] = { 0, 1, 0, 1 };
int main()
{
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> ret(5, 0);
	
	for (int i = 0; i < r - 1; ++i)
	{
		for (int j = 0; j < c - 1; ++j)
		{
			bool isBuilding = false;
			int count = 0;
			
			for (int k = 0; k < 4; ++k)
			{
				int ni = dy[k] + i;
				int nj = dx[k] + j;
				if (arr[ni][nj] == '#')
				{
					isBuilding = true;
					break;
				}
				else if (arr[ni][nj] == 'X')
				{
					count++;
				}
			}

			if (!isBuilding)
			{
				ret[count]++;
			}
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << ret[i] << '\n';
	}
}