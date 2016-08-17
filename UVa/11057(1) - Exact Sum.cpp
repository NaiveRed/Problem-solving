#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, price[10001];

    while (scanf("%d", &n) != EOF)
    {
        int money;
        for (int i = 0; i < n; i++)
            scanf("%d", &price[i]);
        scanf("%d", &money);

        sort(price, price + n);
        int mid = lower_bound(price, price + n, money / 2) - price;//�Ĥ@�Ӥj�󵥩� money/2 ��
        bool flag = true;

        //�q�����V�ⰼ�h��A����쪺�L�̬ۮt�@�w����p
        for (; flag&&price[mid] <= money; mid++)//�V�k
            for (int i = 1; i <= mid; i++)//�V��
                if (price[mid] + price[mid - i] == money)
                {
                    printf("Peter should buy books whose prices are %d and %d.\n\n", price[mid - i], price[mid]);
                    flag = false;
                    break;
                }
    }

    return 0;
}