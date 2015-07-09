#include<cstdio>
#include<cmath>
#include<cstring>

int main()
{
	int test;
	char str[10000];

	while (scanf("%d", &test) != EOF)
	{

		getchar();
		while (test--)
		{
			gets(str);
			int len = strlen(str);

			
				double dSqrt = sqrt((double)len);
				int iSqrt = (int)dSqrt;
				if (iSqrt == dSqrt)
				{
					for (int i = 0; i < iSqrt; i++)
						for (int offset = 0; offset < len; offset += iSqrt)
							printf("%c", str[i + offset]);
					puts("");
				}
				else puts("INVALID");
		
		}

	}

	return 0;
}
