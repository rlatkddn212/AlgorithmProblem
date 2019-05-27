#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string s;
		cin >> s;

		if (s.size() % 2 == 0)
		{
			for (int i = 0; i < s.size(); i += 2)
			{
				cout << s[i];
			}
			cout << "\n";
			for (int i = 1; i < s.size(); i += 2)
			{
				cout << s[i];
			}
			cout << "\n";
		}
		else
		{
			for (int i = 0; i < s.size(); ++i)
			{
				cout << s[(2 * i) % s.size()];
			}
			cout << "\n";
			for (int i = 0; i < s.size(); ++i)
			{
				cout << s[(2 * i + 1) % s.size()];
			}
			cout << "\n";
		}
	}
}