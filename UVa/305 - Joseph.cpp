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
	為了讓取mod之後的數即為編號，編號從0開始
	ex.
	0~6 m=3
	(3-1)%7=2   0 1 x 3 4 5 6
	0~5 m=7
	(7-1)%6=0   x 1 2 3 4 5
	*/

	for (m = (n / 2) ;; m++)//從壞人開始刪
	{
	
		if ((m-1)%n>=(n / 2))
		{
			int target((m-1)%n),people;
	
			for (people = n - 1;people>(n/2);people--)
			{
				target = (target + m - 1) % people;
				//每次殺掉的人的號碼，會根據當前人數作改變(ex.0 1 x 3  ->  0 1 x 2 再殺一人 0 1 x 2 -> 0 1 x x 兩次的target都是2

				if (target<(n/2))//跟原來人數比，0~(n/2)-1 是好人
					break;	
			}
				
			if (people == (n/2))//已把壞的殺完
				break;
		}

	}
	return m;
}
