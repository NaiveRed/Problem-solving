#include <cstdio>
typedef unsigned int UI;

UI mod(int a, int e, int n)
{
    UI res = 1, now = a;
    while (e)
    {
        if (e & 1)
            res = (res * now) % n;

        now = ((now % n) * (now % n)) % n;
        e >>= 1;
    }
    return res;
}
int main()
{
    UI B, P, M;
    while (scanf("%u%u%u", &B, &P, &M) != EOF)
    {
        printf("%u\n", mod(B, P, M));
    }

    return 0;
}