#include <cstdio>
#include <cmath>
#define N 65001
typedef unsigned int UI; //case: 62745 is a Carmichael number
bool not_prime[N];
void eratosthenes()
{
    int _sqrt = sqrt(N - 1);

    for (int i = 2; i <= _sqrt; i++)
    {
        if (!not_prime[i])
        {
            for (int k = (N - 1) / i; k >= i; k--)
                if (!not_prime[k])
                    not_prime[k * i] = true;
        }
    }
}
/*LL mod_n(int a, int e, int n)
{
	if (!e)
		return 1;
	if (e == 1)
		return a % n;

	LL res = mod_n(a, e / 2, n);
	if (e & 1)
		return (((res * res) % n) * a) % n;

	return (res * res) % n;
}*/
UI mod_n(int a, int e, int n)
{
    UI res = 1, now = a;
    while (e)
    {
        if (e & 1)
            res = (res * now) % n;

        now = (now * now) % n;
        e >>= 1;
    }
    return res;
}
int main()
{
    eratosthenes();
    int n;
    while (scanf("%d", &n) && n)
    {
        if (!not_prime[n])
        {
            printf("%d is normal.\n", n);
            continue;
        }

        int a;
        for (a = 2; a < n; a++)
        {
            if (mod_n(a, n, n) != (UI)a)
                break;
        }
        if (a == n)
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }

    return 0;
}