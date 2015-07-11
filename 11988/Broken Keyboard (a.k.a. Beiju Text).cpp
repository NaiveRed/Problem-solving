#include<list>
#include<string>
#include<iostream>

int main()
{
	std::list<char>ls;
	std::string str;

	while (getline(std::cin, str))
	{
		int len(str.length());
		auto it(ls.begin());//std::list<char>::iterator it

		for (int i = 0; i < len; i++)
		{
			if (str[i] == '[')
				it = ls.begin();
			else if (str[i] == ']')
				it = ls.end();
			else
				ls.insert(it, str[i]);
		}

		for (char &it : ls)
			std::cout << it;
		
		std::cout << '\n';
		ls.clear();
	}

	return 0;
}