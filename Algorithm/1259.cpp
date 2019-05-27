#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true)
	{

		string s;
		cin >> s;
		if (s == "0")break;
		bool isPalindrome = true;
		for (int i = 0; i < s.size() / 2; ++i)
		{
			if (s[i] != s[s.size() - i - 1])
			{
				isPalindrome = false;
			}
		}
		cout << (isPalindrome ? "yes" : "no") << "\n";
	}
	return 0;
}