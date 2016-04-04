#include<cstdio>
#include<algorithm>
using namespace std;

int side_length;//�������
int stick[21];
bool used[21];
bool backtracking(int n, int len, int now, int idx);
int main()
{
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        int n, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &stick[i]);
            sum += stick[i];
        }
        //���ƧǴ�֦^������
        sort(stick, stick + n, [](const int& s1, const int& s2)->bool{return s1 > s2; });
        fill(used, used + n, false);
        side_length = sum / 4;//�������

        if (sum % 4 || stick[0] > side_length)
            puts("no");
        else
            puts(backtracking(n, 0, 0, 0) ? "yes" : "no");
    }

    return 0;
}
bool backtracking(int n, int len, int now, int idx)//(�Ҥl��,�ثe�s��������,���������,����������ڴҤl)
{
    //�����@��
    if (len == side_length)
    {
        len = idx = 0;
        now++;
        if (now == 3)
            return true;
    }

    for (int i = idx; i < n; i++)
    {
        if (!used[i])
        {
            if (len + stick[i] <= side_length)//�����ư����׶W�L��
            {
                used[i] = true;
                if (backtracking(n, len + stick[i], now, i + 1))
                    return true;

                used[i] = false;
            }
        }
    }

    return false;
}