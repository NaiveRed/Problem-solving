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

                //���r��� map
                if (!str_map.count(s))
                    str_map[s] = count++;

                data[i][j] = str_map[s];
                s.clear();
            }

        unordered_map<LL, int> col_data;//�Y�C���N��檺���
        bool flag = true;

        //�a�|�����
        for (int c1 = 0; c1 < m&&flag; c1++)
            for (int c2 = c1 + 1; c2 < m&&flag; c2++)
            {
                for (int r = 0; r < n; r++)
                {
                    LL s1 = data[r][c1], s2 = data[r][c2];//���X�b r �C�����r��
                    LL temp = (s1 + s2 - 2)*(s1 + s2 - 1) / 2 + s2;//hash: pairing function

                    if (!col_data.count(temp))
                        col_data[temp] = r;//�s�i�o��r��b���C
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