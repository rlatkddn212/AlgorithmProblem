#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0 ,-1, 1, 0};
int visited[101][101];

int solution(vector<vector<int> > maps)
{
	memset(visited, -1, sizeof(visited));
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = 0;

	while (q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (0 <= ny && ny < maps.size() && 0 <= nx && nx < maps[0].size() && visited[ny][nx] == -1)
			{
				
				visited[ny][nx] = visited[p.first][p.second] + 1;
				if (ny == maps.size() - 1 && nx == maps[0].size() - 1)
				{
					return visited[ny][nx];
				}

				q.push(make_pair(ny, nx));
			}
		}
	}

	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > maps(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int a;

			cin >> a;
			maps[i].push_back(a);
		}
	}

	solution(maps);

	return 0;
}