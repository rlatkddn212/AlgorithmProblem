#include <iostream>
using namespace std;

int main()
{
	int s1, s2;
	cin >> s1 >> s2;

	bool testcase1 = true;
	bool testcase2 = true;
	for (int i = 0; i < s1; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a != b)
		{
			testcase1 = false;
		}
	}
	
	for (int i = 0; i < s2; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a != b)
		{
			testcase2 = false;
		}
	}

	if (testcase1 && testcase2)
	{
		cout << "Accepted";
	}else if (!testcase1)
	{
		cout << "Wrong Answer";
	}
	else
	{
		cout << "Why Wrong!!!";
	}
	return 0;
}