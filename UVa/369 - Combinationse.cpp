#include<cstdio>

//You may assume that the final value of C will fit in a 32 - bit Pascal LongInt or a C long. (C 是指答案)
int main()
{

	long long int pascal[101][101] = { { 1 }, { 1, 1 } };

	//建巴斯卡三角形
	for (int i = 2; i <= 100; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;

		for (int j = 1; j < i; j++) 
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];//組合公式:C(n,m) = C(n-1,m) + C(n-1,m-1)

	}
	int n, m;

	while (scanf("%d%d", &n, &m) && n && m)
		printf("%d things taken %d at a time is %lld exactly.\n", n, m, pascal[n][m]);

	return 0;

}
