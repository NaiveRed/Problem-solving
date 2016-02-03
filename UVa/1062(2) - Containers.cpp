//LIS O(NlogL)
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

int main()
{
    char str[1000];
    int length[1000], i, Case = 1;

    while (gets(str) && str[0] != 'e')
    {
        int len = strlen(str);
        std::fill(length, length + len, 1);

        std::vector<int> v = { str[0] };//C++11
        for (i = 1; i < len; i++)
            if (str[i]>v.back())
                v.push_back(str[i]);
            else
                *std::lower_bound(v.begin(), v.end(), str[i]) = str[i];

        printf("Case %d: %d\n", Case++, v.size());
    }

    return 0;
}
