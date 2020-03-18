#include <iostream>

using namespace std;

int n;
int m;
int arr[100001];

bool canLesson(int num)
{
	int c = m;
	int sum = 0;
	for (int i = 0; i < n; i++) 
	{
		sum += arr[i];
		if (sum > num) 
		{
			c--;
			sum = arr[i];
			if (sum > num)
			{
				return false;
			}
		}
	}
	if (c <= 0) 
	{
		return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	int low = 0;
	int high = sum;
	while (low + 1 < high)
	{
		int mid = (low + high) / 2;

		if (canLesson(mid))
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}

	cout << high;

	return 0;
}