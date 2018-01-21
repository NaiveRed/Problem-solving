//分母有理化
//(S + 1)^2 - 1 = n
#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long s;
		scanf("%lld", &s);
		printf("%lld\n", (s + 1) * (s + 1) - 1);
	}

	return 0;
}