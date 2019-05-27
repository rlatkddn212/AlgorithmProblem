#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	// 2 ~ 15개 서로 다른 자연수 자신의 2배인 수의 개수
	// 즉 2로 나눠 떨어지는 수

	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		int a;
		int ret = 0;
		vector<int> v;
		while (ss >> a)
		{
			if (a == -1) return 0;
			if (a != 0)
				v.push_back(a);
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] % 2 != 0)continue;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] == v[i] / 2)
				{
					ret += 1;
				}
			}
		}

		cout << ret << "\n";
	}

	return 0;
}