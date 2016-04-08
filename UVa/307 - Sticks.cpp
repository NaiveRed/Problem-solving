#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;

bool isUsed[N];
int sticks[N],n;
bool backtracking(int idx, int count, int now, int len);
int main()
{
    int i;
    while (scanf("%d", &n) && n)
    {
        int all = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &sticks[i]);
            all += sticks[i];
        }

        //�q�j���}�l���A��֦^������
        sort(sticks, sticks + n, [](const int& a, const int& b)->bool{return a > b; });
        fill(isUsed, isUsed + n, false);

        int len;
        //����Ҥl�����׳̤p���̪�������Ҥl�C
        for (len = sticks[0]; len <= all; len++)
        {
            if (all%len)//�@�w���`�����]�ơA�]�����㪺�Ҥl���׬ҬۦP
                continue;

            if (backtracking(0, 0, 0, len))
                break;
        }

        printf("%d\n", len);
    }

    return 0;
}
bool backtracking(int idx, int count, int now, int len)
{
    //�����@�ڧ��㪺�Ҥl
    if (now == len)
    {
        //�Ҧ����᪺�Ҥl���Χ��A�B���׹F�� len
        if (count == n)
            return true;
        now = 0;
    }

    if (!now)
    {
        //�n�զ�����Ҥl���Ĥ@�ڡA�����`���٨S���ե���Ҥl�A���׬� 0 (now)�C�ҥH�p�G�Ĥ@�ڱ��W���N����A���U�Ӥ]���|��A�]���Ĥ@�ڷ|�ѤU�ӡC
        for (idx = 0; isUsed[idx]; idx++);
        isUsed[idx] = true;
        if (backtracking(idx + 1, count+1, sticks[idx], len))
            return true;
        isUsed[idx] = false;
    }
    else
    {
        for (int i = idx; i < n; i++)
        {
            if (isUsed[i] || (i&&sticks[i] == sticks[i - 1] && !isUsed[i - 1]))//�@�˪����סA�B�S���Ψ쪺�A���ݭn�A��
                continue;

            if (now + sticks[i] <= len)
            {
                isUsed[i] = true;
                if (backtracking(i + 1, count+1, now + sticks[i], len))
                    return true;
                isUsed[i] = false;
                
                //�N�����פ��ޫ���\�A��ӳ��|���յL�k����
                if (now + sticks[i] == len)
                    return false;
            }
        }
    }

    return false;
}