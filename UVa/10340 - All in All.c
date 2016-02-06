#include<stdio.h>
#define N 100000

char s[N], t[N];
int main(){

	while (scanf("%s %s", s, t) != EOF)
	{
		int check = 1;
		int i, j = 0;
		for (i = 0; s[i]; i++)
		{
			while (s[i] != t[j++])
				if (!t[j])
				{
					check = 0;
					break;
				}
			
			if (!check)
				break;
		}
		printf("%s\n",check ? "Yes" : "No");
	}
	return 0;
}