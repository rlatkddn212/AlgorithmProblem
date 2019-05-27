#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int era[1299801];

int main() {
	for (int i = 2; i*i <= 1299800; ++i) {
		if (era[i] == 0) {
			for (int j = i + i; j <= 1299800; j += i) {
				era[j] = 1;
			}
		}
	}

	vector<int> v;
	for (int i = 2; i <= 1299800; ++i) {
		if (!era[i]) {
			v.push_back(i);
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int c;
		cin >> c;
		vector<int>::iterator low = lower_bound(v.begin(), v.end(), c);
		if (*low == c || c == 1)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << *low - *(low - 1) << '\n';
		}
	}
	
	return 0;
}