#include<cstdio>
#include<algorithm>
#define N 100000
using namespace std;
struct Seg
{
    int l, r;
}seg[N];
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int tar, i = 0, l, r;
        scanf("%d", &tar);
        while (scanf("%d%d", &l, &r) && (l || r))
        {
            seg[i].l = l;
            seg[i].r = r;
            i++;
        }

        int count = i;
        sort(seg, seg + count, [](const Seg& a, const Seg& b)->bool
        {
            return a.l < b.l;
        });

        int now = 0, ans = 0, ans_idx[N];
        int max, idx;
        for (i = 0; i < count; ans++)
        {
            if (now >= tar)//�w����
                break;

            if (seg[i].l > now)//�ѤU�Ϭq�������I�w�j��ثe�������F�A�|���Ż�
            {
                ans = 0;
                break;
            }
            else 
            {
                //�q�ѤU���q����X�ŦX "�����I�p�󵥩�ثe������" �A�䤤 �̻����k���I
                max = seg[i].r;
                idx = i;
                while (i < count&&seg[i].l <= now)
                {
                    if (max < seg[i].r)
                    {
                        max = seg[i].r;
                        idx = i;
                    }

                    i++;
                }

                if (max <= now)//�p�G�ѤU�Ϭq���k���I�A�ҵL�k�л\�W�L�{�b�������A�N�L�k�л\�����ϰ�
                    break;

                now = seg[idx].r;
                ans_idx[ans] = idx;
            }
        }

        if (now >= tar)
        {
            printf("%d\n", ans);
            for (i = 0; i < ans; i++)
                printf("%d %d\n", seg[ans_idx[i]].l, seg[ans_idx[i]].r);
        }
        else
            puts("0");

        if (Case)
            putchar('\n');
    }

    return 0;
}