#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k = 0;
	while (n >= 10)
	{
		int ret  = n;
		int sum = 1;
		while (ret)
		{
			sum *= ret % 10;
			ret /= 10;
		}
		n = sum;
		k++;
	}
	cout << k;

	return 0;
}