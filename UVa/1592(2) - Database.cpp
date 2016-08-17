#include<cstdio>
#include<unordered_map>
#include<string>
#include<map>
#include<utility>
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

                if (!str_map.count(s))
                    str_map[s] = count++;

                data[i][j] = str_map[s];
                s.clear();
            }

        map<pair<int, int>, int> col_data;
        bool flag = true;
        for (int c1 = 0; c1 < m&&flag; c1++)
            for (int c2 = c1 + 1; c2 < m&&flag; c2++)
            {
                for (int r = 0; r < n; r++)
                {
                    int s1 = data[r][c1], s2 = data[r][c2];
                    pair<int, int> d(s1, s2);

                    if (!col_data.count(d))
                        col_data[d] = r;
                    else
                    {
                        puts("NO");
                        printf("%d %d\n%d %d\n", col_data[d] + 1, r + 1, c1 + 1, c2 + 1);
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