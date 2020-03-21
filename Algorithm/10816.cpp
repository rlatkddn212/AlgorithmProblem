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
#include <sstream>
#include <map>
#include <unordered_set>
using namespace std;


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int m;
	cin >> n;
	
	vector<int> v(n);

	for (int i = 0; i < n; i++) 
	{
		cin >> v[i];
	}

	cin >> m;
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) 
	{
		int a;
		cin >> a;
		int s = upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a);
		
		printf("%d ", s);
	}

	return 0;
}