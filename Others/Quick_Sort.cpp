#include<cstdio>

int num[50];
inline void swap(int& a, int& b);
void quick_sort(int start, int end);
int main()
{
    while (true)
    {
        for (int i = 0; i < 10; i++)
            scanf("%d", &num[i]);
        quick_sort(0, 9);

        for (int i = 0; i < 10; i++)
            printf("%d ", num[i]);
        putchar('\n');
    }

    return 0;
}
inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void quick_sort(int start, int end)//in-place
{
    if (start >= end)
        return;

    int pivot = num[start];//�̥������

    int left = start + 1, right = end;
    while (left < right)
    {
        //���䬰�p�� pivot ��
        while (num[left] < pivot && left < right)
            left++;

        //�k�䬰�j�� pivot ��
        while (num[right] >= pivot && left < right)
            right--;

        swap(num[left], num[right]);
    }

    //�ѤU num[left]
    if (pivot < num[left])
        /*
        pivot < num[left]�A�N left - 1 �A�� num[left] �O���b�k�b�����A�ݷ| num[left-1] �M num[start] �洫��Aleft-1 ���䪺���� pivot �p�C
        �ҥH���b�����b�ƧǮɡA���ݭn��� pivot�C
        �ӥk�b�������ݤ�� num[left] �A�ҥH�U�� left �|�A�[�@�C
        */
        left--;

    /*
    pivot >= num[left] �A�洫��m��Aleft ����������p�󵥩� pivot�A�ݷ|���b���ƧǮɤ��ݭn��� num[left] �F �C
    �ӥk�b���]���� pivot �j�A�ҥH�����q left+1 �}�l���C
    */

    swap(num[left], num[start]);

    //��ر��p�A num[left] �����ݭn�A������F
    quick_sort(start, left - 1);//���b����
    quick_sort(left + 1, end);//�k�b����
}