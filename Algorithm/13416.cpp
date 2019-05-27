#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			int m = 0;
			for (int j = 0; j < 3; ++j)
			{
				int a;
				cin >> a;
				m = max(m, a);
			}
			ret += m;
		}

		cout << ret << "\n";
	}

	return 0;
}