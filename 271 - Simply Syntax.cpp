#include<cstdio>
#include<cstring>
#define N 999

int main()
{
	char str[N];

	while (scanf("%s",str)!=EOF)
	{
		int s_num(0);
		bool isSentence(true);
		for (int i = strlen(str) - 1; i >= 0; i--)
		{
			if (str[i] == 'N')
			{
				if (!s_num)
				{
					isSentence = false;
					break;
				}
			}
			else if ( str[i] == 'C' || str[i] == 'D' || str[i] == 'E' || str[i] == 'I')
			{
				if (s_num > 1)
					s_num--;
				else
				{
					isSentence = false;
					break;
				}
			}
			else if (str[i] >= 'p'&&str[i] <= 'z')
				s_num++;
			else 
			{
				isSentence = false;
				break;
			}
		}

		puts(isSentence&&s_num == 1 ? "YES" : "NO");
		
	}

	return 0;
}
