/*

(0,0) -> (0,1) step = 1
(0,1) -> (1,0) -> (0,2) step = 2
(0,2) -> (1,1) -> (2,0) -> (0,3) step = 3
(0,3) -> (1,2) -> (2,1) -> (3,0) -> (0,4) step = 4
(0,4) -> (1,3) -> (2,2) -> (3,1) -> (4,0) -> (0,5) step = 5

(x,y)

可知 (1+(x+y))*(x+y)/2  ((首項+末項)*項數)/2
再加上 那一層再繼續移 x

ex. (3,1)

3 + 1 = 4 (需要先移到step = 4那層(上圖))
(3+1+1)*(3+1)/2 = 10

再移 x = 3

ans = 10 + 3 = 13

*/
#include<stdio.h>

typedef long long LL;
int main()
{
	int Case;
	scanf("%d", &Case);

	int i, x1, y1, x2, y2;
	for (i = 1; i <= Case; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		LL step1 = (LL)x1 + (LL)((x1 + y1)*(1 + x1 + y1) / 2);
		LL step2 = (LL)x2 + (LL)((x2 + y2)*(1 + x2 + y2) / 2);

		if (step1 > step2)
			printf("Case %d: %lld\n", i, step1 - step2);
		else
			printf("Case %d: %lld\n", i, step2 - step1);
	}

	return 0;
}