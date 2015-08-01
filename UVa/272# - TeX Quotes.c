#include<stdio.h>

int main(){

	char c;
	int i = 0, count = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '"'&&count == 0)
		{
			printf("%c%c", '`', '`');
			count = 1;
		}
		else if (c == '"'&&count == 1)
		{
			printf("%c%c", '\'', '\'');
			count = 0;
		}
		else printf("%c", c);
	}

	return 0;
}