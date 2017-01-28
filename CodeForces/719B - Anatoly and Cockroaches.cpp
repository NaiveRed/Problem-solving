#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
    int n;
    char str[100002];
    scanf("%d", &n);
    getchar();
    fgets(str, 100002, stdin);
    int r = 0, b = 0, needr, needb, i;

    //first r
    for (i = 0; i < n; i += 2)
        if (str[i] != 'r')
            r++;
    for (i = 1; i < n; i += 2)
        if (str[i] != 'b')
            b++;
    needr = MIN(r, b) + MAX(r, b) - MIN(r, b);

    //first b
    r = b = 0;
    for (i = 0; i < n; i += 2)
        if (str[i] != 'b')
            b++;
    for (i = 1; i < n; i += 2)
        if (str[i] != 'r')
            r++;
    needb = MIN(r, b) + MAX(r, b) - MIN(r, b);

    printf("%d\n", MIN(needr, needb));

    return 0;
}