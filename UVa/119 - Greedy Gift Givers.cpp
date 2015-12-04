#include<iostream>
#include<unordered_map>
#include<string>
using std::cin;

int main()
{
	int people;
	std::string str[10], temp, name;
	bool flag(false);

	while (cin >> people)
	{
		if (flag)
			std::cout << '\n';
		else 
			flag = true;

		std::unordered_map<std::string, int>table;
		int cost, n;

		for (int i = 0; i < people; i++)
			cin >> str[i];

		for (int i = 0; i < people; i++)
		{

			cin >> name >> cost >> n;

			if (cost&&n)
			{
				table[name] += (cost*-1 + cost%n);
				cost /= n;
			}
			else
				table[name] += 0;

			while (n--)
			{
				cin >> temp;
				table[temp] += cost;
			}
		}

		for (int i = 0; i < people; i++)
			std::cout << str[i] << ' ' << table[str[i]] << '\n';
	}

	return 0;
}