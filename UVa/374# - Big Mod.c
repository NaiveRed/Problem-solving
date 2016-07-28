#include<stdio.h>

long long bigmod(long long B, long long P, long long M);
int main(){

	long long B, P, M;
	
	while (scanf("%lld%lld%lld", &B, &P, &M) != EOF)
		printf("%lld\n", bigmod(B, P, M));
	
	return 0;
}
long long bigmod(long long B, long long P, long long M)
{

	if (!P)
		return 1;
	else
	{
		long long temp = bigmod(B, P / 2, M);
		if (P & 1)
			return (temp*temp*B) % M;
		else return (temp*temp) % M;

	}

}