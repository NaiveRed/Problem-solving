#include<cstdio>

char str1[6], str2[6];
inline void clockwise()//順時針旋轉
{
    int temp = str2[4];
    str2[4] = str2[2];
    str2[2] = str2[1];
    str2[1] = str2[3];
    str2[3] = temp;
}
inline void forward()//向前滾
{
    int temp = str2[5];
    str2[5] = str2[4];
    str2[4] = str2[0];
    str2[0] = str2[1];
    str2[1] = temp;
}
inline void turnRight()//向右翻
{
    int temp = str2[3];
    str2[3] = str2[0];
    str2[0] = str2[2];
    str2[2] = str2[5];
    str2[5] = temp;
}
inline bool cmp()
{
    for (int i = 0; i < 6; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}
int main()
{
    while ((str1[0] = getchar()) != EOF)
    {
        int i;
        for (i = 1; i < 6; i++)
            str1[i] = getchar();
        for (i = 0; i < 6; i++)
            str2[i] = getchar();
        getchar();

        bool ok = false;

		//以不同的 6 個面當最上面，去做4次旋轉
        for (int i = 0; i < 4 && !ok; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (cmp())
                {
                    ok = true;
                    break;
                }
                clockwise();
            }
            forward();
        }

        for (int i = 0; i < 4 && !ok; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (cmp())
                {
                    ok = true;
                    break;
                }
                clockwise();
            }

            turnRight();
        }

        puts(ok ? "TRUE" : "FALSE");
    }

    return 0;
}