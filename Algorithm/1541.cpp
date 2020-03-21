#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int opCnt = 0;
	int minusPos = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			opCnt++;
			if (s[i] == '-' && minusPos == -1)
			{
				minusPos = opCnt;
			}
		}
	}

	stringstream ss(s);
	int a;
	int sum = 0;
	int i = 0;
	while (ss >> a)
	{
		if (minusPos!= -1 && i >= minusPos)
		{
			sum -= a;
		}
		else
		{
			sum += a;
		}

		i++;
		if (opCnt < i)
		{
			break;
		}
		char c;
		ss >> c;
	}

	cout << sum;

	return 0;
}