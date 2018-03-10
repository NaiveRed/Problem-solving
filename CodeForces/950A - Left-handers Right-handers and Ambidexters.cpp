#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a);
    while (a && (l != r || a >= 2))
    {
        if (l > r)
        {
            ++r;
            --a;
        }
        else if (r > l)
        {
            ++l;
            --a;
        }
        else
        {
            a -= 2;
            ++l;
            ++r;
        }
    }

    printf("%d\n", min(l, r) << 1);

    return 0;
}