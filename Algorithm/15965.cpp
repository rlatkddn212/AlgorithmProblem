#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int era[10000001];
int main()
{
	for (int i = 2; i*i <= 10000000; ++i) {
		if (era[i] == 0) {
			for (int j = i + i; j <= 10000000; j += i) {
				era[j] = 1;
			}
		}
	}

	vector<int> v;
	for (int i = 2; i <= 10000000; ++i) {
		if (!era[i]) {
			v.push_back(i);
		}
	}
	int a;
	cin >> a;
	cout << v[a - 1];

	return 0;
}