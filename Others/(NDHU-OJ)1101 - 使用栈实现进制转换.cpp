#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
#define isOdd(c) ((c)=='1'||(c)=='3'||(c)=='5'||(c)=='7'||(c)=='9')

void divByTwo(std::string&  bigNum);
int main()
{
	std::stack<char> binary;

	std::string bigNum, zero("");

	while (std::cin >> bigNum)
	{

		while (bigNum != zero)
		{
			if (isOdd(bigNum[bigNum.length ()- 1]))
				binary.push('1');
			else
				binary.push('0');

			divByTwo(bigNum);
		}

		while (!binary.empty())
		{
			putchar(binary.top());
			binary.pop();
		}
		
		putchar('\n');
	}

	return 0;
}
void divByTwo(std::string& bigNum)
{
	int nextAdd(0), len = bigNum.length();

	for (int i = 0; i<len; i++)
	{
		char temp = bigNum[i];

		bigNum[i] = (temp - '0') / 2 + nextAdd + '0';
		nextAdd = isOdd(temp) ? 5 : 0;
	}

	for (int i = 0; i < len; i++)
	{
		if (bigNum[i] == '0')
		{
			bigNum.erase(0, 1);
			i--;
			len--;
		}
		else break;
	}
}