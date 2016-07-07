#include<cstdio>
#define N 101

bool live[N];
inline int getNext(int now, int n);
int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) && n)
    {
        int start, i, pos;

        for (start = 1; start <= n; start++)
        {
            for (i = 0; i <= n; i++)
                live[i] = true;

            int now = start;
            bool flag = true;
            pos = 1;

            for (i = 1; i < n&&flag; i++)
            {
                int count = k;
                while (count)
                {
                    count--;
                    if (!count)
                    {
                        int temp = now;
                        
                        live[now] = false;

                        if (now == pos)//�NJosephus�����F
                        {
                            flag = false;
                            break;
                        }

                        //��H�h�I�A�ô��h�������l
                        for (int j = 0; j < k; j++)
                            temp = getNext(temp, n);

                        //�p�G�����ʨ�Josephus 
                        if (temp == pos)
                            pos = now;
                        
                        live[now] = true;
                        live[temp] = false;
                    }

                    now = getNext(now, n);
                }
            }

            //Josephus�٬���
            if (live[pos])
                break;
        }

        printf("%d\n", start);
    }

    return 0;
}
int getNext(int now, int n)
{
    do
    {
        now++;
        if (now > n)
            now = 1;
    } while (!live[now]);

    return now;
}