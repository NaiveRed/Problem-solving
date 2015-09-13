#include<cstdio>
#include<cstring>

int seq[5000];
char num[5000][100000];

int getSequence();
void getNum();
int main()
{
	int Case;
	scanf("%d", &Case);
	getchar();
	
	bool first(true);

	while (Case--)
	{
		
		getchar();
		int max = getSequence();
		getNum();
	
		if (first)
			first = false;
		else putchar('\n');

		for (int i = 0; i < max; i++)
		{
			for (int j = 0;num[i][j];j++)
				putchar(num[i][j]);
			
			putchar('\n');
		}

		
	}
	return 0;
}
int getSequence()
{
	int index(0);
	char str[5000];
	gets(str);

	for (int i = 0; i < strlen(str); i++)
	{
		int temp(0);
		while (str[i] != ' '&&str[i])
			temp = temp * 10 + str[i++] - '0';

		seq[index++] = temp;
	}
	return index;
}
void getNum()
{
	int i(0);
	int index(seq[i]-1);
	int flag(0);
	char c;
	
	while ((c = getchar()) != '\n'&&c!=EOF)
	{
		
		if (c == ' ')
		{
			num[index][flag] = '\0';
			index=seq[++i]-1;
			flag = 0;
			continue;
		}

		num[index][flag++] = c;
		
	}

	num[index][flag] = '\0';
}