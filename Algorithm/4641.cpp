#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	// 2 ~ 15�� ���� �ٸ� �ڿ��� �ڽ��� 2���� ���� ����
	// �� 2�� ���� �������� ��

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