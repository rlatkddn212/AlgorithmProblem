#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long dp[51][51][2501];
int dy[4] = { -1 , 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

long long INF = (1LL << 31);

long long func0(int m, int n, vector<vector<int>>& time_map, int s, int y, int x, int d)
{
	if (y == m - 1 && x == n - 1)
	{
		return 0;
	}

	long long& ret = dp[y][x][d];
	if (ret != -1)
	{
		return ret;
	}

	ret = INF;

	for (int i = 0; i < 4; ++i)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (0 <= ny && ny < m && 0 <= nx && nx < n && d > 0 && time_map[ny][nx] != -1)
		{
			long long k = func0(m, n, time_map, s, ny, nx, d - 1) + (long long)time_map[ny][nx];
			if (k <= (long long)s)
			{
				ret = min(ret, k);
			}
		}
	}

	return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map)
{
	int move_distance = 0;
	long long sum_of_talk_time = 0;

	vector<int> answer(2);
	sum_of_talk_time = INF;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 2501; ++i)
	{

		long long minSum = func0(m, n, time_map, s, 0, 0, i);
		if (sum_of_talk_time > minSum)
		{
			sum_of_talk_time = minSum;
			move_distance = i;
			break;
		}
	}

	answer[0] = move_distance;
	answer[1] = sum_of_talk_time;

	return answer;
}

int main()
{
	int m;
	int n;
	int s;
	cin >> m >> n >> s;
	vector<vector<int>> time_map(m);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			cin >> a;
			time_map[i].push_back(a);
		}
	}

	vector<int> ret = solution(m, n, s, time_map);
	
	cout << ret[0] << " " << ret[1];

	return 0;
}