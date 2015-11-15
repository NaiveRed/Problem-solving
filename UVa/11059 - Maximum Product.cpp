#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

//Maximum Product Subarray
//注意overflow 和 set 只出現0的狀況(ex: 2 0 0)
int main()
{
	int set, Case(0);

	while (scanf("%d", &set) != EOF)
	{
		int num[20]{};

		for (int i = 0; i < set; i++)
			scanf("%d", &num[i]);

		//include empty set is zero
		//max_sub,min_sub 為某局部連續的總和(1方便乘法)，max_total為其中連續最大的總和
		long long max_sub(1), min_sub(1), max_total(0);

		if (set != 1)
			for (int n : num)
			{
			//n為0時，subarray都重新開始
			if (!n)
			{
				min_sub = max_sub = 1;
				continue;
			}

			long long temp = max_sub;

			//看"max乘上n後"和"n"(將從n開始的subarray)哪個大，再去處理如果n為負，乘上min_sub可能為更大
			max_sub = MAX(MAX(max_sub*n, n), min_sub*n);

			//一樣看"乘上n後"和"n"(將從n開始的subarray)哪個小，再去處理如果n為負，乘上原max_sub可能為更小
			min_sub = MIN(MIN(min_sub*n, n), temp*n);

			max_total = MAX(max_sub, max_total);
			}
		else
			max_total = num[0] < 0 ? 0 : num[0];

		printf("Case #%d: The maximum product is %lld.\n\n", ++Case, max_total);
	}

	return 0;
}