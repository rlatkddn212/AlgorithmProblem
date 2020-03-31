#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	cin >> n >> k;
	vector<tuple<int, int, int>> v;
	tuple<int, int, int> t;
	//int tg, ts, tb;
	for (int i = 0; i < n; ++i)
	{
		int a, g, s, b;
		cin >> a >> g >> s >> b;
		if (a == k)
		{
			t = make_tuple(-g, -s, -b);
		}
		v.push_back(make_tuple(-g, -s, -b));
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == t) 
		{
			cout << i + 1;
			break;
		}
	}

	return 0;
}