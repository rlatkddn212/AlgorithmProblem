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
#include <map>

using namespace std;

void UpdateStack(stack<int>& st)
{
	if (st.empty()) 
		return;

	if (st.top() == -2 || st.top() == -3)
	{
		return;
	}
	else
	{
		int sum = 0;
		while (!st.empty() && st.top() != -2 && st.top() != -3)
		{
			sum += st.top();
			st.pop();
		}

		st.push(sum);
	}
}

int main()
{
	string s;
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			st.push(-2);
		}
		else if (s[i] == '[')
		{
			st.push(-3);
		}
		else if (s[i] == ')')
		{
			if (st.empty())
			{
				cout << 0;
				return 0;
			}
			if (st.top() == -2)
			{
				st.pop();
				st.push(2);
				UpdateStack(st);
			}
			else if (st.top() == -3)
			{
				cout << 0;
				return 0;
			}
			else
			{
				int sum = st.top();
				st.pop();

				if (!st.empty() && st.top() == -2)
				{
					st.pop();
					st.push(2 * sum);
				}
				else
				{
					cout << 0;
					return 0;
				}

				UpdateStack(st);
			}
		}
		else
		{
			if (st.empty())
			{
				cout << 0;
				return 0;
			}
			if (st.top() == -3)
			{
				st.pop();
				st.push(3);
				UpdateStack(st);
			}
			else if (st.top() == -2)
			{
				cout << 0;
				return 0;
			}
			else
			{
				int sum = st.top();
				st.pop();

				if (!st.empty() && st.top() == -3)
				{
					st.pop();
					st.push(3 * sum);
				}
				else
				{
					cout << 0;
					return 0;
				}

				UpdateStack(st);
			}
		}
	}

	if (st.top() == -2 || st.top() == -3)
	{
		cout << 0;
	}
	else if (st.size() > 1)
	{
		cout << 0;
	}
	else
	{
		cout << st.top();
	}

	return 0;
}