#include <cstdio>
#include <algorithm>
#define ORD(c) ((c) - 'A')

int order[20];
struct DNA
{
    char str[52];
    int len, count;

    void calc()
    {
        int alp[4] = {};
        count = 0;
        for (int i = 0; i < len; ++i)
        {
            int idx = order[ORD(str[i])];
            /*
            直接利用記錄下來的字母數，往前計算 [0~i-1] 有哪些比自己(i)大
            k = 自己的順位 + 1
            */
            for (int k = idx + 1; k < 4; ++k)
                count += alp[k];
            ++alp[idx]; //更新 [0~i] 的各字母數
        }

        str[len] = '\0';
    }

    /* slow version
    void calc()
    {
        count = 0;
        for (int i = 0; i < len - 1; i++)
            for (int j = i + 1; j < len; j++)
                if (str[j] < str[i])
                    count++;
    }*/
};
int main()
{
    //順位轉換
    order[0] = 0;  //'A'-'A'
    order[2] = 1;  //'C'-'A'
    order[6] = 2;  //'G'-'A'
    order[19] = 3; //'T'-'A'

    int Case;
    DNA dna[100];
    scanf("%d ", &Case);

    while (Case--)
    {
        int n, m;
        scanf("%d%d ", &n, &m);

        for (int i = 0; i < m; ++i)
        {
            fgets(dna[i].str, 52, stdin);
            dna[i].len = n;
            dna[i].calc();
            //dna[i].id = i;
        }

        std::stable_sort(dna, dna + m, [](const DNA &a, const DNA &b) -> bool {
            return a.count < b.count;
        });

        /*std::sort(dna, dna + m, [](const DNA &a, const DNA &b) -> bool {
            int ad = a.count, bd = b.count;
            if (ad != bd)
                return ad < bd;
            else
                return a.id < b.id;
        });*/

        for (int i = 0; i < m; ++i)
            puts(dna[i].str);
        if (Case)
            putchar('\n');
    }
    return 0;
}