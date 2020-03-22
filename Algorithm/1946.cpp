#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int testcase = 0; testcase < t; ++testcase)
	{
		int n;
		cin >> n;

		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			v[i] = make_pair(a, b);
		}

		sort(v.begin(), v.end());

		int sum = 0;
		int minv = 1000001;
		for (int i = 0; i < n; ++i)
		{
			int k = v[i].second;
			if (minv > k)
			{
				minv = k;
				sum++;
			}
		}

		cout << sum << endl;
	}

	return 0;
}