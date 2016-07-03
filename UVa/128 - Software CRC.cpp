#include<cstdio>
#define G 34943

int main()
{
    char num[1025];

    while (gets(num) && num[0] != '#')
    {
        if (!num[0])
            puts("00 00");
        else
        {
            int now = 0;
            for (int i = 0; num[i]; i++)
                now = ((now << 8) + num[i]) % G;
            now = G - (((now << 8) % G) << 8) % G;
            printf("%02X %02X\n", now >> 8, now & 255);//now & 255 = now & ((1<<8)-1) = now % 256
        }
    }

    return 0;
}