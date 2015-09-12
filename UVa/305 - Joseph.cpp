#include<cstdio>

int Joseph(int n);
int main()
{
	int ans[14]{0, 2};

	for (int i = 2; i < 14; i++)
		ans[i] = Joseph(i << 1);

	int k;
	while (scanf("%d", &k) && k)
		printf("%d\n", ans[k]);

	return 0;
}
int Joseph(int n)
{
	int m;

	/*
	���F����mod���᪺�ƧY���s���A�s���q0�}�l
	ex.
	0~6 m=3
	(3-1)%7=2   0 1 x 3 4 5 6
	0~5 m=7
	(7-1)%6=0   x 1 2 3 4 5
	*/

	for (m = (n / 2) ;; m++)//�q�a�H�}�l�R
	{
	
		if ((m-1)%n>=(n / 2))
		{
			int target((m-1)%n),people;
	
			for (people = n - 1;people>(n/2);people--)
			{
				target = (target + m - 1) % people;
				//�C���������H�����X�A�|�ھڷ�e�H�Ƨ@����(ex.0 1 x 3  ->  0 1 x 2 �A���@�H 0 1 x 2 -> 0 1 x x �⦸��target���O2

				if (target<(n/2))//���ӤH�Ƥ�A0~(n/2)-1 �O�n�H
					break;	
			}
				
			if (people == (n/2))//�w���a������
				break;
		}

	}
	return m;
}
