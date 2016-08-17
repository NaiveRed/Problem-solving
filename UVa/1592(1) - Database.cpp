//pairing function: http://mathworld.wolfram.com/PairingFunction.html
#include<cstdio>
#include<unordered_map>
#include<string>
typedef long long LL;
using namespace std;

int main()
{
    int n, m;
    unordered_map<string, int> str_map;
    int data[10001][11];
    while (scanf("%d%d", &n, &m) != EOF)
    {
        getchar();
        str_map.clear();
        int count = 1;
        string s;
        char c;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                data[i][j] = 0;//init

                while ((c = getchar()) != ',' && c != '\n')
                    s += c;

                //替字串建 map
                if (!str_map.count(s))
                    str_map[s] = count++;

                data[i][j] = str_map[s];
                s.clear();
            }

        unordered_map<LL, int> col_data;//某列任意兩行的資料
        bool flag = true;

        //窮舉任兩行
        for (int c1 = 0; c1 < m&&flag; c1++)
            for (int c2 = c1 + 1; c2 < m&&flag; c2++)
            {
                for (int r = 0; r < n; r++)
                {
                    LL s1 = data[r][c1], s2 = data[r][c2];//取出在 r 列的兩行字串
                    LL temp = (s1 + s2 - 2)*(s1 + s2 - 1) / 2 + s2;//hash: pairing function

                    if (!col_data.count(temp))
                        col_data[temp] = r;//存進這對字串在哪列
                    else
                    {
                        puts("NO");
                        printf("%d %d\n%d %d\n", col_data[temp] + 1, r + 1, c1 + 1, c2 + 1);
                        flag = false;
                        break;
                    }
                }

                col_data.clear();
            }

        if (flag)
            puts("YES");
    }

    return 0;
}