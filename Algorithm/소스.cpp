#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstring>
#include <set>
#include <stdio.h>
#include <functional>
#include <tuple>
#include <queue>
#include <stack>
#include <map>

using namespace std;
const int MAX_N = 1001;
#define uint64 unsigned long long

const int INF = 987654321;
int arr[MAX_N][MAX_N];

void floyd(int n) {
	for (int i = 0; i < n; i++) {
		arr[i][i] = 0;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[a - 1][b - 1] = 1;
	}

	floyd(n);
	int ret = n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == INF && arr[j][i] == INF)
			{
				ret--;
				break;
			}
		}
	}

	cout << ret << endl;

	return 0;
}