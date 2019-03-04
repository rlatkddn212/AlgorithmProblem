#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int,int> > arr(n);
	
	for(int i = 0 ; i < n ; ++i)
	{
		int a;
		cin >> a;
		arr[i] = make_pair(a, i);
	}

	sort(arr.begin(), arr.end());
	int counter = 0;
	for(int i = 0 ; i < arr.size() ; ++i)
	{
		counter = max(arr[i].second - i, counter);
	}
	cout << counter+1;
	return 0;
}