#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		string s;
		getline(cin, s);
		if (s == ".") break;
		stack<char> st;
		bool isChecked = true;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '[' || s[i] == '(')
			{
				st.push(s[i]);
			}
			else if (s[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					isChecked = false;
					break;
				}
			}
			else if (s[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					isChecked = false;
					break;
				}
			}
		}

		if (isChecked && st.empty())
		{
			cout << "yes\n";
		}
		else 
		{
			cout << "no\n";
		}
	}

	return 0;
}