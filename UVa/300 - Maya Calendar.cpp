//注意日、月、年從 0 開始的部分
#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string haab_str[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
                           "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

    unordered_map<string, int> haab;
    for (int i = 0; i < 19; ++i)
        haab[haab_str[i]] = i;

    char tzo_str[][10] = {"ahau", "imix", "ik", "akbal", "kan", "chicchan",
                          "cimi", "manik", "lamat", "muluk", "ok",
                          "chuen", "eb", "ben", "ix", "mem",
                          "cib", "caban", "eznab", "canac"}; //把第20個移到[0]

    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    while (n--)
    {
        int d, y, sum;
        char str[10];
        scanf("%d.%s%d", &d, str, &y);

        sum = (d + 1) + haab[string(str)] * 20 + y * 365;
        y = (sum - 1) / 260;
        sum = (sum - 1) % 260 + 1; //260 為該年最後一天
        int name = sum % 20, no = (sum - 1) % 13 + 1;
        printf("%d %s %d\n", no, tzo_str[name], y);
    }

    return 0;
}