#include <iostream>
#include <vector>
using namespace std;


int func(vector<vector<int>>& v, int idx, int k)
{
	if (idx == k)
	{
		return 0;
	}

	if (idx != 0 && v[idx].size() == 1 && k == v[idx][0])
	{
		return 1;
	}

	if (v[idx].empty())
	{
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < v[idx].size(); ++i)
	{
		ret += func(v, v[idx][i], k);
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;
	n++;
	vector<vector<int>> v(n);
	for (int i = 1; i < n; ++i)
	{
		int a;
		cin >> a;
		a++;
		v[a].push_back(i);
	}

	int k;
	cin >> k;

	cout << func(v, 0, k + 1);

	return 0;
}