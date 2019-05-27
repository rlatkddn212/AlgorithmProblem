#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int c, k, p;
	cin >> c >> k >> p;

	int ret = 0;
	for (int i = 1; i <= c; ++i)
	{
		ret += i * k + p * i*i;
	}

	cout << ret;
	return 0;
}