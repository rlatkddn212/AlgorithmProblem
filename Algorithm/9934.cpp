#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int k = pow(2, n) - 1;
	vector<int> v(k);

	for (int i = 0; i < k; ++i)
	{
		cin >> v[i];
	}
	int root = k / 2;

	for (int i = 0; i < n; ++i)
	{
		int diff = 0;
		for (int j = 0; j < pow(2, i); ++j)
		{
			cout << v[root + diff] << " ";
			diff += root * 2 + 2;
		}
		root /= 2;
		cout << "\n";
	}

	return 0;
}