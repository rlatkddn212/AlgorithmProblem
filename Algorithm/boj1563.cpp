#include <iostream>
#include <string.h>
using namespace std;

///���� ��ġ, � ��������, ���� ����ߴ���
int cache[1001][3][2];
int N;
int Sang(int idx, int state, int k)
{
	if(idx == N)
	{
		return 1;
	}
	int& ret = cache[idx][state][k];
	if(ret != -1)
	{
		return ret;
	}
	ret = 0;
	
	///s1 �⼮!
	ret += Sang(idx+1, 0, k);
	///s2 ����
	if(k == 0)
	{
		ret += Sang(idx+1, 0, k + 1);
	}
	///s3 �Ἦ
	if(state < 2)
	{
		ret += Sang(idx+1, state + 1, k);
	}
	return ret%1000000;
}

int main()
{
	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout << Sang(0, 0, 0);

	return 0;
}