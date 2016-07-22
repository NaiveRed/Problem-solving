/*
http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html#3
*/
#include<cstdio>
#include<vector>
#define N 100000
using namespace std;

int num[N], lis[N];
int pos[N] = { 1 };//for LIS()

int findLowerBound(vector<int>&v, int n);//尋找下界，也就是第一個遇到 "大於等於 n" 的，也可以用 std::lower_bound
int LIS(int *seq, int size);//O(NlogL)
int main()
{

    int n = 0;
    char c;
    int temp = 0, neg = 1;

    //input
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            num[n++] = temp*neg;
            temp = 0;
            neg = 1;
        }
        else if (c == '-')
            neg = -1;
        else
            temp = temp * 10 + c - '0';
    }

    int max = LIS(num, n);

    printf("%d\n-\n", max);
    for (int i = 0; i < max; i++)
        printf("%d\n", lis[i]);

    return 0;
}
int LIS(int *seq, int size)
{
    vector<int> v = { seq[0] };//C++11

    int len = 1, i;
    for (i = 1; i < size; i++)
    {
        if (seq[i] > v.back())
        {
            v.push_back(seq[i]);
            pos[i] = ++len;
        }
        else
        {
            int temp = findLowerBound(v, seq[i]);
            v[temp] = seq[i];
            pos[i] = temp + 1;//位置從 1 開始，而findLowerBound回傳的是 v 的index(起始為0)，所以需加 1
        }
    }

    //找出LIS
    for (i = size - 1; i >= 0; i--)
        if (pos[i] == len)
            break;

    int temp = len;
    for (; i >= 0 && temp; i--)
        if (pos[i] == temp)
        {
        lis[temp - 1] = seq[i];
        temp--;
        }

    return len;
}
int findLowerBound(vector<int>&v, int n)
{
    //binary search
    int left = 0, right = v.size() - 1;
    int mid = (left + right) / 2;

    while (left < right)
    {
        if (v[mid] >= n)
            right = mid;
        else if (v[mid] < n)
            left = mid + 1;

        mid = (left + right) / 2;
    }

    return mid;
}