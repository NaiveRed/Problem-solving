#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>
#define VOWEL(c) ((c)=='a'||(c)=='e'||(c)=='i'||(c)=='o'||(c)=='u')

int main()
{
	std::string str;

	while (getline(std::cin,str))
	{

		int now(0), i;
		for (i = 0; i < str.length(); i++)
			if (isalpha(str[i]))
			{
			now = i;
			break;
			}

		if (i == str.length())
		{
			puts(str.c_str() );
			continue;
		}
		
		bool flag(true);
		for (i = now; i < str.length(); i++)
		{

			if (!isalpha(str[i]) && flag)
			{
				flag = false;
				if (VOWEL(tolower(str[now])))
					str.insert(i, "ay");
				else
				{
					char temp[4]{str[now], 'a', 'y', '\0'};

					str.insert(i, temp);

					str.erase( now,1);
				}
				i += 2;
			}
			else  if (isalpha(str[i]) && !flag)
			{
				flag = true;
				now = i;
			}

		}

		if (flag)
		{
			if (VOWEL(tolower(str[now])))
				str.insert(i, "ay");
			else
			{
				char temp[4]{str[now], 'a', 'y', '\0'};

				str.insert(i, temp);
				str.erase(now,1);
			}
		}


		puts(str.c_str());

	}


	return 0;
}