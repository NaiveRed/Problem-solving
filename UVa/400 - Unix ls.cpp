/*
注意字串的順序輸出時是由上到下:
1 4
2 5
3 6
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define L 60
using namespace std;

int main()
{
    int n;
    vector<string> file;
    string str;
    while (scanf("%d", &n) != EOF)
    {
        int max_len = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            file.push_back(str);
            int len = str.length();
            if (len > max_len)
                max_len = len;
        }

        sort(file.begin(), file.end());
        int x = 1 + (L - max_len) / (max_len + 2);//一列最多可容納幾個
        int r = (int)n / x + (n%x ? 1 : 0);//有幾列

        puts("------------------------------------------------------------");

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (i + r*j >= n)
                    break;

                if (j)
                    putchar(' '), putchar(' ');

                printf("%-*s", max_len, file[i + r*j].c_str());
            }
            putchar('\n');
        }

        file.clear();
    }

    return 0;
}