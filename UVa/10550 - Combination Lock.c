/*
�`�N������:
���ɰw�A�b�Y���V���Ǭ� 39 38 37 .... 0
�f�ɰw�A�b�Y���V���Ǭ� 0 1 2 3 ... 39
*/
#include<stdio.h>

int main()
{
    int st, a, b, c;
    while (scanf("%d%d%d%d", &st, &a, &b, &c) && (st || b || a || c))
    {
        int count = 1080;
        //�C�ӳ������O�_�p��{�b����m�h���B�z
        count += ((st >= a) ? (st - a) : (st + 40 - a)) * 9;
        count += ((a > b) ? (40 - a + b) : (b - a)) * 9;
        count += ((b >= c) ? (b - c) : (b + 40 - c)) * 9;
        printf("%d\n", count);
    }

    return 0;
}