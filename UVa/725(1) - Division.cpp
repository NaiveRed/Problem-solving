/*
time: 0.275ms
*/
#include<cstdio>
#include<string>

int main()
{

	int num;
	bool first(true);

	while (scanf("%d", &num) && num)
	{
		if (first)
			first = false;
		else puts("");

		int limit(98765 / num);
		bool noSolution(true);

		for (int i = 1234; i <= limit; i++)
		{
			bool digit[10]{0};
			std::string str1(std::to_string(i*num)), str2(std::to_string(i));

			if (str1.length() < 5)
				continue;

			bool isOk(true);
			
			if (str2.length() == 4)
				digit[0] = true;
			
			for (char c : str1)
			{
				if (digit[c - '0'])
				{
					isOk = false;
					break;
				}
				else digit[c - '0'] = true;
			}
			for (char c : str2)
			{
				if (digit[c - '0'])
				{
					isOk = false;
					break;
				}
				else digit[c - '0'] = true;
			}

			if (isOk)
			{
				if (noSolution)noSolution = false;

				printf("%s /%s%s = %d\n", str1.c_str(), str2.length() == 4 ? " 0" : " ", str2.c_str(), num);
			}

		}
		if (noSolution)
			printf("There are no solutions for %d.\n", num);
	

	}

	return 0;
}