#include<cstdio>

int main()
{
	char num[1001];
	
	while (gets(num)&&(num[0]!='0'||num[1]!='\0'))
	{
		int odd(0), even(0),start,end;

		for (start = 0; num[start] > '9' || num[start] < '0'; start++);
		
		for (end =start+1; num[end] >= '0'&&num[end] <= '9'; end++);

		for (int i = 0; i < end; i += 2)
			odd += (num[i] - '0');
		
		for (int i = 1; i < end; i += 2)
			even += (num[i] - '0');
		
		num[end] = '\0';

		printf("%s is%sa multiple of 11.\n", num+start, (odd - even) % 11 ? " not " : " ");
		
	}

	return 0;
}