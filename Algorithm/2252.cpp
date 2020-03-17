#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr[32002];
bool visited[32002] = { false, };
void func(int k, vector<int>& out)
{
	visited[k] = true;
	for (int i = 0; i < arr[k].size(); ++i)
	{
		if (!visited[arr[k][i]])
		{
			func(arr[k][i], out);
		}
	}

	out.push_back(k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}

	vector<int> out;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			func(i, out);
		}
	}

	vector<int>::reverse_iterator outIter = out.rbegin();
	for (; outIter != out.rend(); ++outIter)
	{
		cout << *outIter << ' ';
	}

	return 0;
}