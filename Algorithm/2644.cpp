#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& v, int a, int b)
{
	vector<int> dist(v.size(), -1);
	queue<int> q;
	q.push(a);
	dist[a] = 0;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < v[here].size(); ++i)
		{
			int there = v[here][i];
			if (there == b)
			{
				return dist[here] + 1;
			}

			if (dist[there] == -1)
			{
				dist[there] = dist[here] + 1;
				q.push(there);
			}
		}
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>());

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int c, d;
		cin >> c >> d;
		v[c - 1].push_back(d - 1);
		v[d - 1].push_back(c - 1);
	}

	cout << bfs(v, a- 1, b - 1);

	return 0;
}