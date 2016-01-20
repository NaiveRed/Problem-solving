#include<cstdio>

int main()
{
	int a, r;
	int seq[1000] = {};

	while (scanf("%d%d", &a, &r) != EOF)
	{
		bool notSeq = false;
		int i, k;

		//»Ý»¼´î
		if (r > 1 && a > 1)
		{
			for (i = 0; a > 1; i++)
			{
				seq[i] = a;
				if (a%r)
				{
					notSeq = true;
					break;
				}

				a /= r;
			}
		}
		else
			notSeq = true;

		if (!notSeq)
		{
			for (k = 0; k < i; k++)
				printf("%d ", seq[k]);
			puts("1");
		}
		else
			puts("Boring!");

	}

	return 0;
}