#include<cstdio>
#include<cctype>
#define VOWEL(c) ((c)=='a'||(c)=='e'||(c)=='i'||(c)=='o'||(c)=='u'||(c)=='A'||(c)=='E'||(c)=='I'||(c)=='O'||(c)=='U')

int main()
{
	bool flag(true),isVowel(false);
	char c, tar;

	while ((c = getchar())!=EOF)
	{
		
			if (!isalpha(c))
			{
				if (flag)
				{
					putchar(c);
					continue;
				}

				if (!isVowel)
					putchar(tar);

				putchar('a');
				putchar('y');
				putchar(c);
				flag = true;
				continue;
			}


			if (flag)
			{
				tar = c;
				flag = false;

				if (VOWEL(tar))
				{
					putchar(tar);
					isVowel = true;
				}
				else isVowel = false;
			}
			else putchar(c);
		
	}


	return 0;
}