#include<cstdio>
#include<cstring>
#define OK(a,b) (((a)-'0'+(b)-'0')<=3)

int main()
{
	char str1[102], str2[102];
	while (fgets(str1, 102, stdin))
	{
		fgets(str2, 102, stdin);
		int len1 = strlen(str1) - 1, len2 = strlen(str2) - 1;
		int i, j, ans = 201;

		//�H str1 ���� �A���� str2 
		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len2&&i + j < len1; j++)
				if (!OK(str1[i + j], str2[j]))
					break;
			if (j == len2 || i + j == len1)
				break;
		}

		ans = len1 + len2 - j;

		//�H str2 ���� �A���� str1 
		for (i = 1; i < len2; i++)
		{
			for (j = 0; j < len1&&i + j < len2; j++)
				if (!OK(str2[i + j], str1[j]))
					break;
			if (j == len1 || i + j == len2)
				break;

		}

		//���p��
		if (ans > len2 + len1 - j)
			ans = len2 + len1 - j;

		printf("%d\n", ans);
	}

	return 0;
}