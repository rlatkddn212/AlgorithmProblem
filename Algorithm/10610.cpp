#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <map>
#include <unordered_map>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	sort(s.rbegin(), s.rend());
	if (s[s.size() - 1] != '0')
	{
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < s.size() - 1; ++i)
	{
		sum += s[i] - '0';
	}

	if (sum % 3 == 0)
	{
		cout << s;
	}
	else
	{
		cout << -1;
	}

	return 0;
}