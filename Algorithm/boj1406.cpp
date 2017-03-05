#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<char> list;
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); ++i)
	{
		auto iter = list.end();
		list.insert(iter,s[i]);
	}

	int c;
	cin >> c;
	auto iter = list.end();
	for (int i = 0; i < c; ++i)
	{
		char t;
		char s;
		cin >> t;
		
		switch(t)
		{
		case 'L':
			if (iter != list.begin())
			{
				iter--;
			}
			break;
		case 'D':
			if (iter != list.end())
			{
				iter++;
			}
			break;
		case 'B':
			if (iter != list.begin())
			{
				iter = list.erase(--iter);
			}
			break;
		case 'P':
			cin >> s;
			iter = list.insert(iter, s);
			iter++;
			break;
		default:
			break;
		}
	}


	auto iter_2 = list.begin();
	for (; iter_2 != list.end(); ++iter_2)
	{
		cout << *iter_2;
	}
	return 0;
}