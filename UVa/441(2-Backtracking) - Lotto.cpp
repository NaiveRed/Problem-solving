#include<cstdio>

int num[15], ans[7];

void back(int len, int pos, int& total);//Backtracking
int main()
{
	int n;
	bool first(true);

	while (scanf("%d", &n) && n)
	{

		if (!first)
			putchar('\n');
		else
			first = false;

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);

		back(0, 0, n);

	}


	return 0;
}
void back(int len, int pos, int& total)
{
	if (len == 6)//���׺�6�Y�i��X
	{
		//ans�q1�}�l
		for (int i = 1; i < 6; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[6]);
	}
	else
	{
		len++;
		for (int i = pos; i < total; i++)//ans[len]�����ר̧Ǳqnum[]������D
		{
			ans[len] = num[i];//�N�Ʀr���J����
			back(len, i + 1, total);//���ת��U�@��q�U�Ӧ�m�}�l��
		}
	}
}