#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int f;
int s;
int g;
int u;
int d;

int visited[1000001];
int counter[1000001];

int bfs() {
	if (s == g)return 0;
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int np;
			if (i == 0) {
				np = here + u;
			}
			else {
				np = here - d;
			}
			if (1 <= np && np <= f && !visited[np]) {
				visited[np] = 1;
				counter[np] = counter[here] + 1;
				if (np == g)return counter[np];
				q.push(np);
			}

		}
	}
	return -1;
}

int main() {
	cin >> f >> s >> g >> u >> d;
	int ret = bfs();
	if (ret == -1) {
		cout << "use the stairs";
	}
	else {
		cout << ret;
	}
	return 0;
}