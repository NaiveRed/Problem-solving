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
            if (now >= tar)//已完成
                break;

            if (seg[i].l > now)//剩下區段的左端點已大於目前完成的了，會有空隙
            {
                ans = 0;
                break;
            }
            else 
            {
                //從剩下的段落找出符合 "左端點小於等於目前完成的" ，其中 最遠的右端點
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

                if (max <= now)//如果剩下區段的右端點，皆無法覆蓋超過現在完成的，就無法覆蓋全部區域
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