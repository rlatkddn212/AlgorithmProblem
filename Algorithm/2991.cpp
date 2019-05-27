#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i < 3; ++i)
	{
		int ret = 0;
		int t = arr[i] % (a + b);
		if (0 < t && t <= a)
		{
			ret++;
		}

		t = arr[i] % (c + d);
		if (0 < t && t <= c)
		{
			ret++;
		}

		cout << ret << '\n';
	}
	
	return 0;
}