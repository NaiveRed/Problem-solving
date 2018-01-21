#include <cstdio>
#include <cstring>

int main()
{
	int C[27][27] = {}; // C(i,j) = C[i][j]
	for (int i = 0; i < 27; i++)
		C[i][i] = C[i][0] = 1;

	for (int i = 1; i < 27; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

	char str[7];
	while (fgets(str, 7, stdin))
	{
		int len = strlen(str) - 1, count = 0;
		str[len] = NULL;

		bool legal = true;

		for (int i = 1; i < len; i++)
			if (str[i] <= str[i - 1])
			{
				legal = false;
				break;
			}

		if (legal)
		{
			count = 1;
			for (int i = 1; i < len; i++)
				count += C[26][i];

			for (int i = 0; i < len; i++)
			{
				// str[i] can replace with x, c < x < str[i]
				// After replacing, count for combination of remain alphabets
				// 'b' ce => 'a' (_ _)
				char c = i ? str[i - 1] + 1 : 'a';

				//count for this (_ _)
				for (char use = c; use < str[i]; use++)
					count += C['z' - use][len - i - 1];		
			}
		}
		
		printf("%d\n", count);
	}

	return 0;
}