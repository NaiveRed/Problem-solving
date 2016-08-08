#include<cstdio>
#include<cmath>
#define EPS 1e-6

int main()
{
	int H, W;
	while (scanf("%d%d", &H, &W) && H)
	{
		int N = 0, k;
		double logH = log((double)H), logW = log((double)W);
		if (H == 1)
		{
			puts("0 1");
			continue;
		}

		//log(W)*log(N+1) == log(H)*log(N)
		while (true)
		{
			N++;
			if (H % (N + 1))
				continue;

			double logn1 = log((double)N + 1);
			if (std::abs(logH*log((double)N) - logn1*logW) < EPS)
			{
				k = round(logH / logn1);
				break;
			}
		}

		double dN = N;
		int tot;
		if (N == 1)
			tot = k + 1;
		else
			tot = (1 - pow(dN, k + 1)) / (1 - dN);//1+N+N^2+N^3+...+N^k

		//H+H(N/(N+1))+H(N/(N+1))^2+...+H(N/(N+1))^k
		int tot_height = (int)round(H*(1 - pow(dN / (dN + 1), k + 1)) / (1 - (dN / (dN + 1))));
		printf("%d %d\n", tot - W, tot_height);
	}

	return 0;
}