#include <iostream>
using namespace std;
int A[500001];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
	}
	int i, j, temp;
	int change;
	for (i = 1; i <= N; i++) {
		change = 0;
		for (j = 1; j <= N - i; j++) {
			if (A[j] > A[j + 1]) {
				change = 1;
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
		if (change == 0) {
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}