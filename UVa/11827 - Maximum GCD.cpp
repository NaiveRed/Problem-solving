#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

inline int gcd(int a, int b)
{
    while (b)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }

    return a;
}
int main()
{
    int n, num[100];
    string str;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        int max = 0, i = 0, temp;

        getline(cin, str);
        stringstream ss(str);
        while (ss >> temp)
            num[i++] = temp;

        for (int j = 0; j < i; j++)
            for (int k = j + 1; k < i; k++)
            {
                int g = gcd(num[j], num[k]);
                max = max < g ? g : max;
            }

        printf("%d\n", max);
    }

    return 0;
}