#include<cstdio>
#include<algorithm>

int main()
{
    int t[3];
    while (scanf("%d%d%d", &t[0], &t[1], &t[2]) && t[0])
    {
        std::sort(t, t + 3);
        puts(t[0] * t[0] + t[1] * t[1] == t[2] * t[2] ? "right" : "wrong");
    }

    return 0;
}
