#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char pre[27], in[27];
void buildTree(int in_start, int in_end, int pre_idx);
void post(int idx);
int main()
{
    while (scanf("%s%s", pre, in) != EOF)
    {
        int len = strlen(pre);
        buildTree(0, len, 0);
        putchar('\n');
    }

    return 0;
}
void buildTree(int in_start, int in_end, int pre_idx)
{
    if (in_start >= in_end)
        return;

    int pos = find(in + in_start, in + in_end, pre[pre_idx]) - in;//�ڸ`�I

    int lLen = pos - in_start;//���l���I���Ӽ�

    buildTree(in_start, in_start + lLen, pre_idx + 1);//���l��
    buildTree(pos + 1, in_end, pre_idx + lLen + 1);//�k�l��

    putchar(in[pos]);//��ǦL�X
}
