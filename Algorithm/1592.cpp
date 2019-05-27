#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, l;

	cin >> n >> m >> l;

	vector<int> v(n, 0);

	int idx = 0;
	v[0] = 1;
	int d = 1;
	int count = 1;
	while (true)
	{
		idx = idx + d * l;
		if (idx < 0)
		{
			idx += n;
		}
		else if (idx >= n)
		{
			idx -= n;
		}

		v[idx]++;
		if (v[idx] == m)
		{
			break;
		}

		count++;
		if (v[idx] % 2 == 0)
		{
			d = -1;
		}
		else
		{
			d = 1;
		}
	}

	cout << count;

	return 0;
}