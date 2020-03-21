#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
	}

	int m1 = 0;
	int m2 = 0;
	int m3 = 0;
	int m4 = 0;
	
	sort(v.begin(), v.end());
	int sum = 0;
	int cnt = 0;
	int maxcnt = 0;
	int temp = 0;
	int a = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (i == 0)
		{
			temp = v[i];
			cnt = 1;
			m3 = temp;
			maxcnt = cnt;
		}
		else
		{
			if (temp != v[i])
			{
				temp = v[i];
				cnt = 1;
			}
			else
			{
				cnt++;
			}

			if (maxcnt == cnt && a == 0)
			{
				m3 = temp;
				a++;
			}

			if (maxcnt < cnt)
			{
				maxcnt = cnt;
				m3 = temp;
				a = 0;
			}
		}

		sum += v[i];
	}

	m1 = round((float)sum / v.size());
	m2 = v[v.size() / 2];
	m4 = v[v.size() - 1] - v[0];

	printf("%d\n%d\n%d\n%d", m1, m2, m3, m4);

	return 0;
}