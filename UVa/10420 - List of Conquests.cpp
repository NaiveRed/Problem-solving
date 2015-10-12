#include<cstdio>
#include<string>
#include<map>
#include<cctype>

using std::string;
int main()
{
	int Case;

	scanf("%d", &Case);
	getchar();
	char cStr[80];
	
	std::map<string,int>country;

	while (Case--)
	{
		gets(cStr);

		int temp(0);
		bool flag(false);

		for (char &c : cStr)
		{
			if (isalpha(c))
				flag = true;
			else if (!flag)
				temp++;
			else
			{
				c = '\0';
				break;
			}
		}

		country[string(cStr+temp)]++;
	 
	}

	for (auto it = country.begin(); it != country.end(); it++)
		printf("%s %d\n", it->first.c_str(), it->second);

	return 0;
}
