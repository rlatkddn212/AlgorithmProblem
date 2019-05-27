#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		int score = s[i] - 'A';
		ret += score + 1;
	}

	cout << ret;

	return 0;
}