#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double a, b, c;

	cin >> c >> a >> b;
	cout << (int)(a * sqrt((c * c) / ((a * a) + (b * b)))) << ' ' << (int)(b * sqrt((c * c) / ((a * a) + (b * b))));

	return 0;
}