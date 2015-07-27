#include<stdio.h>
#include<string.h>

#define N 200
int main(){

	char s[N], stack[N];
	int set;
	while (scanf("%d", &set) != EOF)
	{
		getchar();
		while (set--)
		{
			memset(stack, 0, sizeof(stack));

			gets(s);

			int i, now = 0;

			for (i = 0; s[i]; i++)
			{
				if (s[i] == '(' || s[i] == '[')
				{
					stack[now++] = s[i];
					continue;
				}

				if (s[i] == ')')
				{
					if (stack[now - 1] == '(')
						stack[--now] = '\0';
					else stack[now++] = s[i];
					continue;
				}

				if (s[i] == ']')
				{
					if (stack[now - 1] == '[')
						stack[--now] = '\0';
					else stack[now++] = s[i];
				}
			}

			printf("%s\n", stack[0] ? "No" : "Yes");
		}

	}


	return 0;
}