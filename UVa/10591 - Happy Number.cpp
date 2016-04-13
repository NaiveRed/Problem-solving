#include<cstdio>
#include<unordered_set>
using namespace std;

int main()
{
    int Case;
    scanf("%d", &Case);

    unordered_set<int> s;
    for (int i = 1; i <= Case; i++)
    {
        s.clear();
        int n, m;
        bool flag = false;
        scanf("%d", &n);
        m = n;

        while (!s.count(n))//判斷是否已經出現過
        {
            if (n == 1)
            {
                flag = true;
                break;
            }
            s.insert(n);

            int sum = 0;
            //相加每位的平方
            while (n)
            {
                int temp = n % 10;
                sum += temp*temp;
                n /= 10;
            }
            n = sum;
        }

        printf("Case #%d: %d is ", i, m);
        if (flag)
            puts("a Happy number.");
        else
            puts("an Unhappy number.");
    }
    return 0;
}