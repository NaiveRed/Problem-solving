#include<stdio.h>
#include<ctype.h>


int main(){


	char c[1000];

	while (gets(c))
	{

		int i = 0;
		int num_word = 0;


		while (c[i])
		{
			if (isalpha(c[i]) && !isalpha(c[i + 1]))
			{
				num_word++;
			}
			i++;

		}
		printf("%d\n", num_word);
	}


	return 0;
}