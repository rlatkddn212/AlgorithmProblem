#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b;
	cin >> a >> b;

	int ret = gcd(a, b);

	for (int i = 0; i < ret; ++i)
	{
		cout << 1;
	}

	return 0;
}