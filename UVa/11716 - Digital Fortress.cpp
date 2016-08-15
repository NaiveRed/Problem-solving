#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int test;
    string str;
    int square[10001] = {};

    for (int i = 1; i <= 100; i++)
        square[i*i] = i;

    scanf("%d", &test);
    getchar();

    while (test--)
    {
        getline(cin, str);
        int len = str.length();

        int Sqrt = square[len];
        if (Sqrt)
        {
            for (int i = 0; i < Sqrt; i++)
                for (int r = 0; r < Sqrt; r++)
                    putchar(str[i + r*Sqrt]);
            putchar('\n');
        }
        else
            puts("INVALID");
       
    }

    return 0;
}