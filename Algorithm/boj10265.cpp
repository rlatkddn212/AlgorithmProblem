#include <string.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;

//노드에 번호를 매긴다.
vector<int> nodeNumber;
//강결합 컴포넌트로 분리됨
vector<int> sccId;
stack<int> s;
int nodeCounter;
int sccCounter;

int scc(int here)
{
	int ret = nodeCounter;
	nodeNumber[here] = nodeCounter;
	nodeCounter++;
	s.push(here);

	for (int i = 0; i < adj[here].size(); i++)
	{
		//인접리스트를 가져옴
		int there = adj[here][i];
		//아직 발견 못한 트리 간선일경우
		if (nodeNumber[there] == -1)
		{
			//자를 위치를 찾는다.
			ret = min(ret, scc(there));
		}
		//교차 간선을 처리해준다..
		else if (sccId[there] == -1)
		{
			ret = min(ret, nodeNumber[there]);
		}
	}

	//scc의 루트 노드라면 자른다.
	if (nodeNumber[here] == ret)
	{
		while (true)
		{
			int t = s.top();
			s.pop();
			sccId[t] = sccCounter;
			if (t == here)
			{
				break;
			}
		}

		sccCounter++;
	}

	return ret;
}

vector<int> tarjan()
{
	nodeCounter = 0;
	sccCounter = 0;
	nodeNumber.clear();
	sccId.clear();

	nodeNumber = vector<int>(adj.size(), -1);
	sccId = vector<int>(adj.size(), -1);
	for (int i = 0; i < adj.size(); i++)
	{
		if (nodeNumber[i] == -1)
		{
			scc(i);
		}
	}

	return sccId;
}

int cache[1002][1002];

int dfs(const vector<pair<int, int> >& mmax, int m, int idx)
{
	int& ret = cache[m][idx];
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	for (int i = idx + 1; i < mmax.size(); ++i)
	{
		ret = max(ret, dfs(mmax, m, i));
		for (int j = mmax[idx].first; j <= mmax[idx].second; ++j)
		{
			if (m - j >= 0)
			{
				ret = max(ret, dfs(mmax, m - j, i) + j);
			}
			else
			{
				break;
			}
		}
	}

	return ret;
}

int visited[1001];
int findScc(vector<pair<int, int> >& mmax, vector<int>& label, int idx)
{
	if (visited[idx] != -1) return visited[idx];
	if (mmax[label[idx]].first != 0) return label[idx];
	int k = findScc(mmax, label, adj[idx][0]);
	visited[idx] = k;

	return k;
}

void solve(int m)
{
	vector<int> label = tarjan();
	// sort(label.begin(), label.end());
	int n = 0;
	for (int i = 0; i < label.size(); ++i)
	{
		n = max(n, label[i]);
	}
	
	vector<vector<int> > v(n + 1);
	for (int i = 0; i < label.size(); ++i)
	{
		v[label[i]].push_back(i);
	}

	vector<pair<int, int> > mmax(n + 1);

	for (int i = 0; i < n + 1; ++i)
	{
		if (v[i].size() != 1)
		{
			mmax[i].first = v[i].size();
			mmax[i].second = v[i].size();
		}
		else
		{
			if (v[i][0] == adj[v[i][0]][0])
			{
				mmax[i].first = v[i].size();
				mmax[i].second = v[i].size();
			}
		}
	}

	memset(visited, -1, sizeof(visited));
	for (int i = 0; i < n + 1; ++i)
	{
		if (mmax[i].second == 0)
		{
			// 연결된 강결합 컴포넌트를 찾는다.
			int sccNum = findScc(mmax, label, v[i][0]);
			mmax[sccNum].second += 1;
		}
	}

	int ret = 0;
	//ret = max(ret, dfs(mmax, m, 0));

	memset(cache, 0, sizeof(cache));
	for (int i = m; i >= 0; --i)
	{
		for (int idx = n; idx >= 0; --idx)
		{
			cache[i][idx] = max(cache[i][idx], cache[i][idx + 1]);
			for (int j = mmax[idx].first; j <= mmax[idx].second; ++j)
			{
				if (i - j >= 0)
				{
					// f(m, i) = max(f(m, i + 1), f(m - j, i + 1) + j)
					cache[i - j][idx] = max(cache[i - j][idx], cache[i][idx + 1] + j);
				}
				else
				{
					break;
				}
			}

		}
	}

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			ret = max(ret, cache[i][j]);
		}
	}

	cout << ret;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;

	adj.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		adj[i].push_back(a - 1);
	}

	solve(m);

	return 0;
}