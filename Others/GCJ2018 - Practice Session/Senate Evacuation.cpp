#include <cstdio>
#include <queue>

struct part
{
    char name;
    int amount;
    bool operator<(const part &a) const
    {
        return amount < a.amount;
    }
} p[26];

std::priority_queue<part> PQ;
void evacuate() //move one persion
{
    part tmp = PQ.top();
    PQ.pop();
    putchar(tmp.name);

    if (--tmp.amount)
        PQ.push(tmp);
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int n, tot = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            p[i].name = 'A' + i;
            scanf("%d", &p[i].amount);
            tot += p[i].amount;
            PQ.push(p[i]);
        }

        printf("Case #%d:", t);
        //奇數的話要先走一個，避免最後剩下一人過半數的情況
        if (tot & 1)
        {
            putchar(' ');
            evacuate();
            --tot;
        }

        while (tot)
        {
            /*
            直接走兩個不會造成過半數
            總人數：10 -> 9 -> 8
            過半數： 5 -> 4 -> 4
            假設目前最多人的政黨為 5 人，走一個後變 4 人，不會過半數。
            接著剩餘政黨最多也有為 5 人的，再從最多人的政黨走一個也不會使任何政黨過半。
            */
            putchar(' ');
            evacuate(); //first person
            evacuate(); //second person
            tot -= 2;
        }
        putchar('\n');
    }

    return 0;
}