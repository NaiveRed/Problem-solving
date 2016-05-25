//�d���i�}
#include<cstdio>
#include<cstring>
#define N 31
typedef long long LL;
inline int gcd(int a, int b);
int main()
{
    char str[N];
    while (gets(str) && str[0] != '#')
    {
        int i, j, k, len = strlen(str);
        int alp[26] = {};

        //�p��r����
        for (i = 0; i < len; i++)
            alp[str[i] - 'a']++;

        LL ans = 0;
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < str[i] - 'a'; j++)//�C�Ӥp�� str[i] ���r��
            {
                if (!alp[j])
                    continue;

                int back = len - i - 1;//str[i] ��誺�r���Ӽ�
                
                alp[j]--;//�H j + 'a' (�r��)���Y

                //���l
                int num[N] = {};
                for (k = 0; k <= back; k++)
                    num[k] = k;

                //�B�z�ۦP�r���h��@��
                for (k = 0; k < 26; k++)
                {
                    for (int c = 2; c <= alp[k]; c++)//�n��������
                    {
                        int temp = c;
                        for (int n = 2; n <= back&&temp > 1; n++)//���l
                        {
                            //�����A�䭼�����
                            int g = gcd(temp, num[n]);
                            temp /= g;
                            num[n] /= g;
                        }
                    }
                }

                alp[j]++;//�k��

                //�p��H�C�Ӥp��str[i]���r�����������զX��
                LL result = 1;
                for (k = 2; k <= back; k++)
                    result *= num[k];
                ans += result;
            }

            alp[str[i] - 'a']--;//���r���w�Q�p�⧹��
        }

        printf("%10lld\n", ans + 1);
    }


    return 0;
}
int gcd(int a, int b)
{
    while (a)
    {
        int temp = a;
        a = b%a;
        b = temp;
    }

    return b;
}