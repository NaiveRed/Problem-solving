/*
rbegin().base() => rbegin()-1 (逆向的) => end()
auto it = (urn.rbegin()).base();//成為正向的 iterator，位置為 end()
--it;//最後一個元素
it => end()-1 (last number)
*/
#include <cstdio>
#include <set>
using namespace std;

inline int read()
{
    int n = 0;
    char c;
    while ((c = getchar()) >= '0' && c <= '9')
        n = n * 10 + c - '0';
    return n;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        getchar();

        multiset<int> urn;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int k, bill;
            //scanf("%d", &k);
            k = read();
            for (int j = 0; j < k; ++j)
            {
                //scanf("%d", &bill);
                bill = read();
                urn.insert(bill);
            }

            multiset<int>::iterator low(urn.begin());
            multiset<int>::reverse_iterator high(urn.rbegin());//也可以使用 end()-1 即可
            sum += *high - *low;

            //printf("%d %d", *urn.rbegin(), *(++urn.rbegin()).base());
            urn.erase(low);
            urn.erase((++high).base());
        }

        printf("%lld\n", sum);
    }

    return 0;
}
