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

    int pivot = num[start];//最左邊當基準

    int left = start + 1, right = end;
    while (left < right)
    {
        //左邊為小於 pivot 的
        while (num[left] < pivot && left < right)
            left++;

        //右邊為大於 pivot 的
        while (num[right] >= pivot && left < right)
            right--;

        swap(num[left], num[right]);
    }

    //剩下 num[left]
    if (pivot < num[left])
        /*
        pivot < num[left]，將 left - 1 ，把 num[left] 保持在右半部分，待會 num[left-1] 和 num[start] 交換後，left-1 左邊的都比 pivot 小。
        所以左半部分在排序時，不需要比較 pivot。
        而右半部分仍需比較 num[left] ，所以下面 left 會再加一。
        */
        left--;

    /*
    pivot >= num[left] ，交換位置後，left 的左邊全部小於等於 pivot，待會左半部排序時不需要比較 num[left] 了 。
    而右半部也都比 pivot 大，所以直接從 left+1 開始做。
    */

    swap(num[left], num[start]);

    //兩種情況， num[left] 都不需要再做比較了
    quick_sort(start, left - 1);//左半部分
    quick_sort(left + 1, end);//右半部分
}