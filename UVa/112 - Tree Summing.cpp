#include<cstdio>

enum status{
	EMPTY = 0, YES, NO
};

status getChild(int sum, int now,char last);
int main()
{

	int sum;
	while (scanf("%d", &sum) != EOF)
		puts(getChild(sum, 0,'(') == YES ? "yes" : "no");

	return 0;
}
status getChild(int sum, int now,char last)
{

	char c;
	int num(0);
	bool neg(false), flag(false);

	while ((c = getchar()) == ' ' || c == '\n');
		
	while (true)
	{
		if (c <= '9'&&c >= '0')
		{
			num = num * 10 + c - '0';
			flag = true;
		}
		else if (c == '-')
			neg = true;
		else if ((last=='('&&c==')')||flag)
			break;

		c = getchar();
	}

	if (neg)
		num *= -1;

	if (!flag)//empty tree ()
		return EMPTY;
	else
	{
		while (c == '\n' || c == ' ')
			c = getchar();
		status left = getChild(sum, now + num,c);
		while ((c = getchar()) != '(');//find the "last" of next pair 
		status right = getChild(sum, now + num,c);
		while ((c = getchar()) != ')');//find the "last" of next pair 

		if (!left&&!right)//leaf node ()()
		{
			if (now + num == sum)
				return YES;
		}
		else if (left == YES || right == YES)
			return YES;
					
	}
	return NO;
}