#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a;
	int ret = 0;
	while (cin >> a)
	{
		if (a > 0)
		{
			ret++;
		}
	}
	cout << ret;
}