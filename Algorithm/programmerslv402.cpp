#include <iostream>
using namespace std;

int func(int n, int one)
{
	if (n < 1) return 0;
	if (n < pow(3, one / 2)) return 0;
	if (n == 3 && one == 2) return 1;

	int ret = 0;
	ret += func(n - 1, one + 1);
	if (n % 3 == 0 && one >= 2)
		ret += func(n / 3, one - 2);

	return ret;
}

int solution(int n) 
{
	int answer = func(n, 0);
	return answer;
}

int main()
{
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}