#include <iostream>
using namespace std;

int main()
{
	int n;
	int k;
	cin >> n >> k;

	int ret = 0;
	for (int i = 0; i < k; ++i)
	{
		int a;
		cin >> a;

		ret += (a + 1) / 2;
	}
	
	cout << ((ret - n >= 0)?"YES" : "NO");
	return 0;
}