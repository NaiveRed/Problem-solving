#include<cstdio>

int main()
{
	int num[101] = { 0 };
	bool sum[20001] = { false };//bi�̤j��10000�A�ۥ[��20000

	int Case = 0, n, i;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf("%d", &num[i]);

		bool isB2 = num[1] >= 1 ? true : false;

		for (i = 1; i < n&&isB2; i++)
			if (num[i] >= num[i + 1])
			{
			isB2 = false;
			break;
			}

		//�C�@�إi�઺�M����@��
		for (i = 1; i <= n&&isB2; i++)
			for (int j = i; j <= n; j++)
			{
			if (sum[num[i] + num[j]])
			{
				isB2 = false;
				break;
			}
			else
				sum[num[i] + num[j]] = true;
			}

		printf("Case #%d: It is%sa B2-Sequence.\n\n", ++Case, isB2 ? " " : " not ");

		//init
		for (i = 0; i <= 20000; i++)
			sum[i] = false;
	}

	return 0;
}