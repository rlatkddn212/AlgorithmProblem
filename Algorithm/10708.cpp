#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> tg(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> tg[i];
	}

	vector<int> v(n, 0);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			if (tg[i] == a)
			{
				v[j]++;
			}
			else
			{
				v[tg[i] - 1]++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << v[i] << endl;
	}

	return 0;
}