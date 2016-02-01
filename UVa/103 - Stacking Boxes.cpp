#include<cstdio>
#include<algorithm>
#define N 30

struct Box
{
    int D;
    int dim[10];
    int tag;

    bool operator >(const Box& b)
    {
        for (int i = 0; i < D; i++)
        {
            if (dim[i] <= b.dim[i])
                return false;
        }

        return true;
    }
};

bool comp(const Box& a, const Box& b);//for the std::sort
int LIS(Box box[], int n, int *lis);//O(n^2)
int main()
{
    int n, dim, temp[10], i;
    Box box[N];

    while (scanf("%d%d", &n, &dim) != EOF)
    {
        int lis[N] = {};
        for (int k = 0; k < n; k++)
        {
            box[k].D = dim;
            box[k].tag = k + 1;//��0�Ӳ��l�s���O1
            for (i = 0; i < dim; i++)
                scanf("%d", &box[k].dim[i]);

            //�N�U���ץѤp��j�Ƨ�
            std::sort(box[k].dim, box[k].dim + dim);

        }
        //�N�c�l�Ѥp�ƨ�j
        std::sort(box, box + n, comp);

        int len = LIS(box, n, lis);
        //output
        printf("%d\n", len);
        for (i = 0; i < len - 1; i++)
            printf("%d ", lis[i]);
        printf("%d\n", lis[i]);
    }

    return 0;
}
bool comp(const Box& a, const Box& b)
{
    int d = a.D;
    for (int i = 0; i < d; i++)
        if (a.dim[i] < b.dim[i])
            return true;
        else if (a.dim[i] > b.dim[i])
            return false;

    return false;
}
int LIS(Box box[], int n, int *lis)
{
    int length[N], i, prev[N] = {};
    //�u���ۤv�ɪ��׬� 1
    std::fill(length, length + n, 1);

    //��U��LIS������
    for (i = 0; i < n; i++)
    {
        //��b[i]�᭱��˨���
        for (int j = i + 1; j < n; j++)
            if (box[j] > box[i])
                if (length[i] + 1 > length[j])
                {
            length[j] = length[i] + 1;
            prev[j] = i;
                }
    }

    //�̪���LIS����
    int max = 0, last;
    for (i = 0; i < n; i++)
        if (max < length[i])
        {
        max = length[i];
        last = i;
        }

    //�D�XLIS
    for (i = max - 1; i >= 0; i--)
    {
        lis[i] = box[last].tag;
        last = prev[last];
    }

    return max;
}