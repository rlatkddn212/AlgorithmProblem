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
#include <stack>

using namespace std;
const int MAX_V = 501;
const int INF = 987654321;
int V;
vector <pair<int, int> > g[MAX_V];

vector<int> bellmanFord(int src)
{
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	for (int it = 0; it < V; ++it)
	{
		updated = false;
		for (int here = 0; here < V; ++here)
		{
			if (upper[here] == INF) continue;
			for (int i = 0; i < g[here].size(); ++i)
			{
				int there = g[here][i].first;
				int cost = g[here][i].second;

				if (upper[there] > upper[here] + cost)
				{
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}

	if (updated) upper.clear();
	return upper;
}


int main()
{
	int m;
	scanf("%d %d", &V, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, value;
		scanf("%d %d %d", &a, &b, &value);
		g[a - 1].push_back(make_pair(b - 1, value));
	}
	vector<int> ret = bellmanFord(0);
	if (ret.empty())
	{
		cout << -1;
	}
	else
	{
		for (int i = 1; i < ret.size(); ++i)
		{
			if (ret[i] == INF)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << ret[i] << '\n';
			}
		}
	}
	return 0;
}
