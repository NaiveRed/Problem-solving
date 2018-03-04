/*
ref: http://programming-study-notes.blogspot.tw/2014/01/uva-10334-ray-through-glasses.html
只要最後的反射點在上下兩條線，就可以在下次反射時有兩種方法。在(最下、中間)或是(最上、中間)時反射。
其餘的光線就只有一種方法。
而光線最後都會通過最上面或下面，所以 a_n 反射點的數量就是 a_{n-1}。
a_n = a_{n-1} + a_{n-1}的反射點數 = a_{n-1} + a_{n-2}
*/
#include <cstdio>
#define N 1001
int main()
{
    static int fib[N][215] = {{1}, {2}};
    int len = 1, n; //len = 210
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < len; j++)
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j];

        for (int j = 0; j < len; j++)
            if (fib[i][j] >= 10)
            {
                fib[i][j] %= 10;
                fib[i][j + 1]++;
                if (j + 1 == len)
                    len++;
            }
    }

    while (scanf("%d", &n) != EOF)
    {
        int i = len - 1;
        while (!fib[n][i])
            i--;
        while (i >= 0)
            putchar(fib[n][i--] + '0');
        putchar('\n');
    }

    return 0;
}