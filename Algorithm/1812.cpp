#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}

	sum /= 2;
	int t = 0;
	for (int i = 0; i < n; ++i)
	{
		t = 0;
		for (int j = 1; j < n; j += 2)
		{
			t += v[(i + j) % n];
		}

		cout << sum - t << "\n";
	}
	return 0;
}